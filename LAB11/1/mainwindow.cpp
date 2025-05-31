#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QRegularExpression>
#include <QTreeWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_calc, &QPushButton::clicked, this, &MainWindow::on_pushButton_calc_clicked);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(ui->actionExit, &QAction::triggered, qApp, &QApplication::quit);

    // Налаштування колонок для QTreeWidget
    ui->treeWidget_fileContent->setColumnCount(2);
    QStringList headers;
    headers << "Коефіцієнт" << "Значення";
    ui->treeWidget_fileContent->setHeaderLabels(headers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_calc_clicked()
{
    double a = ui->doubleSpinBox_A->value();
    double b = ui->doubleSpinBox_B->value();

    if (a == 0.0) {
        QMessageBox::warning(this, "Помилка", "Коефіцієнт A не повинен дорівнювати 0!");
        return;
    }

    double x = -b / a;
    QString resultText = QString("Розв’язок: x = %1").arg(x);
    ui->label_result->setText(resultText);

    addToHistory(a, b, x);
}

void MainWindow::addToHistory(double a, double b, double result)
{
    QString entry = QString("A=%1, B=%2 → x=%3").arg(a).arg(b).arg(result);
    ui->listWidget_history->addItem(entry);
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Відкрити файл", "", "Text Files (*.txt);;All Files (*)");
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Помилка", "Не вдалося відкрити файл!");
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    ui->treeWidget_fileContent->clear();

    QStringList parts = content.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

    double a = 0, b = 0;
    bool aOk = false, bOk = false;

    for (int i = 0; i < parts.size(); ++i) {
        if (parts[i] == "A" && i + 1 < parts.size()) {
            a = parts[i + 1].toDouble(&aOk);
            QTreeWidgetItem *itemA = new QTreeWidgetItem();
            itemA->setText(0, "A");
            itemA->setText(1, QString::number(a));
            ui->treeWidget_fileContent->addTopLevelItem(itemA);
            i++;
        } else if (parts[i] == "B" && i + 1 < parts.size()) {
            b = parts[i + 1].toDouble(&bOk);
            QTreeWidgetItem *itemB = new QTreeWidgetItem();
            itemB->setText(0, "B");
            itemB->setText(1, QString::number(b));
            ui->treeWidget_fileContent->addTopLevelItem(itemB);
            i++;
        }
    }

    if (aOk && bOk) {
        ui->doubleSpinBox_A->setValue(a);
        ui->doubleSpinBox_B->setValue(b);
    } else {
        QMessageBox::warning(this, "Помилка", "Невірний формат файлу або відсутні коефіцієнти A і B.");
    }
}

void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Зберегти файл", "", "Text Files (*.txt);;All Files (*)");
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Помилка", "Не вдалося зберегти файл!");
        return;
    }

    QTextStream out(&file);
    out << "A " << ui->doubleSpinBox_A->value() << "\n";
    out << "B " << ui->doubleSpinBox_B->value() << "\n";
    out << ui->label_result->text() << "\n";

    for (int i = 0; i < ui->listWidget_history->count(); ++i) {
        out << ui->listWidget_history->item(i)->text() << "\n";
    }

    file.close();
}

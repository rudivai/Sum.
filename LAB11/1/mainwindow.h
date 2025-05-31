#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_calc_clicked();
    void openFile();
    void saveFile();

private:
    Ui::MainWindow *ui;
    void addToHistory(double a, double b, double result);
};

#endif // MAINWINDOW_H

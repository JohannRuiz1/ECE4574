#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "StringCoder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString processHW1(QString input);

private slots:
    void on_processButton_clicked();

    void on_otpButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<StringCoder*> coders;

};
#endif // MAINWINDOW_H

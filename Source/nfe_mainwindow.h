#ifndef NFE_MAINWINDOW_H
#define NFE_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class NFE_MainWindow;
}

class NFE_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NFE_MainWindow(QWidget *parent = 0);
    ~NFE_MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_action_5_triggered();

    void on_pushButton_2_clicked();

private:
    Ui::NFE_MainWindow *ui;
};

#endif // NFE_MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <player.h>
#include <tools.h>
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>
#include <QtWebEngineWidgets>
#include <testdialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //Display video frame in player UI
    void updatePlayerUI(QImage img);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_horizontalScrollBar_sliderReleased();

    void on_horizontalScrollBar_2_sliderReleased();

    void on_horizontalScrollBar_valueChanged(int value);

    void on_horizontalScrollBar_2_valueChanged(int value);

    void on_pushButton_5_clicked();

    void on_frameNumberScroll_sliderReleased();

    void on_frameNumberScroll_sliderMoved(int position);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_myTestButton_clicked();

private:
    Ui::MainWindow *ui;
    Player* myPlayer = 0;
    cv::Mat theImage;
    TestDialog* winAbout;
};

#endif // MAINWINDOW_H

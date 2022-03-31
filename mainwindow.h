#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_hole1_clicked();
    void on_hole2_clicked();
    void on_hole3_clicked();
    void on_hole4_clicked();
    void on_hole5_clicked();
    void on_hole6_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QThread* worker;

    void update_holes();
    void hole_clicked(int index);

    void play();

    bool digletts[6] {true, false, false, false, true, true};
    int score = 0;
    int health = 3;

    QLabel* holes[6];
};
#endif // MAINWINDOW_H

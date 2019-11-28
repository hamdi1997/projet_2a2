#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Station.h"
#include "ligne.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui
{ class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_ajouter_p_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_modifier_p_clicked();

    void on_pb_supprime_2_clicked();

private:
    Ui::MainWindow *ui;
    station tmp_station;
    ligne tmp_ligne;
};
#endif // MAINWINDOW_H

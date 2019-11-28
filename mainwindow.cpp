#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Station.h"
#include "ligne.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
     ui->tab_station->setModel(tmp_station.afficher());
   ui->tab_ligne->setModel(tmp_ligne.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int num_station=ui->lineEdit_num_station->text().toInt();
    QString type=ui->lineEdit_type->text();
    QString nom=ui->lineEdit_nom->text();
    int num_ligne=ui->lineEdit_num_ligne->text().toInt();
    station s(num_station,type,nom,num_ligne);
    bool test=s.ajouter();
    if (test) qDebug()<<"station ajoute";
}

void MainWindow::on_pb_supprimer_clicked()
{
    int num_station=ui->lineEdit_num_station_2->text().toInt();
    bool test=tmp_station.supprimer(num_station);
    if (test)
       ui->tab_station->setModel(tmp_station.afficher());
}



void MainWindow::on_pb_modifier_clicked()
{
    int num_station=ui->num_station_m->text().toInt();
    QString type=ui->type_m->text();
    QString nom=ui->nom_m->text();
    int num_ligne=ui->num_ligne_m->text().toInt();

    station e(num_station,type,nom,num_ligne);
    bool test=tmp_station.modifier(num_station);
    if (test) ui->tab_station->setModel(tmp_station.afficher());

}

void MainWindow::on_pb_ajouter_p_clicked()
{
    int num_ligne=ui->num->text().toInt();
    int depart=ui->depart->text().toInt();
    int arrive=ui->arrive->text().toInt();
    int num_bus=ui->num_bus->text().toInt();
    ligne l(num_ligne,depart,arrive,num_bus);
    bool test=l.ajouter();
    if (test) qDebug()<<"ligne ajoute";
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    int num_ligne=ui->sup->text().toInt();
    bool test=tmp_ligne.supprimer(num_ligne);
    if (test)
       ui->tab_ligne->setModel(tmp_ligne.afficher());
}

void MainWindow::on_pb_modifier_p_clicked()
{
    int num_ligne=ui->lineEdit_num_m->text().toInt();
    int depart=ui->lineEdit_depart_m->text().toInt();
    int arrive=ui->lineEdit_arrive_m->text().toInt();
    int num_bus=ui->lineEdit_num_bus_m->text().toInt();
    ligne l(num_ligne,depart,arrive,num_bus);
    bool test=tmp_ligne.modifier(num_ligne);
    if (test) ui->tab_ligne->setModel(tmp_ligne.afficher());
}



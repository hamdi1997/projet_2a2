#include "ligne.h"

ligne::ligne()
{
    num_ligne=0;
    depart=0;
    arrive=0;
    num_bus=0;

}

ligne::ligne(int n,int d,int a,int b)
{
    num_ligne=n;
    depart=d;
    arrive=a;
    num_bus=b;
}

int ligne::get_num_ligne()
{
    return num_ligne;
}

int ligne::get_depart()
{
    return depart;
}

int ligne::get_arrive()
{
    return arrive;
}

int ligne::get_num_bus()
{
    return num_bus;
}

bool ligne::ajouter()
{
    QSqlQuery query;
    QString num_ligne2=QString::number(num_ligne);
    QString depart2=QString::number(depart);
    QString arrive2=QString::number(arrive);
    QString num_bus2=QString::number(num_bus);
    query.prepare("INSERT INTO ligne (num_ligne,depart,arrive,num_bus)""VALUES(:num_ligne,:depart,:arrive,:num_bus");
    query.bindValue(":num_ligne",num_ligne2);
    query.bindValue(":depart",depart2);
    query.bindValue(":arrive",arrive2);
    query.bindValue(":num_bus",num_bus2);
    return query.exec();
}

QSqlQueryModel * ligne::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from ligne");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM_LIGNE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DEPART"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ARRIVE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NUM_BUS"));
    return model;
}

bool ligne::supprimer(int num_ligne)
{
    QSqlQuery query;
    QString num_ligne2=QString::number(num_ligne);
    query.prepare("DELETE FROM promotions WHERE NUM_LIGNE= :num_ligne");
    query.bindValue(":num_ligne",num_ligne);
    return query.exec();
}

bool ligne::modifier(int num_ligne)
{
    QSqlQuery query;
    query.prepare("UPDATE ligne SET depart= :depart WHERE num_ligne= :num_ligne AND SET arrive= :arrive WHERE num_ligne= :num_ligne AND SET num_bus= :num_bus WHERE num_ligne= :num_ligne");
    query.bindValue(":num_ligne",num_ligne);
    query.bindValue(":depart",depart);
    query.bindValue(":arrive",arrive);
    query.bindValue(":num_bus",num_bus);
    return query.exec();
}

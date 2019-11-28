#include "Station.h"

station::station()
{
    num_station=0;
    type="";
    nom="";
    num_ligne=0;

}

station::station(int s,QString t,QString n,int num)
{
    num_station=s;
    type=t;
    nom=n;
    num_ligne=num;

}

int station::get_num_station()
{
    return num_station;
}

QString station::get_type()
{
    return type;
}

QString station::get_nom()
{
    return nom;
}

int station::get_num_ligne()
{
    return num_ligne;
}


bool station::ajouter()
{
    QSqlQuery query;
    QString num_station2=QString::number(num_station);
    QString num_ligne2=QString::number(num_ligne);

    query.prepare("INSERT INTO station (num_station,type,nom,num_ligne)""VALUES(:num_station,:type,:nom,:num_ligne");
    query.bindValue(":num_station",num_station2);
    query.bindValue(":type",type);
    query.bindValue(":nom",nom);
    query.bindValue(":num_ligne",num_ligne2);

    return query.exec();
}

QSqlQueryModel * station::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from station");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM_STATION"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NUM_LIGNE"));

    return model;
}

bool station::supprimer(int num_station)
{
    QSqlQuery query;
    QString num_station2=QString::number(num_station);
    query.prepare("DELETE FROM station WHERE NUM_STATION= :num_station");
    query.bindValue(":num_station",num_station);
    return query.exec();
}

bool station::modifier(int num_station)
{
    QSqlQuery query;
    query.prepare("UPDATE station SET type= :type WHERE num_station= :num_station AND SET nom= :nom WHERE num_station= :num_station AND SET num_ligne= :num_ligne WHERE num_station= :num_station ");
    query.bindValue(":num_station",num_station);
    query.bindValue(":type",type);
    query.bindValue(":nom",nom);
    query.bindValue(":num_ligne",num_ligne);
    return query.exec();
}

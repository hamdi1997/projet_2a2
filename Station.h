#ifndef STATION_H
#define STATION_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QVariant>

class station
{
public:
    station();
    station(int,QString,QString,int);
    int get_num_station();
    QString get_type();
    QString get_nom();
    int get_num_ligne();

    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    int num_station;
    QString type;
    QString nom;
    int num_ligne;

};

#endif // STATION_H

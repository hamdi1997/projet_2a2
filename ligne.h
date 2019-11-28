#ifndef LIGNE_H
#define LIGNE_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QVariant>

class ligne
{
public:
    ligne();
    ligne(int,int,int,int);
    int get_num_ligne();
    int get_depart();
    int get_arrive();
    int get_num_bus();
    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    int num_ligne,depart,arrive,num_bus;
};

#endif // LIGNE_H



#include "connexion.h"
#include <QSqlError>
#include <QMessageBox>
Connexion::Connexion(){
                      }
bool Connexion::ouvrirConnexion()

{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("Projet_transport");
                           db.setUserName("hamdi2019");//inserer nom de l'utilisateur
                           db.setPassword("hamdi2019");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de paramètres"),
                        QObject::tr("connection failed.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
        //throw QString ("Erreur Paramétres"+db.lastError().text());
    }
    return  test;
}
void Connexion::fermerConnexion()
{db.close();}

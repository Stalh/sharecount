#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

/**
 * @brief createConnection créer la table utilisateur et vérifier que la connection est bien établie
 * @return vrai si table créée et bdd connectée
 */
static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to establish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }


    QSqlQuery query;
    //creation de la table utilisateur
    query.exec("CREATE table utilisateur("
               "id varchar(50), "
               "mail varchar(50) not null unique, "
               "mdp varchar(50) not null, "
               "nom varchar(50), "
               "prenom varchar(50), "
               "primary key (id));");

    return true;
}

#endif // CONNECTION_H

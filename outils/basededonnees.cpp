#include "basededonnees.h"

BaseDeDonnees::BaseDeDonnees()
{
     bdd = QSqlDatabase::addDatabase("QSQLITE");
     bdd.setDatabaseName("../sharecount/baseDeDonnees.db");

     //QString directory = QDir::currentPath();
     if(bdd.open()){
         QSqlQuery query(bdd);
         //si la table n'existe pas , on la crée, sinon on ne fait rien
         //table utilisateur avec identifiant, mail (unique), mdp, nom, prenom
         //La clé primaire de la table est l'identifiant de l'utilisateur
         if(!query.exec("CREATE TABLE IF NOT EXISTS utilisateur(id varchar(50), mail varchar(50) not null unique, mdp varchar(50) not null, nom varchar(50), prenom varchar(50), primary key (id));"))
         {
             qDebug()<< "table utilisateur erreur !";
         }

         //Création de la table gestionnaire de budget

         if(!query.exec("CREATE TABLE IF NOT EXISTS gestionnaire_de_budget(idGdb varchar(200), nomGdb varchar(50) not null, descriptionGdb varchar(200), idUtilisateur varchar(50) NOT NULL, primary key (idGdb));")){

             qDebug()<< "erreur creation table gdb" ;
         }

         //Création de la table de cagnotte

         if(!query.exec("CREATE TABLE IF NOT EXISTS cagnotte(idCagnotte varchar(200), nomCagnotte varchar(50) not null, descriptionCagnotte varchar(200), objectifCagnotte double(1000000) NOT NULL, montant double(100000) NOT NULL DEFAULT '0.00', idUtilisateur varchar(50) NOT NULL, primary key (idCagnotte));")){
             qDebug() << "erreur creation table cagnotte";
         }

         //Création de la table qui dira quel utilisateur participe à quel gdb

         if(!query.exec("CREATE TABLE IF NOT EXISTS participeAuGdb(idGdb varchar(200), idUtilisateur varchar(50), "
                        "primary key (idGdb , idUtilisateur), "
                        "CONSTRAINT fk_idUtilisateur FOREIGN KEY (idUtilisateur) REFERENCES utilisateur(id),"
                        "CONSTRAINT fk_idGdb FOREIGN KEY (idGdb) REFERENCES gestionnaire_de_budget(idGdb));")){

             qDebug()<< "erreur creation table participeAuGdb";

         }
        //Création de la table qui dira quel utilisateur participe à quelle cagnotte
         if(!query.exec("CREATE TABLE IF NOT EXISTS participeACagnotte(idCagnotte varchar(200), idUtilisateur varchar(50), "
                        "primary key (idCagnotte , idUtilisateur), "
                        "CONSTRAINT fk_idUtilisateur FOREIGN KEY (idUtilisateur) REFERENCES utilisateur(id),"
                        "CONSTRAINT fk_idCagnotte FOREIGN KEY (idCagnotte) REFERENCES cagnotte(idCagnotte));")){

             qDebug()<< "erreur creation table participeACagnotte";

         }

         if(!query.exec("CREATE TABLE IF NOT EXISTS depenseGdb(idDepense varchar(200), idUtilisateur varchar(50) not null, idGdb varchar(200) not null, nomDepenseGdb varchar(200) not null, montant double(1000000) NOT NULL,"
                        "primary key (idDepense),"
                        "CONSTRAINT fk_idUtilisateur FOREIGN KEY (idUtilisateur) REFERENCES utilisateur(id),"
                        "CONSTRAINT fk_idGdb FOREIGN KEY (idGdb) REFERENCES gestionnaire_de_budget(idGdb))")){

             qDebug()<< "erreur creation table depenseGdb";
         }

         if(!query.exec("CREATE TABLE IF NOT EXISTS contributionCagnotte(idContribution varchar(50), idUtilisateur varchar(50) not null, idCagnotte varchar(200) not null, montant double(1000000) NOT NULL, nbOk number(4) not null default 0 , demandeRetrait int NOT NULL,"
                        "primary key(idContribution), "
                        "CONSTRAINT fk_idUtilisateur FOREIGN KEY (idUtilisateur) REFERENCES utilisateur(id),"
                        "CONSTRAINT fk_idCagnotte FOREIGN KEY (idCagnotte) REFERENCES cagnotte(idCagnotte))")){

             qDebug()<< "erreur creation table contributionCagnotte";
         }

     }else{
         qDebug() <<"Erreur lors de l'ouverture de la base de données";
         return;
     }


}


// ********************* LES ENVOIS DE DONNÉES *********************


bool BaseDeDonnees::envoieDonneesInscription(QString id, QString mail, QString mdp){

    QSqlQuery query(bdd);
    //ajouter l'identifiant, le mail et le mdp  à la bdd
    //le nom et le prenom sont nuls pour l'instant
    QString requete = "INSERT INTO utilisateur(id,mail,mdp) values('"+ id+"', '"+ mail+"', '"+ mdp+"');";
    return query.exec(requete);
}

void BaseDeDonnees::envoieDonneesGdb(QString id, QString nom, QString description, QString idUtilisateur){

    QSqlQuery query(bdd);
    //ajouter l'identifiant, le mail et le mdp  à la bdd
    //le nom et le prenom sont nuls pour l'instant

    QString requete = "INSERT INTO gestionnaire_de_budget(idGdb, nomGdb, descriptionGdb, idUtilisateur) values('"+id +"', '"+ nom+"', '"+ description+"', '" +idUtilisateur+ "');";
    if(!query.exec(requete)){
        qDebug() << "Erreur ajout à la gdb :" << bdd.lastError().text();

    }
}

void BaseDeDonnees::envoieDonneesCagnotte(QString id, QString nom, QString description, QString objectif, QString idUtilisateur){
    QSqlQuery query(bdd);


    QString requete = "INSERT INTO cagnotte(idCagnotte, nomCagnotte, descriptionCagnotte, objectifCagnotte, idUtilisateur) values('" + id +"', '"+ nom+"', '"+ description+"', '" + objectif +"' , '" +idUtilisateur+ "');";
    if(!query.exec(requete)){
        qDebug() << "Erreur ajout à la cagnotte :" << bdd.lastError().text();
    }
}

bool BaseDeDonnees::envoieDonneesDepenses(QString idDep, QString idU , QString idGdb, QString nomDep, QString montant){
    bool executed= false;
    QSqlQuery query(bdd);
    QString requete= "INSERT INTO depenseGdb(idDepense, idUtilisateur, idGdb, nomDepenseGdb, montant) VALUES('"+idDep +"', '"+ idU+"', '"+ idGdb+"', '" +nomDep+ "', '"+ montant+"');";
    if(query.exec(requete)){
        executed = true;
    }
    return executed;
}

bool BaseDeDonnees::envoieDonneesContributions(QString id, QString idU , QString idCagnotte, QString montant,QString demandeRetrait){
    bool executed= false;
    QSqlQuery query(bdd);
    QString requete= "INSERT INTO contributionCagnotte(idContribution , idUtilisateur, idCagnotte, montant,demandeRetrait) VALUES('"+id+"', '"+ idU+"', '"+ idCagnotte+"','"+ montant+"','"+ demandeRetrait+"');";
    if(query.exec(requete)){
        executed = true;
    }
    return executed;
}

bool BaseDeDonnees::updateMontant(QString idCagnotte, QString montant){
    bool executed= false;
    QSqlQuery query(bdd);
    QString requete= "UPDATE cagnotte SET montant = '"+ montant +"' WHERE idCagnotte = '" + idCagnotte + "';";
    if(query.exec(requete)){
        executed = true;
    }
    return executed;
}

// ********************* LES AJOUTS *********************


void BaseDeDonnees::ajouterUtilisateurACagnotte(QString nom, QString nomUtilisateur){
    QSqlQuery query(bdd);
    QString requete = "INSERT INTO participeACagnotte(idCagnotte, idUtilisateur) values('"+nom+"', '"+nomUtilisateur+"');";
    if(!query.exec(requete)){
        qDebug()<< "Erreur ajout participant à cagnotte";
    }
}

void BaseDeDonnees::ajouterUtilisateurAuGdb(QString nom, QString nomUtilisateur){
    QSqlQuery query(bdd);
    QString requete = "INSERT INTO participeAuGdb(idGdb, idUtilisateur) values('"+nom+"', '"+nomUtilisateur+"');";
    if(!query.exec(requete)){
        qDebug()<< "Erreur ajout participant au gdb";
    }
}


// ********************* LES SUPPRESSIONS *********************


void BaseDeDonnees::supprimerGDB(QString id){
    QSqlQuery query(bdd);
    QString requete = "DELETE FROM gestionnaire_de_budget where idGdb= '" + id +"';";
    if(!query.exec(requete)){
        qDebug()<< "Erreur suppression gdb"<< bdd.lastError().text();;
    }
}

void BaseDeDonnees::supprimerGDBCascade(QString id){
    QSqlQuery query(bdd);
    QString requete = "DELETE FROM gestionnaire_de_budget where idUtilisateur= '" + id +"';";
    if(!query.exec(requete)){
        qDebug()<< "Erreur suppression gdb"<< bdd.lastError().text();;
    }
}

void BaseDeDonnees::supprimerCagnotteCascade(QString id){
    QSqlQuery query(bdd);
    QString requete = "DELETE FROM cagnotte where idUtilisateur= '" + id +"';";
    if(!query.exec(requete)){
        qDebug()<< "Erreur suppression gdb"<< bdd.lastError().text();;
    }
}

void BaseDeDonnees::supprimerParticipantGDBCascade(QString id){
    QSqlQuery query(bdd);
    QString requete = "DELETE FROM participeAuGdb where idUtilisateur= '" + id +"';";
    if(!query.exec(requete)){
        qDebug()<< "Erreur suppression gdb"<< bdd.lastError().text();;
    }
}

void BaseDeDonnees::supprimerParticipantCagnotteCascade(QString id){
    QSqlQuery query(bdd);
    QString requete = "DELETE FROM participeACagnotte where idUtilisateur= '" + id +"';";
    if(!query.exec(requete)){
        qDebug()<< "Erreur suppression gdb"<< bdd.lastError().text();;
    }
}

void BaseDeDonnees::supprimerUtilisateur(QString id){
    QSqlQuery query(bdd);
    QString requete = "DELETE FROM utilisateur where id= '" + id +"';";
    if(!query.exec(requete)){
        qDebug()<< "Erreur suppression utilisateur"<< bdd.lastError().text();;
    }
}

void BaseDeDonnees::supprimerParticipantGDB(QString id){
    QSqlQuery query(bdd);
    QString requete = "DELETE FROM participeAuGdb where idGdb= '" + id +"';";
    if(!query.exec(requete)){
        qDebug()<< "Erreur suppression participant gdb"<< bdd.lastError().text();;
    }
}

void BaseDeDonnees::supprimerCagnotte(QString id){
    QSqlQuery query(bdd);
    QString requete = "DELETE FROM cagnotte where idCagnotte= '" + id +"';";
    if(!query.exec(requete)){
        qDebug()<< "Erreur suppression cagnoote"<< bdd.lastError().text();;
    }
}

void BaseDeDonnees::supprimerParticipantCagnotte(QString id){
    QSqlQuery query(bdd);
    QString requete = "DELETE FROM participeACagnotte where idCagnotte= '" + id +"';";
        //qDebug() << requete;
    if(!query.exec(requete)){
        qDebug()<< "Erreur suppression particiant cagnotte"<< bdd.lastError().text();;
    }
}

void BaseDeDonnees::supprimerDepense(QString idDep){

    QSqlQuery query(bdd);
    QString requete = "DELETE FROM depenseGdb WHERE idDepense='"+idDep+"';";
    if(!query.exec(requete)){
        qDebug()<< "Erreur supprimer depense" ;
    }
}
// ********************* LES GETTERS *********************


QString BaseDeDonnees::obtenirIdGDB(QString titre){
    QSqlQuery query(bdd);
    QString requete = "SELECT idGdb FROM gestionnaire_de_budget where nomGdb= '" + titre +"';";
    QString res;
    if(!query.exec(requete)){
        qDebug()<< "Erreur obtention id gdb"<< bdd.lastError().text();;
    } else {
        if(query.exec(requete)){
            while (query.next()) {
                res = query.value(0).toString();
            }
        }
    }
    return res;
}

QString BaseDeDonnees::obtenirMontantDepense(QString nomDepense){
    QSqlQuery query(bdd);
    QString requete = "SELECT montant FROM depenseGdb where nomDepenseGdb= '" + nomDepense +"';";
    QString res;
    if(!query.exec(requete)){
        qDebug()<< "Erreur obtention id gdb"<< bdd.lastError().text();;
    } else {
        if(query.exec(requete)){
            while (query.next()) {
                res = query.value(0).toString();
            }
        }
    }
    return res;
}

QString BaseDeDonnees::getMailUtilisateur(std::string id){
       QSqlQuery query(bdd);
       std::string requete = "Select mail from utilisateur where id='" +id + "';";

       QString qstr = QString::fromStdString(requete);
       QString res = "";
       if(query.exec(qstr)){
           while (query.next()) {
               res = query.value(0).toString();
           }
       }
       return res;
}



double BaseDeDonnees::getObjectif(QString id){
    QSqlQuery query(bdd);
    float res = 0;
    QString requete = "SELECT objectifCagnotte FROM cagnotte WHERE idCagnotte= '"+id+"';";
    if(query.exec(requete)){
        while(query.next()){
            res =query.value(0).toFloat();
        }
    }else{
        qDebug()<< "Erreur requete";
    }
    return res;
}

double BaseDeDonnees::getMontant(QString id){
    QSqlQuery query(bdd);
    float res = 0;
    QString requete = "SELECT montant FROM cagnotte WHERE idCagnotte= '"+id+"';";
    if(query.exec(requete)){
        while(query.next()){
            res =query.value(0).toFloat();
        }
    }else{
        qDebug()<< "Erreur requete";
    }
    return res;
}



QSqlQueryModel* BaseDeDonnees::getDepensesUtilisateur(QString idUtilisateur, QString idGdb){
    QSqlQueryModel* modelSql = new QSqlQueryModel() ;
    QSqlQuery query(bdd);
    QString requete = "SELECT idDepense FROM depenseGdb WHERE idUtilisateur='"+ idUtilisateur+"' AND idGdb='"+ idGdb+"';";


    if(query.exec(requete)){
        modelSql->setQuery(query);

    }else{
        qDebug()<< "erreur" << bdd.lastError();
    }
    return modelSql;
}

double BaseDeDonnees::getContributionsUtilisateur(QString idUtilisateur, QString idCagnotte){
    double res = 0;
    QSqlQuery query(bdd);
    QString requete = "SELECT SUM(montant) FROM contributionCagnotte WHERE idUtilisateur='"+ idUtilisateur+"' AND idCagnotte='"+ idCagnotte+"';";

    if(query.exec(requete)){
        while(query.next()){
            res =query.value(0).toDouble();
        }
    }else{
        qDebug()<< "erreur" << bdd.lastError();
    }
    return res;
}
// ********************* LES BOOLEENS *********************


bool BaseDeDonnees::idGdbExist(QString id){
    QSqlQuery query(bdd);
    QString requete = "Select count(*) , idGdb FROM gestionnaire_de_budget where idGdb= '"+id+ "';";
    int count= 0;
    bool res = false;
    if(query.exec(requete)){
        while (query.next()) {
            count = query.value(0).toInt();
        }
        if(count ==1){
            res = true;
        }
    }
    return res;
}

bool BaseDeDonnees::idCagnotteExist(QString id){
    QSqlQuery query(bdd);
    QString requete = "Select count(*) , idCagnotte FROM cagnotte where idCagnotte= '"+id+ "';";
    int count= 0;
    bool res = false;
    if(query.exec(requete)){
        while (query.next()) {
            count = query.value(0).toInt();
        }
        if(count ==1){
            res = true;
        }
    }
    return res;
}

QString BaseDeDonnees::obtenirIdCagnotte(QString titre){
    QSqlQuery query(bdd);
    QString requete = "SELECT idCagnotte FROM cagnotte where nomCagnotte= '" + titre +"';";
    QString res;
    if(!query.exec(requete)){
        qDebug()<< "Erreur obtention id cagnotte"<< bdd.lastError().text();;
    } else {
        if(query.exec(requete)){
            while (query.next()) {
                res = query.value(0).toString();
            }
        }
    }
    qDebug() << "l'id:" << res;
    return res;
}


bool BaseDeDonnees::verificationUtilisateur(QString id, QString mdp){
    bool estDansLaBDD = false;
    QSqlQuery query(bdd);
    std::string requete = "Select count(*), id, mdp from utilisateur where id='" +id.toStdString()  + "' AND mdp= '" +  mdp.toStdString()+"';";

    QString qstr = QString::fromStdString(requete);
    if(query.exec(qstr)){
        int count = 0;
        while (query.next()) {
                count = query.value(0).toInt();

            }
        if(count == 1){
            estDansLaBDD = true;
        }
    }else{
        qDebug() << "Erreur requete select:" << bdd.lastError().text();

    }
    return estDansLaBDD;
}


QSqlQueryModel* BaseDeDonnees::getGdbUtilisateur(QString idUtilisateur){
    QSqlQueryModel* modelSql = new QSqlQueryModel() ;
    QSqlQuery query(bdd);
    QString requete = "SELECT gdb.nomGdb , gdb.descriptionGDB "
                      "FROM participeAuGdb p JOIN utilisateur u ON (u.id=p.idUtilisateur) "
                      "JOIN gestionnaire_de_budget gdb ON (gdb.idGdb=p.idGdb)  "
                      "WHERE u.id = '"+idUtilisateur +"';";
    if(query.exec(requete)){
        modelSql->setQuery(query);
    }
    return modelSql;
}

QSqlQueryModel* BaseDeDonnees::getCagnottesUtilisateur(QString idUtilisateur){
    QSqlQueryModel* modelSql = new QSqlQueryModel() ;
    QSqlQuery query(bdd);
    QString requete = "SELECT c.nomCagnotte , c.descriptionCagnotte "
                      "FROM participeACagnotte p JOIN utilisateur u ON (u.id=p.idUtilisateur) "
                      "JOIN cagnotte c ON (c.idCagnotte=p.idCagnotte)  "
                      "WHERE u.id = '"+idUtilisateur +"';";
    if(query.exec(requete)){
        modelSql->setQuery(query);
    }
    return modelSql;
}

QSqlTableModel* BaseDeDonnees::getGdbDepenses(QString idGdb){
   QSqlTableModel* modelSql= new QSqlTableModel();

   modelSql->setTable("depenseGdb");
   modelSql->select();
   modelSql->setFilter(QString("idGdb like '%%1%'").arg(idGdb));

   return modelSql;
}

QSqlTableModel* BaseDeDonnees::getGdbDepensesUtilisateur(QString idUtilisateur, QString idGdb){
    QSqlTableModel* modelSql= new QSqlTableModel();

    modelSql->setTable("depenseGdb");
    modelSql->select();
    //WHERE idGdb = (id en paramètre) and idUtilisateur = (id en paramètre)
    modelSql->setFilter(QString("idGdb like '%%1%' and idUtilisateur like '%%2%'").arg(idGdb,idUtilisateur));

    return modelSql;
}

bool BaseDeDonnees::isCreateurCompte(QString tableComptes, QString idCompte,QString idUti){
    QSqlQuery query(bdd);
    QString nomIdTable;
    //On vérifie si la table qu'on veut vérifier est cagnotte
    //Pour utiliser la même fonction entre cagnotte et gestionnaire
    if (QString::compare(tableComptes,"cagnotte",Qt::CaseInsensitive) == 0){
        nomIdTable = "idCagnotte";
    } else {
        nomIdTable = "idGdb";
    }
    QString requete = "Select idUtilisateur FROM "+tableComptes+" where "+nomIdTable+"= '"+idCompte+ "';";
    QString idCreateur;
    bool res = false;
    if(query.exec(requete)){
        while (query.next()) {
            idCreateur = query.value(0).toString();
        }
        //On vérifie si l'id passé en paramètre est celui de l'utilisateur
        if (QString::compare(idCreateur,idUti,Qt::CaseInsensitive) == 0){
            res = true;
        }
    } else{
        qDebug() << "Erreur requete vérification créateur: " << bdd.lastError().text();

    }
    return res;
}



//*****************  CHANGEMENT MAIL *****************

bool BaseDeDonnees::changerMail(QString id, QString mail){
    QSqlQuery query(bdd);
    QString requete = "UPDATE utilisateur SET mail='" + mail +"' WHERE id= '" + id +"';";
    return query.exec(requete);

}

//*****************  CHANGEMENT MDP *****************

bool BaseDeDonnees::changerMdp(QString id, QString mdp){
    QSqlQuery query(bdd);
    QString requete = "UPDATE utilisateur SET mdp='" + mdp +"' WHERE id= '" + id +"';";
    return query.exec(requete);
}

#ifndef FENETRE_H
#define FENETRE_H
#include <QWidget>

#include "model.h"

class Fenetre : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Fenetre Constructeur
     * @param bd Base de Données
     * @param gestFenetres gestionnaire de fenetres
     * @param parent widget
     */
    explicit Fenetre(BaseDeDonnees* bd, Model &model, QWidget *parent = nullptr);
    /**
     * @brief setTitre fonction globale (virtuelle) redéfinie dans fenetreGDB et fenetreConsulterMesDepenses
     * @param label titre du gestionnaire de budget
     */
    virtual void setTitre(const QString label);
signals:
protected:
    BaseDeDonnees* bd; /*!< Instance de la base de données >*/

    Model &model;

};

#endif // FENETRE_H

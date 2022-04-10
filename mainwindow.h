#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "affichage/fenetre.h"
#include "model.h"
/**
 * @file mainwindow.h
 * @brief Class générée automatiquement par QtCreator lors de la création du projet 
 * @author C. Mathias, R. Martini, G. Zimol
 * @version 1.0
 */

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /**
     * @brief setFenetre Modifie l'affichage à partir du widget passé en paramètre
     * @param widget Le widget à afficher
     */
    void setFenetre(QWidget* widget);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

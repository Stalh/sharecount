#include "mainwindow.h"
/**
 * @file mainwindow.cpp
 * @brief Class générée automatiquement par QtCreator lors de la création du projet 
 * @author C. Mathias, R. Martini, G. Zimol
 * @version 1.0
 */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Model* model = new Model(*this);

    std::map<std::string,Fenetre*>::const_iterator it;
    for(it = model->getFenetres().begin(); it != model->getFenetres().end();it++){
        ui->stackedWidget->addWidget((QWidget*)it->second);
    }
    ui->stackedWidget->setCurrentWidget(model->getFenetres().at("authentification"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setFenetre(QWidget* widget){
    ui->stackedWidget->setCurrentWidget(widget);
}

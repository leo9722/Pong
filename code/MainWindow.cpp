#include "MainWindow.h"
#include "MyScene.h"

MainWindow::MainWindow() : QMainWindow(){
    
    //widget dans lequel tout s'affiche
    widget_general = new QWidget;
    QHBoxLayout * qbl_general = new QHBoxLayout;
    widget_general->setLayout(qbl_general);
    this->setCentralWidget(widget_general);

    //exemple de création de zone ou mettre boutons
    qbl_general->addWidget(BuildGroupBoxControle());

    //exemple de création de menu
    menuFichier = menuBar() -> addMenu(tr("&Fichier"));

    //instanciation de l'objet 
    QGraphicsView * myview;
    QGraphicsScene * myscene = new MyScene(this);
    myview = new QGraphicsView(myscene, this);
    myscene -> setBackgroundBrush(Qt::black);
    qbl_general->addWidget(myview);
}

MainWindow::~MainWindow(){

}

QGroupBox * MainWindow::BuildGroupBoxControle(){
    QGroupBox * qgb = new QGroupBox(tr("Jeu PONG"));
    return qgb;
}

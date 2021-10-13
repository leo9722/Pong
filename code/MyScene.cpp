#include "MyScene.h"

MyScene::MyScene(QObject * parent) : QGraphicsScene(parent){


    int hauteur = 700;
    int largeur = 600;
    
    this->setSceneRect(0,0, largeur, hauteur);

    QGraphicsRectItem *terrain = new QGraphicsRectItem(0, 100, 600, 300);
    terrain->setPen(QPen(Qt::white, 3, Qt::DashLine));
    this->addItem(terrain);

    QGraphicsLineItem *filet = new QGraphicsLineItem(300, 103, 300, 397);
    filet->setPen(QPen(Qt::white, 3, Qt::DashLine));
    this->addItem(filet);


    qgpi = new QGraphicsPixmapItem(QPixmap("ball.png").scaled(QSize(10,10)));
    qgpi->setY(250);
    qgpi->setX(295);
    this->addItem(qgpi);

    player1 = new QGraphicsPixmapItem(QPixmap("barre-vertical.png").scaled(QSize(100,100)));
    //player1->setX(-100);
    player1->setY(200);
    this -> addItem(player1);

    player2 = new QGraphicsPixmapItem(QPixmap("barre-vertical.png").scaled(QSize(100,100)));
    player2->setX(+500);
    player2->setY(200);
    this -> addItem(player2);

    qgti = new QGraphicsTextItem();
    qgti->setX(270);
    // qgti->setY(-500);
    qgti->setPlainText("Pong");
    this->addItem(qgti);

    g = new QGraphicsTextItem();
    g->setY(400);
    g->setPlainText("GAME OF PONG  :\nPour jouer utiliser les touche  : I + J --> Palyer 1 et  Z + S --> player 2 \nTouche G : PLAY et pour RESTART quand partie termine");
    g->setDefaultTextColor(Qt::green);
    this->addItem(g);

    h = new QGraphicsTextItem();
    h->setY(440);
    h->setPlainText("\nTouche H : PAUSE");
    h->setDefaultTextColor(Qt::green);
    this->addItem(h);

    f1 = new QGraphicsTextItem();
    f1->setY(460);
    f1->setPlainText("\nTouche F1 : LEVEL 1 (EASY)");
    f1->setDefaultTextColor(Qt::green);
    this->addItem(f1);

    f2 = new QGraphicsTextItem();
    f2->setY(480);
    f2->setPlainText("\nTouche F2 : LEVEL 2 (NORMAL)");
    f2->setDefaultTextColor(Qt::green);
    this->addItem(f2);

    f3 = new QGraphicsTextItem();
    f3->setY(500);
    f3->setPlainText("\nTouche F3 : LEVEL 3 (HARDCORE)");
    f3->setDefaultTextColor(Qt::green);
    this->addItem(f3);

    QString txtsc1=QString::number(sc1);
    score1 = new QGraphicsTextItem(txtsc1);
    score1->setDefaultTextColor(Qt::white);
    score1->setX(80);
    score1->setY(60);
    this->addItem(score1);

    QString txtsc2=QString::number(sc2);
    score2 = new QGraphicsTextItem(txtsc2);
    score2->setDefaultTextColor(Qt::white);
    score2->setX(480);
    score2->setY(60);
    this->addItem(score2);
    
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    
}

void MyScene::update(){

        int x = qgpi->x();
        int y = qgpi->y();

    qgpi -> setX(x + sensx);
    qgpi -> setY(y + sensy);


    if(qgpi->collidesWithItem(player1)||qgpi->collidesWithItem(player2) || qgpi->x() == 0 || qgpi->x() == 590){
        sensx=-sensx;


    }else if(qgpi->y() == 100 || qgpi->y() == 390){
        sensy = -sensy;
    }

    if(qgpi->x() == 590){
        sc1+=1;
        score1->setPlainText(QString::number(sc1));
        qgpi->setPos(295,250);
        
    }else if(qgpi->x() == 0){
        sc2+=1;
        score2->setPlainText(QString::number(sc2));
        qgpi->setPos(295,250);
        
    }

    if(sc1 == 5){
        //timer->stop();
        timer->stop();
        win1 = new QGraphicsTextItem();
        win1->setPos(250, 50);
        win1->setDefaultTextColor(Qt::green);
        win1->setPlainText("Player1 WIN !!!!");
        this->addItem(win1);
    }else if(sc2 == 5){
        //timer->stop();
        timer->stop();
        win2 = new QGraphicsTextItem();
        win2->setPos(250,50);
        win2->setDefaultTextColor(Qt::green);
        win2->setPlainText("Player2 WIN !!!!!");
        this->addItem(win2);
    }
}

void MyScene::keyPressEvent(QKeyEvent *event){

    int y = player1->y();
    int y2 = player2->y();

    if(event->key() == Qt::Key_G && (sc1 != 5 && sc2 != 5)){

        timer->start(speed);
    }else if(event->key() == Qt::Key_H){
        timer->stop();

    }

    if(event->key() == Qt::Key_Z && player1->y() >= 100 ){
        //qDebug() << "Vers le haut";
        player1->setY(y-10);
    }else if(event->key() == Qt::Key_S && player1->y() <= 300){
        player1->setY(y+10);
    }

    else if(event->key() == Qt::Key_I && player2->y() >= 100){
        player2->setY(y2-10);
    }else if(event->key() == Qt::Key_J  && player2->y() <= 300){
        player2->setY(y2+10);
    }

    if(event->key() == Qt::Key_F2){
        speed = 7;
        timer->start(speed);
    }else if(event->key() == Qt::Key_F3){
        speed = 5;
        timer->start(speed);
    }else if(event->key() == Qt::Key_F1){
        speed =10;
        timer->start(speed);
    }

    if(sc1 == 5 && event->key() == Qt::Key_G){

        sc1=0;
        sc2=0;
        score1->setPlainText(QString::number(sc1));
        score2->setPlainText(QString::number(sc2));



        this->removeItem(win1);

        // this->addItem(score1);
        // this->addItem(score2);
    
        timer->start(speed);
    }else if(sc2 == 5 && event->key() == Qt::Key_G){
        sc1=0;
        sc2=0;
        score1->setPlainText(QString::number(sc1));
        score2->setPlainText(QString::number(sc2));

        this->removeItem(win2);

        timer->start(speed);
    }

    
}
#ifndef MYSCENE_H
#define MYSCENE_H
#include <QtWidgets>
#include <QTimer>

class MyScene : public QGraphicsScene{
    Q_OBJECT
    public:
        MyScene(QObject * parent = 0);
        void keyPressEvent(QKeyEvent* event);
        void paintEvent(QPaintEvent* painter) ;
        int sc1 = 0;
        int sc2 = 0;
       // void keyReleaseEvent(QKeyEvent* event);
    
    public slots : 
        void update();


    private: 
        QTimer *timer;
        QGraphicsPixmapItem * qgpi;
        QGraphicsPixmapItem * player1;
        QGraphicsPixmapItem * player2;
        QGraphicsTextItem * qgti;
        QGraphicsTextItem * score1;
        QGraphicsTextItem * score2;
        QGraphicsTextItem * win1;
        QGraphicsTextItem * win2;
        QGraphicsTextItem * g;
        QGraphicsTextItem * h;
        QGraphicsTextItem * f1;
        QGraphicsTextItem * f2;
        QGraphicsTextItem * f3;

        int sensy = 1;
        int sensx = 1;
        int speed = 10;



};

class MyWidget : public QWidget{
    public:
    MyWidget( QWidget *parent = 0 ) : QWidget( parent ) {}

    void paintEvent(QPaintEvent* e) 
    {
        QWidget::paintEvent(e); // effectue le comportement standard

        QPainter painter(this); // construire
         
        painter.setPen( QPen(Qt::white, 2) ); // personnaliser

        painter.drawRect( 190, 100, 410, 310 ); // dessiner

    } // détruire
};


#endif

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>

class MainWindow : public QMainWindow{
    Q_OBJECT
    public:
        MainWindow();
        ~MainWindow();
        QGroupBox * BuildGroupBoxControle();

    public slots:

    private : 
        QWidget * widget_general;
        QMenu * menuFichier;
};

#endif
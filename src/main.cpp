#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    a.setApplicationName("Hemisemi Video");
    a.setApplicationVersion("0.0 alpha");

    hsm::video::gui::MainWindow w;
    w.show();

    return a.exec();
}

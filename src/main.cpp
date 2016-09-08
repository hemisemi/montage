#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    a.setApplicationName("Hemisemi Montage");
    a.setApplicationVersion("0.0");

    hsm::video::gui::MainWindow w;
    w.show();

    return a.exec();
}

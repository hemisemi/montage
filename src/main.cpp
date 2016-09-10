#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>

#include <hsm/montage/montage.h>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    a.setApplicationName("Hemisemi Montage");
    a.setApplicationVersion("0.0");

	hsm::montage::init();

    hsm::montage::gui::MainWindow w;
    w.show();

    return a.exec();
}

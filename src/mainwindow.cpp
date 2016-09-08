#include "mainwindow.h"
#include "widgets/splitter.h"
#include "widgets/viewcontainer.h"

namespace hsm{
namespace video{
namespace gui{

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    _splitter = new Splitter;
    setCentralWidget(_splitter);
    _splitter->setOrientation(Qt::Vertical);
    _splitter->setHandleWidth(1);

    _splitter->addWidget(new ViewContainer);
    _splitter->addWidget(new ViewContainer);
}

MainWindow::~MainWindow(){
    //
}

}
}
}

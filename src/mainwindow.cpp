#include "mainwindow.h"
#include "widgets/splitter.h"
#include "widgets/viewcontainer.h"

#include "views/videostreamview.h"

namespace hsm{
namespace video{
namespace gui{

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    _splitter = new Splitter;
    setCentralWidget(_splitter);
    _splitter->setOrientation(Qt::Vertical);
    _splitter->setHandleWidth(1);

    _splitter->addWidget(new ViewContainer(new VideoStreamView));
    _splitter->addWidget(new ViewContainer);
}

MainWindow::~MainWindow(){
    //
}

}
}
}

#include "mainwindow.h"
#include "widgets/splitter.h"
#include "widgets/viewcontainer.h"

#include "views/videostreamview.h"

#include <hsm/montage/io/resource.h>

namespace hsm{
namespace montage{
namespace gui{

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    _splitter = new Splitter;
    setCentralWidget(_splitter);
    _splitter->setOrientation(Qt::Vertical);
    _splitter->setHandleWidth(1);

    _splitter->addWidget(new ViewContainer(new VideoStreamView));
    _splitter->addWidget(new ViewContainer);

	hsm::montage::resource vds;
	vds.load("/home/timothee/videos/Chaton/Les Alcôves final.mp4");
}

MainWindow::~MainWindow(){
    //
}

}
}
}

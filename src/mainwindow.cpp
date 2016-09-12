#include "mainwindow.h"
#include "widgets/splitter.h"
#include "widgets/viewcontainer.h"

#include "views/videostreamview.h"
#include "player/player.h"
#include "player/renderer/renderer.h"

#include <hsm/montage/config/settings.h>
#include <hsm/montage/montage.h>
#include <hsm/montage/io/resource.h>
#include <hsm/montage/video/video.h>
#include <hsm/montage/stream/source.h>

namespace hsm{
namespace montage{
namespace gui{

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    _splitter = new Splitter;
    setCentralWidget(_splitter);
    _splitter->setOrientation(Qt::Vertical);
    _splitter->setHandleWidth(1);

    VideoStreamView *sv = new VideoStreamView;

    _splitter->addWidget(new ViewContainer(sv));
    _splitter->addWidget(new ViewContainer);

    settings s;
    hsm::montage::init_settings(s);

    hsm::montage::io::resource vds(s);
    vds.load("/home/timothee/Téléchargements/Adventure Time Saison 6 VOSTFR/Adventure Time S06E01-02.mkv");
    //vds.load("/home/timothee/videos/Nouveau projet.ogv");
    //vds.load("/home/timothee/videos/RickAndMorty-Saison1/Rick.and.Morty.S01E02.Lawnmower Dog.avi");

    hsm::montage::video *source = nullptr;
    for(hsm::montage::source *src : vds.sources()){
        if(src->type() == hsm::montage::source::video){
            source = (hsm::montage::video*)src;
        }
    }

    if(source != nullptr){
        hsm::montage::video::parser *parser = source->new_parser();

        if(parser != nullptr)
            sv->player()->renderer()->setFrame(parser->read_frame());
    }
}

MainWindow::~MainWindow(){
    //
}

}
}
}

#include "mainwindow.h"
#include "widgets/splitter.h"
#include "widgets/viewcontainer.h"

#include "views/videostreamview.h"
#include "player/player.h"
#include "player/renderer/renderer.h"

#include <hsm/montage/settings.h>
#include <hsm/montage/montage.h>
#include <hsm/montage/io/resource.h>
#include <hsm/montage/video/source.h>
#include <hsm/montage/video/input.h>
#include <hsm/montage/source.h>
#include <hsm/montage/nodes/sequencer.h>
#include <hsm/montage/project.h>

#include <iostream>

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

	hsm::montage::project *proj = new hsm::montage::project;

	hsm::montage::io::resource *vds = new hsm::montage::io::resource(proj->root());
    //vds->load("/home/timothee/Téléchargements/Adventure Time Saison 6 VOSTFR/Adventure Time S06E01-02.mkv");
    //vds.load("/home/timothee/videos/Nouveau projet.ogv");
	//vds->load("/home/timothee/videos/RickAndMorty-Saison1/Rick.and.Morty.S01E02.Lawnmower Dog.avi");
	vds->load("/home/timothee/downloads/Adventure Time Saison 5 VOSTFR/Adventure Time S05E01-02.mkv");

    hsm::montage::video::source *source = nullptr;
    for(hsm::montage::source *src : vds->sources()){
        if(src->type() == hsm::montage::source::video){
            source = (hsm::montage::video::source*)src;
        }
    }

    if(source != nullptr){
        /*hsm::montage::video::source::parser *parser = source->new_parser();

        if(parser != nullptr){
            parser->seek(10.0);
            sv->player()->renderer()->setFrame(parser->read_frame());
        }*/

		hsm::montage::node::sequencer *sequencer = new hsm::montage::node::sequencer(proj->root());
		sequencer->input()->set_source(ref<montage::source>((montage::source*)source));

        sv->player()->setStream(sequencer->output());
        sv->player()->play();
    }
}

MainWindow::~MainWindow(){
    //
}

}
}
}

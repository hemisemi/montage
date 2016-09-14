#include "softwarerenderer.h"
#include <QPaintEvent>
#include <QPainter>

#include <hsm/montage/video/frame.h>

namespace hsm{
namespace montage{
namespace gui{

SoftwareRenderer::SoftwareRenderer(){
    _widget = nullptr;
}

SoftwareRenderer::~SoftwareRenderer(){
    //
}

QWidget *SoftwareRenderer::widget() const{
    if(_widget == nullptr){
        _widget = new Widget(*this);
    }
    return _widget;
}

void SoftwareRenderer::setFrame(const video::frame *frame){
    if(frame == nullptr || frame->planes().empty())
        return;
    hsm::bitmap *plane = frame->planes().front();
    _image = QImage(plane->data(), plane->width(), plane->height(), plane->stride(), QImage::Format_RGB888);

    if(_widget != nullptr)
        _widget->repaint();
}

const QImage & SoftwareRenderer::image() const{
    return _image;
}

SoftwareRenderer::Widget::Widget(const SoftwareRenderer & r) : _renderer(r){
    _painter = new QPainter;
}

SoftwareRenderer::Widget::~Widget(){
    delete _painter;
}

void SoftwareRenderer::Widget::paintEvent(QPaintEvent *){
    _painter->begin(this);

    _painter->drawImage(0, 0, _renderer.image());

    _painter->end();
}

}
}
}

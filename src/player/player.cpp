#include "player.h"
#include <hsm/montage/video/frame.h>
#include <hsm/montage/video/stream.h>
#include <QShowEvent>
#include <QResizeEvent>

#include "renderer/softwarerenderer.h"

namespace hsm{
namespace montage{
namespace gui{

Player::Player(QWidget *parent) : Player(new SoftwareRenderer, parent){
    //
}

Player::Player(Renderer *renderer, QWidget *parent) : QWidget(parent){
    _renderer = renderer;
    _widget = nullptr;
    _stream = nullptr;
    _fps = 25;
    _time = 0.0;
    _frame = nullptr;

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    connect(&_timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
}

Renderer *Player::renderer() const{
    return _renderer;
}

void Player::setStream(video::stream *s){
    _stream = s;
}

void Player::play(){
    refresh();

    _timer.setInterval(1000/_fps);
    _timer.start();
}

void Player::nextFrame(){
    _time += 1.0/_fps;

    refresh();
}

void Player::refresh(){
    if(_frame != nullptr)
        delete _frame;
    _frame = new video::frame(_time, 640, 480);
    _stream->draw(_frame);
    renderer()->setFrame(_frame);
}

void Player::showEvent(QShowEvent *){
    if(_widget == nullptr && _renderer != nullptr){
        _widget = _renderer->widget();
        _widget->setParent(this);
        _widget->setGeometry(rect());
        _widget->show();
    }
}

void Player::resizeEvent(QResizeEvent *e){
    if(_widget != nullptr)
        _widget->setGeometry(QRect(QPoint(), e->size()));
}

}
}
}

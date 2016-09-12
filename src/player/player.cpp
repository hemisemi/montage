#include "player.h"
#include <QShowEvent>
#include <QResizeEvent>

#include "renderer/softwarerenderer.h"

namespace hsm{
namespace montage{
namespace gui{

Player::Player(QWidget *parent) : QWidget(parent){
    _renderer = new SoftwareRenderer;
    _widget = nullptr;

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

Player::Player(Renderer *renderer, QWidget *parent) : QWidget(parent){
    _renderer = renderer;
    _widget = nullptr;

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

Renderer *Player::renderer() const{
    return _renderer;
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

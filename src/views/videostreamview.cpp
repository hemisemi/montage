#include "videostreamview.h"
#include <QPainter>
#include <QVBoxLayout>

#include "player/player.h"

namespace hsm{
namespace montage{
namespace gui{

VideoStreamView::VideoStreamView(QWidget *parent) : View(parent){
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(_player = new Player(this));
    layout->setMargin(0);
    layout->setSpacing(0);
}

Player *VideoStreamView::player() const{
    return _player;
}

void VideoStreamView::paintEvent(QPaintEvent *){
    QPainter painter(this);

    painter.fillRect(rect(), Qt::black);
}

}
}
}

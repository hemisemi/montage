#include "view.h"
#include <QPaintEvent>
#include <QPainter>

namespace hsm{
namespace video{
namespace gui{

View::View(QWidget *parent) : QWidget(parent){
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void View::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    painter.fillRect(event->rect(), palette().base());
}

}
}
}

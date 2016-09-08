#include "viewcontainertoolbar.h"
#include <QPaintEvent>
#include <QPainter>

namespace hsm{
namespace video{
namespace gui{

ViewContainerToolbar::ViewContainerToolbar(){
    setFixedHeight(25);
}

void ViewContainerToolbar::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.fillRect(event->rect(), palette().window());

    painter.setPen(palette().window().color().darker());
    painter.drawLine(0, 0, width(), 0);
    painter.setPen(palette().window().color().lighter());
    painter.drawLine(0, 1, width(), 1);
}

}
}
}

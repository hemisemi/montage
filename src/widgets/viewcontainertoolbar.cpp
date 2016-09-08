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
}

}
}
}

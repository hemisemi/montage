#include "defaultview.h"
#include <QPainter>
#include <QPaintEvent>

namespace hsm{
namespace montage{
namespace gui{

DefaultView::DefaultView(QWidget *parent) : View(parent){
    //
}

void DefaultView::paintEvent(QPaintEvent *e){
    QPainter painter(this);

    painter.fillRect(e->rect(), palette().window());
}

}
}
}

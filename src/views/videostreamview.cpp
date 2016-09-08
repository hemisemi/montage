#include "videostreamview.h"
#include <QPainter>

namespace hsm{
namespace montage{
namespace gui{

VideoStreamView::VideoStreamView(QWidget *parent) : View(parent){
    //
}

void VideoStreamView::paintEvent(QPaintEvent *){
    QPainter painter(this);

    painter.fillRect(rect(), Qt::black);
}

}
}
}

#include "splitter.h"
#include <QPaintEvent>
#include <QPainter>

namespace hsm{
namespace montage{
namespace gui{

Splitter::Splitter(){
    //
}

void Splitter::paintEvent(QPaintEvent *e){
    QPainter painter(this);

    painter.fillRect(e->rect(), palette().window().color().darker());
}

}
}
}

#pragma once

#include <QWidget>

namespace hsm{
namespace video{
namespace gui{

class ViewContainerToolbar : public QWidget{
public:
    ViewContainerToolbar();

protected:
    void paintEvent(QPaintEvent *event);
};

}
}
}

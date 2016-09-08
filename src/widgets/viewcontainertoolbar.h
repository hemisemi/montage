#pragma once

#include <QWidget>

namespace hsm{
namespace montage{
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

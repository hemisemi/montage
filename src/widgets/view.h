#pragma once

#include <QWidget>

namespace hsm{
namespace video{
namespace gui{

class View : public QWidget{
public:
    View();

protected:
    void paintEvent(QPaintEvent *event);
};

}
}
}

#pragma once

#include <QWidget>

namespace hsm{
namespace video{
namespace gui{

class View : public QWidget{
public:
    View(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
};

}
}
}

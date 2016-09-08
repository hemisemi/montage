#pragma once

#include "../widgets/view.h"

namespace hsm{
namespace video{
namespace gui{

class DefaultView : public View{
public:
    DefaultView(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *e);
};

}
}
}

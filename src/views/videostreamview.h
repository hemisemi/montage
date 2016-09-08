#pragma once

#include "../widgets/view.h"

namespace hsm{
namespace video{
namespace gui{

class VideoStreamView : public View{
public:
    VideoStreamView(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *e);

private:
    //
};

}
}
}

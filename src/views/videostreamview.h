#pragma once

#include "../widgets/view.h"

namespace hsm{
namespace montage{
namespace gui{

class Player;

class VideoStreamView : public View{
public:
    VideoStreamView(QWidget *parent = nullptr);

    Player *player() const;

protected:
    void paintEvent(QPaintEvent *e);

private:
    Player *_player;
};

}
}
}

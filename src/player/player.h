#pragma once

#include <QWidget>

namespace hsm{
namespace montage{
namespace gui{

class Renderer;

class Player : public QWidget{
public:
    Player(QWidget *parent = nullptr);
    Player(Renderer *renderer, QWidget *parent = nullptr);

    Renderer *renderer() const;

protected:
    void showEvent(QShowEvent *);
    void resizeEvent(QResizeEvent *);

private:
    Renderer *_renderer;
    QWidget *_widget;
};

}
}
}

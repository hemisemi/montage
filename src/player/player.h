#pragma once

#include <QWidget>
#include <QTimer>

namespace hsm{
namespace montage{

namespace video{

class stream;
class frame;

}

namespace gui{

class Renderer;

class Player : public QWidget{
    Q_OBJECT
public:
    Player(QWidget *parent = nullptr);
    Player(Renderer *renderer, QWidget *parent = nullptr);

    void setStream(video::stream *s);

    Renderer *renderer() const;

public slots:
    void play();
    void refresh();

protected:
    void showEvent(QShowEvent *);
    void resizeEvent(QResizeEvent *);

private slots:
    void nextFrame();

private:
    Renderer *_renderer;
    QWidget *_widget;

    video::stream *_stream;
    video::frame *_frame;

    QTimer _timer;
    quint8 _fps;
    double _time;
};

}
}
}

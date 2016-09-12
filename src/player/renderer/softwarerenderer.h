#include <QWidget>
#include <QPixmap>

#include "renderer.h"

class QPaintEvent;

namespace hsm{
namespace montage{
namespace gui{

class SoftwareRenderer : public Renderer{
public:
    SoftwareRenderer();
    ~SoftwareRenderer();

    class Widget : public QWidget{
    public:
        Widget(const SoftwareRenderer &);
        ~Widget();

    protected:
        void paintEvent(QPaintEvent *);

    private:
        const SoftwareRenderer & _renderer;
        QPainter *_painter;
    };

    QWidget *widget() const;

    void setFrame(const video_frame *frame);

    const QImage & image() const;

private:
    mutable Widget *_widget;
    QImage _image;

};

}
}
}

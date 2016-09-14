#include <QWidget>

namespace hsm{
namespace montage{

namespace video{

class frame;

}

namespace gui{

class Renderer{
public:
    Renderer();
    virtual ~Renderer() = 0;

    virtual void setFrame(const video::frame *frame) = 0;

    virtual QWidget *widget() const = 0;
};

}
}
}

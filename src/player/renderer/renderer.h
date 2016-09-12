#include <QWidget>

namespace hsm{
namespace montage{

class video_frame;

namespace gui{

class Renderer{
public:
    Renderer();
    virtual ~Renderer() = 0;

    virtual void setFrame(const video_frame *frame) = 0;

    virtual QWidget *widget() const = 0;
};

}
}
}

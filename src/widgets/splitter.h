#pragma once

#include <QSplitter>

namespace hsm{
namespace video{
namespace gui{

class Splitter : public QSplitter{
public:
    Splitter();

protected:
    void paintEvent(QPaintEvent *);

private:
    //
};

}
}
}

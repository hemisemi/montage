#pragma once

#include <QWidget>

class QVBoxLayout;

namespace hsm{
namespace video{
namespace gui{

class View;
class ViewContainerToolbar;

class ViewContainer : public QWidget{
public:
    ViewContainer(QWidget *parent = nullptr);

    View *getView() const;
    void setView(View *);

protected:
    void paintEvent(QPaintEvent *);

private:
    QVBoxLayout *_layout;
    ViewContainerToolbar *_bar;
    View *_view;
};

}
}
}

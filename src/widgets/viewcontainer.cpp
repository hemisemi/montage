#include "viewcontainer.h"
#include "viewcontainertoolbar.h"
#include "view.h"
#include "views/defaultview.h"
#include <QPainter>
#include <QVBoxLayout>

namespace hsm{
namespace montage{
namespace gui{

ViewContainer::ViewContainer(View *view, QWidget *parent) : QWidget(parent){
    _bar = new ViewContainerToolbar;
    _layout = new QVBoxLayout(this);
    _view = nullptr;
    _layout->addWidget(_bar);
    _layout->setMargin(0);
    _layout->setSpacing(0);

    setView(view);
}

View *ViewContainer::getView() const{
    return _view;
}

void ViewContainer::setView(View *v){
    if(v == nullptr)
        v = new DefaultView;
    if(_view != v){
        setUpdatesEnabled(false);
        if(_view != nullptr)
            _layout->removeWidget(_view);
        _view = v;
        if(_view)
            _layout->insertWidget(0, _view);
        setUpdatesEnabled(true);
    }
}

void ViewContainer::paintEvent(QPaintEvent *){
    QPainter painter(this);

    painter.fillRect(rect(), palette().base());
}

}
}
}

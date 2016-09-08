#include "viewcontainer.h"
#include "viewcontainertoolbar.h"
#include "view.h"
#include <QPainter>
#include <QVBoxLayout>

namespace hsm{
namespace video{
namespace gui{

ViewContainer::ViewContainer(QWidget *parent) : QWidget(parent){
    _bar = new ViewContainerToolbar;
    _layout = new QVBoxLayout(this);
    _layout->addStretch();
    _layout->addWidget(_bar);
    _layout->setMargin(0);
    _layout->setSpacing(0);
}

View *ViewContainer::getView() const{
    return _view;
}

void ViewContainer::setView(View *v){
    if(_view != v){
        setUpdatesEnabled(false);
        if(_view != nullptr)
            _layout->removeWidget(_view);
        _view = v;
        if(_view)
            _layout->insertWidget(1, _view);
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

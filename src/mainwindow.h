#pragma once

#include <QMainWindow>

namespace hsm{
namespace montage{
namespace gui{

class Splitter;

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Splitter *_splitter;
};

}
}
}

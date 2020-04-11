#pragma once

#include <QWidget>
#include <QPainter>
#include "World.h"
#include "Camera.h"

namespace Ui {
class GameForm;
}

class GameForm : public QWidget
{
    Q_OBJECT

public:
    explicit GameForm(QWidget *parent = nullptr);
    ~GameForm();

protected:
    virtual void timerEvent(QTimerEvent *pe);
    virtual void keyPressEvent(QKeyEvent *pe);
    virtual void paintEvent(QPaintEvent *pe);

private:
    Ui::GameForm *ui;
    World m_world;
    Camera m_camera;

    void redraw(QPainter &painter);

};

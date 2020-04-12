#include <QDebug>
#include <QKeyEvent>
#include "Object.h"
#include "GameForm.h"
#include "ui_GameForm.h"

GameForm::GameForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameForm),
    m_camera(m_world)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);

    m_world.add(new Object({{0, 0}, {600, 0}, {600, 10}, {0, 10}}));
    m_world.add(new Object({{0, 0}, {0, 600}, {10, 600}, {10, 0}}));
    m_world.add(new Object({{0, 600}, {600, 600}, {600, 590}, {0, 590}}));
    m_world.add(new Object({{590, 0}, {600, 0}, {600, 600}, {590, 600}}));
    m_world.add(&m_camera);

    startTimer(200);

}

GameForm::~GameForm()
{
    delete ui;
}

void GameForm::timerEvent(QTimerEvent *pe)
{
    Q_UNUSED(pe)
    repaint();
}

void GameForm::keyPressEvent(QKeyEvent *pe)
{
    switch (pe->key()) {
    case Qt::Key_Left:
        m_camera.turnLeft();
        break;
    case Qt::Key_A:
        m_camera.moveLeft();
        break;
    case Qt::Key_Right:
        m_camera.turnRight();
        break;
    case Qt::Key_D:
        m_camera.moveRight();
        break;
    case Qt::Key_Up:
    case Qt::Key_W:
        m_camera.moveForward();
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        m_camera.moveBack();
        break;
    default:
        QWidget::keyPressEvent(pe);
        break;
    }
}

void GameForm::paintEvent(QPaintEvent *pe)
{
    Q_UNUSED(pe)
    QPainter painter(this);
    redraw(painter);
}

void GameForm::redraw(QPainter &painter)
{
//    qDebug() << __FILE__ << __FUNCTION__;
    QRect viewport = painter.viewport();
    QBrush brush(Qt::black);
    painter.setBrush(brush);
    QRect background(viewport.left(), viewport.top(), viewport.width() - 1, viewport.height() - 1);
    painter.drawRect(background);

    m_world.draw(painter);
}

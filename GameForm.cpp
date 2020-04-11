#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include "GameForm.h"
#include "ui_GameForm.h"

GameForm::GameForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameForm)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);

}

GameForm::~GameForm()
{
    delete ui;
}

void GameForm::timerEvent(QTimerEvent *pe)
{

}

void GameForm::keyPressEvent(QKeyEvent *pe)
{
    switch (pe->key()) {
    case Qt::Key_Left:
    case Qt::Key_A:
        qDebug() << "Left";
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        qDebug() << "Right";
        break;
    case Qt::Key_Up:
    case Qt::Key_W:
        qDebug() << "Up";
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        qDebug() << "Down";
        break;
    default:
        QWidget::keyPressEvent(pe);
        break;
    }
}

void GameForm::paintEvent(QPaintEvent *pe)
{
    QPainter painter(this);
    QRect viewport = painter.viewport();
    QRect background(viewport.left(), viewport.top(), viewport.width() - 1, viewport.height() - 1);
    painter.drawRect(background);

}

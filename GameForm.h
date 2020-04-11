#pragma once

#include <QWidget>

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
};

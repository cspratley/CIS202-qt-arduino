#include "ball_animation.h"
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QDateTime>

int xMod = 1;
int yMod = 1;
int mv_x;
int mv_y;


BallAnimation::BallAnimation(QWidget *parent) :
    QWidget(parent),
    m_origin(QPoint(11,11))

{
    setFixedSize(100,100);
}

void BallAnimation::setOrigin(const QPoint &origin)
{
    m_origin = origin;
}

void BallAnimation::addToOrigin(const QPoint &point)
{
    m_origin += point;
 qDebug() << "Point x:"<< m_origin.x() <<"Point y:"<<  m_origin.y();

}
/*
void BallAnimation::collisionDetect()
{
if(this->mv_x >= m_origin.x() && m_origin.x() >= this->width() * -11)
   this->mv_x *= -1;
if (this->mv_y >= m_origin.y() && m_origin.y() >= this->height() * -11)
    this->mv_y *= -1;
}
*/

void BallAnimation::collisionDetect()
{

    if(m_origin.x() == 90 || m_origin.x() == 10 || m_origin.y() == 90
            || m_origin.y() == 10)
    {
        xMod *= -1;
        yMod *= -1;
    }
}


  int BallAnimation::ranGen()
 {
            int max = 4;
            qsrand(QDateTime::currentMSecsSinceEpoch()%5000);
           int rand = qrand();
            rand %= max;
            return (rand + 5);
 }

void BallAnimation::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(QRect(0,0,width()-1,height()-1));
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::red);
    painter.drawEllipse(m_origin,10,10);
}

void BallAnimation::setMove(int mv_x, int mv_y)
{
    collisionDetect();
    addToOrigin(QPoint((mv_x * xMod), (mv_y * yMod)));
}

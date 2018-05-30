#ifndef BALLANIMATION_H
#define BALLANIMATION_H

#include <QWidget>

class BallAnimation : public QWidget
{
    Q_OBJECT
public:
    explicit BallAnimation(QWidget *parent = nullptr);
    void setOrigin(const QPoint &origin);
    void addToOrigin(const QPoint &origin);
    void setMove(int mv_x, int mv_y);
    void collisionDetect();
    int ranGen();



signals:

public slots:
    void paintEvent(QPaintEvent* event);
private:
    QPoint m_origin;

};

#endif // BALLANIMATION_H

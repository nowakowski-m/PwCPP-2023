#include "my_widget.h"

#include <QPainter>

MyWidget::MyWidget(QWidget* parent)  //
    : QWidget(parent), timer(this)
{
    timer.start(timer_interval);
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void MyWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    painter.setBrush(QBrush(QColor(Qt::GlobalColor::magenta)));
    painter.translate(rect().width() / 2.0, rect().height() / 2.0);
    auto side = std::min(rect().width(), rect().height());
    painter.scale(side / 300.0, side / 300.0);
    painter.setPen(Qt::NoPen);

    for (int i = 0; i < num_disks; i++)
    {
        if (i != hidden)
        {
            QRadialGradient gradient(-20, 50, 40, -20, 50);
            gradient.setColorAt(0, QColor(255, 0, 255, 255));
            gradient.setColorAt(1, QColor(255, 0, 255, 0));
            gradient.setSpread(QGradient::PadSpread);
            painter.setBrush(gradient);
            painter.drawEllipse(-20, 60, 20, 20);
        }
        painter.rotate(360.0 / num_disks);
    }

    painter.setBrush(QBrush(QColor(Qt::GlobalColor::black)));
    painter.drawRect(-0.5, -6, 1, 12);
    painter.drawRect(-6, -0.5, 12, 1);
}

void MyWidget::on_timer()
{
    hidden = (hidden + 1) % num_disks;
    update();
}

void MyWidget::toggle_animation()
{
    if (timer.isActive())
        timer.stop();
    else
        timer.start(timer_interval);
}

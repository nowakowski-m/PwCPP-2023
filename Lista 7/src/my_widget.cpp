#include "my_widget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>

MyWidget::MyWidget(QWidget* parent) : QWidget(parent)
{
    this -> setFocusPolicy(Qt::StrongFocus);
}

///
/// \brief MyWidget::paintEvent obsługuje zdarzenia systemowe "odrysuj zawartość tego widżetu/okienka"
/// \param event - nieużywany
///

void MyWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    auto r = this->rect();
    painter.drawRect(r);

    for (const auto& circ : circles)
    {
        QPointF point(circ.center.x() * r.width(), circ.center.y() * r.height());
        painter.setBrush(QBrush(currentColor));
        painter.drawEllipse(point, circ.radius, circ.radius);
    }
}

///
/// \brief MyWidget::mousePressEvent obsługuje zdarzenia systemowe wygenerowane przyciśnięciem (któregokolwiek) klawisza myszy
/// \param event - parametry zdarzenia (np. położenie kursora myszy w momencie kliknięcia)
///
void MyWidget::mousePressEvent(QMouseEvent* event)
{
    auto pos = event->localPos();           // współrzędne położenia myszy we współrzędnmch obszaru roboczego bieżącego okna
    auto rec = rect();                      // prostokąt obszaru roboczego bieżącego okna
    Circle c;                               // kolejne kółko
    c.radius = DEFAULT_RADIUS;              // w tej wersji programu wszystkie kółka mają ten sam promień
    c.center.setX(pos.x() / rec.width());   // składowa "x" środka kółka
    c.center.setY(pos.y() / rec.height());  // składowa "y" środka kółka
    circles.push_back(c);                   // dodanie kółka na koniec wektora `circles`
    repaint();                              // wymuszamy odświeżenie okna bieżącego oboiektu (pośrednio uruchomi MyWidget::paintEvent)
}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Z) {
        if (event->modifiers() == Qt::ControlModifier) {
            if (!circles.empty()) {
                circles.pop_back();
                repaint();
            }
        }
    }
}

//po podwójnym naciśnięciu zmienia kolor wszystkich kulek na losowy

void MyWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        int r = qrand() % 256;
        int g = qrand() % 256;
        int b = qrand() % 256;
        currentColor = QColor(r, g, b);
        repaint();
    }
}


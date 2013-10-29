#include "WidgetAnimation.hpp"
#include <SFML/Graphics.hpp>


using namespace std;

WidgetAnimation::WidgetAnimation(QWidget *parent, uint fps) :
    QSFWidget(parent, fps)
{
}

WidgetAnimation::~WidgetAnimation()
{
}

void WidgetAnimation::onUpdate(uint i)
{
    QSFWidget::onUpdate(i);
}

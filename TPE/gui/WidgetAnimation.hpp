#ifndef GUI_WIDGETANIMATION_HPP
#define GUI_WIDGETANIMATION_HPP

#include <QSFWidget.hpp>

class WidgetAnimation : public QSFWidget
{
    Q_OBJECT

    public:
        WidgetAnimation(QWidget *parent = 0, uint fps = 0);
        virtual ~WidgetAnimation();

        virtual void onUpdate(uint nextTick) override;
};

#endif // GUI_WIDGETANIMATION_HPP

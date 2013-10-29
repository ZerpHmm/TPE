#ifndef QSIZEDTABLEWIDGET_HPP
#define QSIZEDTABLEWIDGET_HPP

#include <QTableWidget>

class QSizedTableWidget : public QTableWidget
{
    Q_OBJECT

    public:
        explicit QSizedTableWidget(QWidget *parent);
        explicit QSizedTableWidget(int rows, int columns, QWidget *parent);
        virtual ~QSizedTableWidget();

    protected:
        virtual void resizeEvent(QResizeEvent *event) override;
};

#endif // QSIZEDTABLEWIDGET_HPP

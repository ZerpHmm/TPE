#include "QSizedTableWidget.hpp"
#include <QResizeEvent>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QHeaderView>

QSizedTableWidget::QSizedTableWidget(QWidget *parent) :
    QTableWidget(parent)
{
}

QSizedTableWidget::QSizedTableWidget(int rows, int columns, QWidget *parent) :
    QTableWidget(rows, columns, parent)
{
}

QSizedTableWidget::~QSizedTableWidget()
{
}

void QSizedTableWidget::resizeEvent(QResizeEvent *e)
{
    /*
    this->setCellWidget(0, 0, new QSpinBox());
    this->setCellWidget(0, 1, new QDoubleSpinBox());

    this->setCellWidget(1, 0, new QSpinBox());
    this->setCellWidget(1, 1, new QDoubleSpinBox());

    if(this->columnCount() != 0)
    {
        const int newWidth = e->size().width() / this->columnCount();

        for(int i = 0 ; i < this->columnCount() ; ++i)
        {
            setColumnWidth(i, newWidth);
        }
    }

    horizontalHeaderItem(0)->setText("ojio");*/
}

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPluginLoader;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void slot_btn_static();
    void slot_btn_shared();

private:
    void addQtPlugin();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

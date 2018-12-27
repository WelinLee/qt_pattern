#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QBoxLayout>

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
    void slot_btn_load();
    void slot_btn_unload();

private:
    Ui::Widget *ui;
    QWidget *m_widget = nullptr;
    QVBoxLayout *m_vLayout = nullptr;
    QPluginLoader *m_plugin = nullptr;
};

#endif // WIDGET_H

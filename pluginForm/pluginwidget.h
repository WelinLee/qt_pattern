#ifndef PLUGINWIDGET_H
#define PLUGINWIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class PluginWidget;
}

class PluginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PluginWidget(QWidget *parent = 0);
    ~PluginWidget();

private slots:
    void slot_timer();

private:
    Ui::PluginWidget *ui;
    QTimer *m_timer;
};

#endif // PLUGINWIDGET_H

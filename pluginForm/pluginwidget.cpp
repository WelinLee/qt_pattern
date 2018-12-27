#include "pluginwidget.h"
#include "ui_pluginwidget.h"
#include <QDateTime>

PluginWidget::PluginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PluginWidget)
{
    ui->setupUi(this);

    m_timer = new QTimer;
    QObject::connect(m_timer, &QTimer::timeout, this, &PluginWidget::slot_timer);
    m_timer->start(1000);
}

PluginWidget::~PluginWidget()
{
    if(m_timer->isActive())
    {
        m_timer->stop();
        delete m_timer;
    }
    delete ui;
}

void PluginWidget::slot_timer()
{
    QString str_time = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    ui->lineEdit->setText(str_time);
}

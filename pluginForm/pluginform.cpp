#include "pluginform.h"
#include <QCryptographicHash>
#include "pluginwidget.h"

PluginForm::PluginForm()
{
    m_widget = new QWidget;
    PluginWidget *widget = new PluginWidget;
    m_widget = widget;
}

PluginForm::~PluginForm()
{
    if(m_widget)
    {
        delete m_widget;
        m_widget = nullptr;
    }
}

QWidget *PluginForm::PluginUi()
{
    return m_widget;
}

QString PluginForm::getSerialNumber()
{
    QByteArray sBytes = QString("PluginForm").toUtf8();
    QByteArray sMd5 = QCryptographicHash::hash(sBytes, QCryptographicHash::Md5).toHex();
    return QString(sMd5);
}

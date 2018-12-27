#include "pluginform.h"
#include <QCryptographicHash>
#include "pluginwidget.h"

PluginForm::PluginForm()
{

}

PluginForm::~PluginForm()
{

}

QWidget *PluginForm::PluginUi(QWidget *parent)
{
    if(nullptr == parent)
        return nullptr;

    PluginWidget *widget = new PluginWidget(parent);
    return widget;
}

QString PluginForm::getSerialNumber()
{
    QByteArray sBytes = QString("PluginForm").toUtf8();
    QByteArray sMd5 = QCryptographicHash::hash(sBytes, QCryptographicHash::Md5).toHex();
    return QString(sMd5);
}

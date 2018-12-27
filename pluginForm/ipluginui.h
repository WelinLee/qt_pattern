#ifndef IPLUGINUI_H
#define IPLUGINUI_H

#include <QtPlugin>
#include <QString>
#include <QWidget>

class IPluginUi
{
public:
    virtual ~IPluginUi() { }
    virtual QWidget *PluginUi(QWidget *parent) = 0;
    virtual QString getSerialNumber() = 0;
};

#define PluginID   "org.qt-project.Qt.Examples.plugin.IPluginUi"
Q_DECLARE_INTERFACE(IPluginUi, PluginID)

#endif // IPLUGINUI_H

#ifndef PLUGINFORM_H
#define PLUGINFORM_H

#include <QObject>
#include <QWidget>
#include "ipluginui.h"

class PluginForm : public QObject , public IPluginUi
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PluginID FILE "pluginForm.json")
    Q_INTERFACES(IPluginUi)

public:
    PluginForm();
    virtual ~PluginForm();

public:
    virtual QWidget *PluginUi() override;
    virtual QString getSerialNumber() override;

private:
    QWidget *m_widget;
};

#endif // PLUGINFORM_H

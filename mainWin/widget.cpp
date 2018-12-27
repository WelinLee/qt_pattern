#include "widget.h"
#include "ui_widget.h"
#include <QTime>
#include <QPluginLoader>
#include <QDir>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "../pluginForm/ipluginui.h"
#include "staticlib.h"
#include "sharedlib.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton_static, &QPushButton::clicked, this, &Widget::slot_btn_static);
    QObject::connect(ui->pushButton_shared, &QPushButton::clicked, this, &Widget::slot_btn_shared);
    QObject::connect(ui->pushButton_load, &QPushButton::clicked, this, &Widget::slot_btn_load);
    QObject::connect(ui->pushButton_unload, &QPushButton::clicked, this, &Widget::slot_btn_unload);

    m_vLayout = new QVBoxLayout;
    ui->tab_2->setLayout(m_vLayout);
}

Widget::~Widget()
{
    if(m_plugin && m_plugin->isLoaded())
    {
        m_vLayout->removeWidget(m_widget);
        delete m_widget;
        m_widget = nullptr;

        if(m_plugin->unload())
        {
            delete m_plugin;
            m_plugin = nullptr;
        }
    }

    delete ui;
}

void Widget::slot_btn_static()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    double w = qrand() * 1.0/(RAND_MAX/100.0);
    double h = qrand() * 1.0/(RAND_MAX/100.0);
    StaticLib lib;
    double ret = lib.calculateArea(w,h);
    ui->lineEdit_static->setText(QString::number(ret));
}

void Widget::slot_btn_shared()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int x = qrand()%1000;
    int y = qrand()%1000;
    SharedLib lib;
    int ret = lib.add(x, y);
    ui->lineEdit_shared->setText(QString::number(ret));
}

void Widget::slot_btn_load()
{
    if(m_plugin && m_plugin->isLoaded())
        return;

    QDir pluginDir(qApp->applicationDirPath());
    if(pluginDir.dirName().toLower() == tr("debug") || pluginDir.dirName().toLower() == tr("release") )
        pluginDir.cd("plugins");

    QStringList filters;
    filters << "*.dll" << "*.so";
    pluginDir.setNameFilters(filters);
    foreach (QString filename, pluginDir.entryList(QDir::Files))
    {
        m_plugin = new QPluginLoader(pluginDir.absoluteFilePath(filename));
        m_plugin->setLoadHints(QLibrary::ExportExternalSymbolsHint | QLibrary::ResolveAllSymbolsHint);
        if(m_plugin->load())
        {
            QObject *obj = m_plugin->instance();
            IPluginUi *plugin = qobject_cast<IPluginUi*>(obj);
            if(plugin)
            {
                m_widget = plugin->PluginUi(ui->tab_2);
                m_vLayout->addWidget(m_widget);
                QString str_sn = plugin->getSerialNumber();
                ui->textEdit->append("SN: " + str_sn);

                QString class_name = m_plugin->metaData().value("className").toString();
                ui->textEdit->append("export class: " + class_name);
                QJsonObject json = m_plugin->metaData().value("MetaData").toObject();
                QString str_author = json.value("author").toString();
                ui->textEdit->append("author: " + str_author);
                QString str_date = json.value("date").toString();
                ui->textEdit->append("date: " + str_date);
                QString str_license = json.value("license").toString();
                ui->textEdit->append("license: " + str_license);
                QString str_version = json.value("version").toString();
                ui->textEdit->append("version: " + str_version);
                QJsonArray array = json.value("changelog").toArray();
                ui->textEdit->append("changelog: ");
                for(int i = 0; i < array.size(); i++)
                    ui->textEdit->append(array.at(i).toString());
            }
        }
    }
}

void Widget::slot_btn_unload()
{
    if(m_plugin && m_plugin->isLoaded())
    {
        m_vLayout->removeWidget(m_widget);
        delete m_widget;
        m_widget = nullptr;
        ui->textEdit->clear();

        if(m_plugin->unload())
        {
            delete m_plugin;
            m_plugin = nullptr;
        }
    }
}


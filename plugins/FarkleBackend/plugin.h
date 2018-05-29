#ifndef FARKLEBACKENDPLUGIN_H
#define FARKLEBACKENDPLUGIN_H

#include <QQmlExtensionPlugin>

class FarkleBackendPlugin : public QQmlExtensionPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif

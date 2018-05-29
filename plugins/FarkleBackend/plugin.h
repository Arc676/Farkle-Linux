#ifndef FARKLEBACKENDPLUGIN_H
#define FARKLEBACKENDPLUGIN_H

#include <QQmlExtensionPlugin>
#include "farklebackend.h"

class FarkleBackendPlugin : public QQmlExtensionPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    static FarkleBackend* backend;

    void registerTypes(const char *uri);
};

#endif

#include <QtQml>
#include <QtQml/QQmlContext>

#include "plugin.h"
#include "farklebackend.h"

void FarkleBackendPlugin::registerTypes(const char *uri) {
    //@uri FarkleBackend
    qmlRegisterSingletonType<FarkleBackend>(uri, 1, 0, "FarkleBackend", [](QQmlEngine*, QJSEngine*) -> QObject* { return new FarkleBackend; });
}

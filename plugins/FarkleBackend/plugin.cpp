#include <QtQml>
#include <QtQml/QQmlContext>

#include "plugin.h"

FarkleBackend* FarkleBackendPlugin::backend = nullptr;

void FarkleBackendPlugin::registerTypes(const char *uri) {
    // create instance members
    if (!FarkleBackendPlugin::backend) {
	FarkleBackendPlugin::backend = new FarkleBackend();
    }

    //@uri FarkleBackend
    qmlRegisterSingletonType<FarkleBackend>(uri, 1, 0, "FarkleBackend", [](QQmlEngine*, QJSEngine*) -> QObject* { return FarkleBackendPlugin::backend; });
}

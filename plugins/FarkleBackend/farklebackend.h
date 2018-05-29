#ifndef FARKLEBACKEND_H
#define FARKLEBACKEND_H

#include <QObject>

#include "libfarkle.h"

class FarkleBackend: public QObject {
    Q_OBJECT

public:
    FarkleBackend();
    ~FarkleBackend() = default;

    Q_INVOKABLE void speak();
};

#endif

#ifndef FARKLEBACKEND_H
#define FARKLEBACKEND_H

#include <QObject>

#include "libfarkle.h"

class FarkleBackend: public QObject {
    Q_OBJECT

public:
    Q_INVOKABLE void newRoll();
    Q_INVOKABLE void confirmSelection();
    Q_INVOKABLE void bankPoints();
};

#endif

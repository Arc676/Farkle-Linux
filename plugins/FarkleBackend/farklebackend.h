#ifndef FARKLEBACKEND_H
#define FARKLEBACKEND_H

#include <QObject>

class FarkleBackend: public QObject {
    Q_OBJECT

public:
    FarkleBackend();
    ~FarkleBackend() = default;

    Q_INVOKABLE void speak();
};

#endif

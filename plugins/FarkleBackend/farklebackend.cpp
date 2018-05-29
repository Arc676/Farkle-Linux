#include <QDebug>

#include "farklebackend.h"

FarkleBackend::FarkleBackend() {

}

void FarkleBackend::speak() {
    qDebug() << "hello world!";
}

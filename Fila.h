#ifndef FILA_H
#define FILA_H
#include <stdexcept>
#include <iostream>
#include <list>

#include "Datagrama.h"


using namespace std;


class Fila {

private:
    int tamanho;
    int quantidade;
    list<Datagrama*>* datagramas;

public:
    Fila(int tamanho);
    virtual ~Fila();

    virtual void enqueue(Datagrama* d);
    virtual Datagrama* dequeue();
    virtual bool isEmpty();

    virtual void imprimir();
};

#endif // FILA_H

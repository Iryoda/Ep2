#ifndef REDE_H
#define REDE_H

#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>

#include "No.h"
#include "Hospedeiro.h"

#include <vector>

using namespace std;

class Rede
{
    public:
        Rede();
        virtual ~Rede();
        virtual void adicionar(No* no);

        virtual No* getNo(int endereco);
        virtual list<Hospedeiro*>* getHospedeiros();
        virtual void passarTempo();
        virtual void imprimir();

    protected:
        vector<No*>* nos;
        list<Hospedeiro*>* hospedeiros;
};

#endif // REDE_H

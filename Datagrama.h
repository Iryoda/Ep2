#ifndef DATAGRAMA_H
#define DATAGRAMA_H

#include <string>
#include "Segmento.h"

using namespace std;

class Datagrama
{
    private:
        int origem;
        int destino;
        int ttl;
        Segmento* dado;

    public:
        //Contructors
        Datagrama(int origem, int destino, int ttl, Segmento* dado);
        //Destructor
        virtual ~Datagrama();

        //Getters
        virtual int getOrigem();
        virtual int getDestino();
        virtual int getTtl();
        virtual Segmento* getDado();

        //Functions
        virtual void processar();
        virtual bool ativo();
        virtual void imprimir();

        };

#endif // DATAGRAMA_H

#include "Datagrama.h"
#include <iostream>

Datagrama::Datagrama(int origem, int destino, int ttl, Segmento* dado)
{
    this-> origem = origem;
    this-> destino = destino;
    this-> ttl = ttl;
    this-> dado = dado;
}

Datagrama::~Datagrama()
{
    delete dado;
    cout << "Datagrama destruído" << endl;
}
int Datagrama::getOrigem()
{
    return origem;
}

int Datagrama::getDestino()
{
    return destino;
}

int Datagrama::getTtl()
{
    return ttl;
}

Segmento* Datagrama::getDado()
{
    return dado;
}

void Datagrama::processar()
{
    ttl = ttl - 1;
}

bool Datagrama::ativo()
{
    if(ttl > 0) return true;
    else return false;
}

void Datagrama::imprimir()
{
    cout << "Origem: " << getOrigem() << " Destino " << getDestino() <<" TTl = " << getTtl()<< " Ativo: " <<  ativo() << endl;
}

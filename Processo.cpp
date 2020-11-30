#include "Processo.h"

int Processo::padrao = 5;

Processo::Processo(int endereco, int porta, Roteador* gateway):
    endereco(endereco), porta(porta)
{
    this->gateway = gateway;
}

int Processo::getEndereco()
{
    return endereco;
}

int Processo::getPorta()
{
    return porta;
}

int Processo::getTtlPadrao()
{
    return padrao;
}

void Processo::setTtlPadrao(int padrao)
{
    Processo::padrao = padrao;
}


void Processo::imprimir()
{

}

Processo::~Processo()
{

}

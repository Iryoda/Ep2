#include "Segmento.h"

Segmento::Segmento(int portaDeOrigem, int portaDeDestino, string dado) {
    this->portaDeOrigem = portaDeOrigem;
    this->portaDeDestino = portaDeDestino;
    this->dado = dado;
}

Segmento::~Segmento() {
}

int Segmento::getPortaDeOrigem() {
    return this->portaDeOrigem;
}

int Segmento::getPortaDeDestino() {
    return this->portaDeDestino;
}
string Segmento::getDado() {
    return this-> dado;
}

void Segmento::imprimir() {
    cout << "dado: " << dado << endl;
    cout << "porta de destino: " << portaDeDestino << endl;
    cout << "porta de origem: " << portaDeOrigem << endl;
}

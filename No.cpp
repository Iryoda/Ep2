#include "No.h"

No::No(int endereco) {
    this->endereco = endereco;
    fila = new Fila(TAMANHO_FILA);
}

No::~No() {
    delete fila;
}

Fila* No::getFila() {
    return fila;
}

int No::getEndereco() {
    return endereco;
}

void No::receber(Datagrama *d) {
    try {
        fila->enqueue(d);
    } catch (overflow_error *e) {
        cout << "\tFila em " << endereco << " estourou" << endl;
        delete e;
    }
}

void No::imprimir() {
    cout << "endereco: " << endereco << endl;
}

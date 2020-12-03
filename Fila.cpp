#include "Fila.h"

using namespace std;


Fila::Fila(int tamanho){
    datagramas = new list<Datagrama*>();
    this->tamanho = tamanho;
    this->quantidade = 0;
}

Fila::~Fila() {
    delete []datagramas;
}

void Fila::enqueue(Datagrama* d){
    if(quantidade < tamanho) {
        datagramas->push_back(d);
        quantidade++;
    }
    else
        throw new overflow_error("erro");
}

bool Fila::isEmpty(){
    if(datagramas->empty()) {
        return true;
    }
    else
        return false;
}

Datagrama* Fila::dequeue(){
    Datagrama *d;

    if(isEmpty()){
        throw new underflow_error("erro");
    }
    d = datagramas->front();
    datagramas->pop_front();
    quantidade--;
    return d;
}

void Fila::imprimir(){
    cout << "quantidade: " <<  quantidade << endl;
}

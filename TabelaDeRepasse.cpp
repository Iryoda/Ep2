#include "TabelaDeRepasse.h"

TabelaDeRepasse::TabelaDeRepasse()
{
    setPadrao(NULL);

    this->enderecos = new int[MAXIMO_TABELA];
    this->noAdjacentes = new No*[MAXIMO_TABELA];

    for ( int i = 0; i < MAXIMO_TABELA; i++){
        enderecos[i] = NULL;
        noAdjacentes[i] = padrao;
    }
}
void TabelaDeRepasse::mapear(int endereco, No* adjacente)
{
    int i = 0;
    while ( i < MAXIMO_TABELA && enderecos[i] != NULL){ //Percorre o vetor analisando os dados
        if( endereco == enderecos[i]){ //Caso o endereço já exista no vetor troca o valor do No
            noAdjacentes[i] = adjacente;
            return;
        }
        i++;

    }
    if( i == MAXIMO_TABELA ){ //Caso ele percorra todo o tamanho do vetor define como Cheio
        throw new overflow_error("Tabela Cheia");
        return;
    } else{
        enderecos[i] = endereco;
        noAdjacentes[i] = adjacente;
        return;
    }

}

No** TabelaDeRepasse::getAdjacentes()
{
    return noAdjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes()
{
    int i = 0;
    while ( i < MAXIMO_TABELA && noAdjacentes[i] != NULL){
        i++;
    }
    return i;
}

void TabelaDeRepasse::setPadrao(No* padrao)
{
    this->padrao = padrao;
}

No* TabelaDeRepasse::getDestino(int endereco)
{
    for ( int i = 0; i < MAXIMO_TABELA; i++){
        if(enderecos[i] == endereco){
            return noAdjacentes[i];
        }
    }
    return padrao;

}

void TabelaDeRepasse::imprimir()
{
    cout << "Padrao: " << this->padrao << endl;
    cout << "Quantidade: " << getQuantidadeDeAdjacentes() << endl;
    cout << "Adjacentes: " << getAdjacentes() << endl;
 }

 TabelaDeRepasse::~TabelaDeRepasse(){
    delete[] enderecos;
    delete[] noAdjacentes;
 }

#include "Rede.h"

Rede::Rede()
{
    hospedeiros = new list<Hospedeiro*>();
    nos = new vector<No*>();
}

Rede::~Rede(){
    delete nos;
    delete hospedeiros;
}

void Rede::adicionar(No* no)
{
    //Checa se o vetor está vazio
    if( nos->empty()){
        nos->push_back(no);
    }
    else{
        for (int i = 1; i < nos->size(); i++)
            if( no->getEndereco() == (*nos)[i]->getEndereco())
            {
                throw new logic_error("Já existe um no' com o mesmo endereco");
            }
        nos->push_back(no);
        }
}


No* Rede::getNo(int endereco)
{
    //Checa se o vetor está vazio
    if(nos->empty()) return NULL;

    for( unsigned int i = 0; i < nos->size(); i++)
    {
        if((*nos)[i]->getEndereco() == endereco)
        {
            return (*nos)[i];
        }
    }
    return NULL;
}

list<Hospedeiro*>* Rede::getHospedeiros()
{
    if( hospedeiros->empty())
    {
        for(unsigned int i = 0; i < nos->size(); i++){

        Hospedeiro* h1 = dynamic_cast<Hospedeiro*>((*nos)[i]);

        if( h1 != NULL){
            hospedeiros->push_back(h1);
            }
        }
    }
    return hospedeiros;
}
void Rede::passarTempo()
{
    for(unsigned int i = 0; i < nos->size(); i++)
    {
        Roteador* r1 = dynamic_cast<Roteador*>((*nos)[i]);

        if( r1 != NULL){
           r1->processar();
        } else {
            Hospedeiro* h1 = dynamic_cast<Hospedeiro*>((*nos)[i]);
            if( h1 != NULL){
                h1->processar();
            }
        }

        //(*nos)[i]->passarTempo();
    }
}

void Rede::imprimir()
{
    for(unsigned  int i = 0; i < nos->size(); i++)
    {
        cout << (*nos)[i]->getEndereco() << endl;
    }
}

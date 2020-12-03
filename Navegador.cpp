#include "Navegador.h"

Navegador::Navegador(int endereco, int porta, Roteador* gateway):
    Processo(endereco, porta, gateway)
{
}

Navegador::~Navegador()
{
    //dtor
}

void Navegador::abrir(int endereco, int porta)
{

    //Cria um segmento e um datagrama
    Segmento* s1 = new Segmento(this-> porta, porta, "GET");
    Datagrama*d1 = new Datagrama(this->endereco, endereco, padrao, s1);

    //Joga o datagrama no roteador
    gateway->receber(d1);

    //Define o conteudo para uma string vazia
    //E coloca o Navagador em espera
    conteudo = "";
    emEspera = true;

}

void Navegador::abrir(int endereco)
{
    //Cria um segmento e um datagrama
    Segmento* s1 = new Segmento(this-> porta, 80, "GET");
    Datagrama*d1 = new Datagrama(this->endereco, endereco, padrao, s1);
    //Joga o datagrama no roteador
    gateway->receber(d1);

    //Define o conteudo para uma string vazia
    //E coloca o Navagador em espera
    conteudo = "";
    emEspera = true;

}

string Navegador::getConteudo()
{
    return conteudo;
}


void Navegador::receber(int origem,  Segmento* mensagem)
{
    int portaOrigem = mensagem->getPortaDeOrigem();
    if(emEspera){
        conteudo = mensagem->getDado();
        //Mensagem
        cout << "Hospedeiro: " << endereco << endl;
        cout << "Navegador " << porta << endl <<
        "\tRecebido de " <<origem << ":" << portaOrigem <<
        " " << getConteudo() << endl;
    } else {
        cout << "Hospedeiro: " << endereco << endl;
        cout << "Navegador " << porta << endl <<
        "\tMensagem ignorada " <<origem << ":"<< portaOrigem <<
        " " << getConteudo() << endl;
    }
}

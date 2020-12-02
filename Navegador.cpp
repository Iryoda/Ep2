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
    int origem = gateway->getEndereco();

    //Cria um segmento e um datagrama
    Segmento* s1 = new Segmento(this-> porta, porta, "GET");
    Datagrama*d1 = new Datagrama(origem, endereco, padrao, s1);

    //Joga o datagrama no roteador
    gateway->receber(d1);

    //Define o conteudo para uma string vazia
    //E coloca o Navagador em espera
    conteudo = "";
    emEspera = true;

}

void Navegador::abrir(int endereco)
{
    int origem = gateway->getEndereco();

    //Cria um segmento e um datagrama
    Segmento* s1 = new Segmento(this-> porta, 80, "GET");
    Datagrama*d1 = new Datagrama(origem, endereco, padrao, s1);

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
    if(emEspera){
        conteudo = mensagem->getDado();
        //Mensagem
        cout << "Navegador " << porta << endl <<
        "\tRecebido de " <<origem << ":" << origem <<
        " " << getConteudo() << endl;
    } else {
        cout << "Navegador " << porta << endl <<
        "\tMensagem ignorada " <<origem << ":"<< origem <<
        " " << getConteudo() << endl;
    }
}

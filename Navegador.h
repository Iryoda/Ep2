#ifndef NAVEGADOR_H
#define NAVEGADOR_H

#include "Processo.h"
#include "Datagrama.h"
#include "ServidorWeb.h"
class Navegador: public Processo
{
    public:
        Navegador(int endereco, int porta, Roteador* gateway);
        virtual ~Navegador();

        virtual void abrir(int endereco, int porta);
        virtual void abrir(int endereco);
        virtual string getConteudo();

        virtual void receber(int origem,  Segmento* mensagem);

    private:
        string conteudo = "";
        bool emEspera = false;
};

#endif // NAVEGADOR_H

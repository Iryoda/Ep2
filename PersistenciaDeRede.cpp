#include "PersistenciaDeRede.h"
#include "Roteador.h"
PersistenciaDeRede::PersistenciaDeRede()
{
    this->rede = new Rede();
}

PersistenciaDeRede::~PersistenciaDeRede()
{
    //dtor
}
Rede* PersistenciaDeRede::carregar(string arquivo)
{
    //Roteador
    int quantidadeRoteadores;
    int enderecoRoteador;

    //Hospedeiro
    int quantidadeHospedeiros;
    int gateway;
    int enderecoHospedeiro;
    int quantidadeProcessos;
    int porta;
    string letra;
    string conteudo;

    //Tabela de Repasse
    int roteador;
    int roteadorPadrao;
    int quantidadeDeMapeamentos;
    int enderecoMapeamento;
    int noDestino;
    //Rede


    //Inicio Letitura
    ifstream input;

    input.open(arquivo);

    if(input.fail()){
        throw new invalid_argument("Arquivo não existe");
        input.close();
        return NULL;
    }
    //Pega quantidade de Roteadores do arquivo

    input >> quantidadeRoteadores;


    for(int i = 0; i < quantidadeRoteadores; i++) //[0] = 1// []
    {
        input >> enderecoRoteador;
        Roteador* r1 = new Roteador(enderecoRoteador);

        rede->adicionar(r1);
    }
    //Pega quantidade de Hospedeiros do arquivo
    input >> quantidadeHospedeiros;

    for( int i = 0; i < quantidadeHospedeiros; i++){
        input >> enderecoHospedeiro;
        input >> gateway;

        Roteador* r1 = dynamic_cast<Roteador*>(rede->getNo(gateway));

        if(r1 == NULL){
            throw new logic_error("Não há um roteador com esse endereço");
            input.close();
            return NULL;
        }

        Hospedeiro* h1 = new Hospedeiro(enderecoHospedeiro, r1);

        input >> quantidadeProcessos;

        //Verfica para cada quantidade de hospedeiros
        for( int j = 0; j < quantidadeProcessos; j++){
            input >> letra;
            input >> porta;
            if( letra == "w"){
                input >> conteudo;
                h1->adicionarServidorWeb(porta, conteudo);
            } else {
                h1->adicionarNavegador(porta);
            }

        } //Fim do loop de Processos
        rede->adicionar(h1);

    } //Fim do loop de hospedeiros

    input >> roteador;
    input >> roteadorPadrao;
    input >> quantidadeDeMapeamentos;

    while (input){
        //Crio um roteador que será um ponteiro do roteador dado
        //Junto ao no padrão
        Roteador* r1= dynamic_cast<Roteador*>(rede->getNo(roteador));
        No* noPadrao = rede->getNo(roteadorPadrao);

        //Pego a tabela de reapasse dele como t1
        TabelaDeRepasse* t1 = r1->getTabela();

        //E defino como roteadorPadrao
        t1->setPadrao(noPadrao);

        //Para cada mapeamento desse roteador excuto o mapear()
        for( int i = 0; i < quantidadeDeMapeamentos; i++){
            input >> enderecoMapeamento;
            input >> noDestino;
             No* Destino = rede->getNo(noDestino);

            t1->mapear(enderecoMapeamento, Destino);
        }
        //Pego o próximo caso existir
            input >> roteador;
            input >> roteadorPadrao;
            input >> quantidadeDeMapeamentos;
    }

    if( !input.eof()){
        throw new logic_error("Erro de leitura");
        input.close();
        return NULL;
    }

    return rede;

    input.close();
}

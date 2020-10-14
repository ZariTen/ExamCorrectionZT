#ifndef PROVA_H
#define PROVA_H

#include <string>
#include <questao.hpp>

struct Prova{
    private:
        int quantidadeAlunos;
        int quantidadeQuestoes;
        std::string gabarito;
        Questao* questoes;

    public:
        void setGabarito(std::string gabarito);
        std::string getGabarito();

        int getQtdAlunos();
        int getQtdQuestoes();

        Prova();
        ~Prova();

        void lerProva(std::string path); //Ler arquivo e contar quantos alunos e questões
        void analisarProva(std::string path); //Setar alunos e questoes
};

#endif
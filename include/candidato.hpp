#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <string>
#include <prova.hpp>

struct Candidato{
  private:
    std::string nome;
    int tamanhoProva;
    char respostas[10];
    int acertos;

  public:
    void acertarQuestao(); //Add 1 to acertos
    Candidato(std::string nome,char* r);
    void checkSizeTest(Prova pr); //If qtdQuestoes > 10, set respostas size to qtdQuestoes size
};

#endif
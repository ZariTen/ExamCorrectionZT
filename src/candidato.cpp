#include <candidato.hpp>


Candidato::Candidato(){
    acertos = 0;
    resposta="X";
}

void Candidato::setNome(std::string nome){
    this->nome = nome;
}

void Candidato::acertarQuestao(){
    this->acertos += 1;
}

std::string Candidato::getNome(){
    return this->nome;
}

int Candidato::questoesCertas(){
    return this->acertos;
}
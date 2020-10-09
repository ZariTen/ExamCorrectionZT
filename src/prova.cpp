#include <prova.hpp>
#include <fstream>
#include <iostream>

void Prova::setGabarito(std::string gabarito){

    this->gabarito = gabarito;

};

std::string Prova::getGabarito(){
    return this->gabarito;
};

int Prova::getQtdAlunos(){
    return this->quantidadeAlunos;
}

int Prova::getQtdQuestoes(){
    return this->quantidadeQuestoes;
}

void Prova::lerProva(std::string path){
    std::string line;
    std::ifstream input(path);
    quantidadeAlunos = 0;
    quantidadeQuestoes = 0;

    while(getline(input,line)){
        if(!line.empty()){
            
            std::cout << line << std::endl;
            ++quantidadeAlunos;
        }
    }

    std::cout << "Quantidade alunos: " << quantidadeAlunos << std::endl;
}

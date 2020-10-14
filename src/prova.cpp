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
    
    std::string delimitador = " ";
    std::string saved;
    int pos=0,questionIndex=0;

    while(getline(input,line)){
        quantidadeQuestoes=0;

        if(!line.empty()){
            //Delimitador para contar numero de questoes
            //Origem: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c?rq=1
            questionIndex=0;
            while((pos=line.find(delimitador)) != std::string::npos){
                saved = line.substr(0,pos);

                
                if(questionIndex > 0){
                    ++quantidadeQuestoes;
                }
                ++questionIndex;
                
                line.erase(0,pos+delimitador.length());
            }
            ++quantidadeQuestoes; //Função acima deixa sobrar 1 questao sempre
            ++quantidadeAlunos;
        }
    }
}

#include <prova.hpp>
#include <fstream>
#include <iostream>

void Prova::setGabarito(std::string gabarito){
    std::string line;
    std::ifstream input(gabarito);
    
    std::string delimitador = " ";
    std::string saved;
    int pos=0,questionIndex=0;
    std::string gbrito;

    while(getline(input,line)){
        

        if(!line.empty()){
            //Delimitador para contar numero de questoes
            //Origem: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c?rq=1
            while((pos=line.find(delimitador)) != std::string::npos){
                saved = line.substr(0,pos);

                
                gbrito.append(saved);
                
                line.erase(0,pos+delimitador.length());
            }
        }
    }

    this->gabarito = gbrito;
};

Prova::Prova(){
    questoes = new Questao[10];
}

Prova::~Prova(){
    delete[] questoes;
}

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

    //Aumenta tamanho do array caso passe de 10 questões
    if (quantidadeQuestoes > 10){
        Questao* tempArray = new Questao[quantidadeQuestoes+1];

        for(size_t i = 0; i < quantidadeQuestoes+1; ++i){
            tempArray[i] = questoes[i];
        }

        delete[] questoes;
        questoes = tempArray;
    }
}

#include <corretor.hpp>
#include <questao.hpp>
#include <fstream>
#include <iostream>

void corrigirProva(Candidato* candidatos,std::string path){

    std::string line;
    std::ifstream input(path);
    
    std::string delimitador = " ";
    std::string saved;
    int pos=0,questionIndex=0,candidatoIndex=0;

    while(getline(input,line)){
        if(!line.empty()){
            //Delimitador para contar numero de questoes
            //Origem: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c?rq=1
            questionIndex=0;
            while((pos=line.find(delimitador)) != std::string::npos){
                saved = line.substr(0,pos);

                
                if(questionIndex > 0){
                    candidatos[candidatoIndex].resposta.replace(questionIndex-1,1,saved);
                }
                else{
                    candidatos[candidatoIndex].setNome(saved);
                }
                ++questionIndex;
                
                line.erase(0,pos+delimitador.length());
            }
            candidatos[candidatoIndex].resposta.replace(questionIndex-1,1,line);  //Função acima deixa sobrar 1 questao sempre
        }
        ++candidatoIndex;
    }
}

void corrigirRespostas(Candidato* candidatos,Questao* questoes,int qtdCand,int qtdQuest, std::string gabarito){
    std::string letrasPossiveis = "ABCDE";

    for(int i = 0; i < qtdCand; ++i){
        for(int j = 0; j < qtdQuest; ++j){

            if(candidatos[i].resposta[j] == gabarito[j]){
                questoes[j].acertos+=1;
                candidatos[i].acertarQuestao();
            }
            else if( !(letrasPossiveis.find(candidatos[i].resposta[j]) != std::string::npos) ){ //Resposta em branco
                questoes[j].brancos+=1;
            }else{
                questoes[j].errors+=1;
            }
            
        }
    }
}

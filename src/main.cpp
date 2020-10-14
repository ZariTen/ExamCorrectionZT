#include <iostream>
#include <prova.hpp>
#include <candidato.hpp>
#include <corretor.hpp>
#include <questao.hpp>
#include <ordenacao.hpp>

int main(int argc, char* argv[]){
        // ./programa [Localização do arquivo] [metodo] [quantidade]
        // argv[1] = localização
        // argv[2] = metodo
        // argv[3] = quantidade
        if(argc < 4){
                std::cout << "./programa [Localização do arquivo] [metodo] [quantidade]" << std::endl;
                return 0;
        }
        Prova p;
        p.setGabarito("ABCDEEDCBA");
        p.lerProva(argv[1]);

        int qtdQuestoes = p.getQtdQuestoes();
        int qtdAlunos = p.getQtdAlunos();

        Questao questoes[qtdQuestoes];
        Candidato candidatosArr[qtdAlunos];
        corrigirProva(candidatosArr,argv[1]);
        corrigirRespostas(candidatosArr,questoes,qtdAlunos,qtdQuestoes,p.getGabarito());

        int quantidadeMostrar = atoi(argv[3]);

        if(argv[2] == std::string("best")){
                ordernarMelhorCandidato(candidatosArr,qtdAlunos);
        }
        else if (argv[2] == std::string("worst")){
                ordernarPiorCandidato(candidatosArr,qtdAlunos);
        }
        else if (argv[2] == std::string("best-questions")){
                ordernarQuestao(questoes,0);
        }
        else if (argv[2] == std::string("worst-questions")){
                ordernarQuestao(questoes,1);
        }
        else if (argv[2] == std::string("blank-questions")){
                ordernarQuestao(questoes,2);
        }
        else{
                std::cout << "Comando inválido. Apenas: best,worst,best-questions,worst-questions,blank-questions." << std::endl;
        }

        for(int i = 0; i < quantidadeMostrar; ++i){
                std::cout << i+1 << " - " << candidatosArr[i].getNome() << ": " << candidatosArr[i].questoesCertas() << std::endl;
                //std::cout << candidatosArr[i].getNome() << ": " << candidatosArr[i].resposta << std::endl;
        }
        return 0;
}

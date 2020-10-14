#include <iostream>
#include <prova.hpp>
#include <candidato.hpp>
#include <corretor.hpp>
#include <questao.hpp>
#include <ordenacao.hpp>

int main(int argc, char* argv[]){

        if(argc < 2){
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

        ordernarPiorCandidato(candidatosArr,qtdAlunos);

        for(int i = 0; i < 30; ++i){
                std::cout << candidatosArr[i].getNome() << ": " << candidatosArr[i].questoesCertas() << std::endl;
                //std::cout << candidatosArr[i].getNome() << ": " << candidatosArr[i].resposta << std::endl;
        }

        for(int i = 0; i < qtdQuestoes; ++i){
                //std::cout << "Questao " << i+1 << " acertos:" << questoes[i].acertos << std::endl;
                //std::cout << "Questao " << i+1 << " errors:" << questoes[i].errors << std::endl;
                //std::cout << "Questao " << i+1 << " brancos:" << questoes[i].brancos << std::endl;
        }
        return 0;
}

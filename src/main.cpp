#include <iostream>
#include <prova.hpp>
#include <candidato.hpp>

int main(int argc, char* argv[]){

        if(argc < 2){
                return 0;
        }
        Prova p;
        p.setGabarito("ABCDEEDCBA");
        p.lerProva(argv[1]);
        Candidato candidatosArr[p.getQtdAlunos()];
        return 0;
}

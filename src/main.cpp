#include <iostream>
#include <prova.hpp>

int main(int argc, char* argv[]){

        if(argc < 2){
                return 0;
        }
        Prova p;
        p.lerProva(argv[1]);
        return 0;
}

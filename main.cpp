#include <iostream>
#include <string.h>
#include <chrono>
#include <vector> 
#include <ctime>  
#include "radix.h"

void tokenize(std::string const &str, const char* delim, std::vector<std::string> &out) 
{ 
    char *token = strtok(const_cast<char*>(str.c_str()), delim); 
    while (token != nullptr) 
    { 
        out.push_back(std::string(token)); 
        token = strtok(nullptr, delim); 
    } 
} 

int main(int argc, char *argv[])
{
    std::vector<std::string> vetor;
    std::map<std::string, int> ocorrencias;
    std::map<std::string, int> topOcorrencias;
    std::string linha;
    std::string passagem;

    if(argc != 2)
    {
        std::cout << "Numero de argumentos errados!" << std::endl;
        return 1;
    }

    passagem = argv[1];

    getline(std::cin, linha);
    tokenize(linha, " ", vetor);

    MSD::sort(vetor);
    ocorrencias = MSD::countOccurrences(vetor);
    topOcorrencias = MSD::top1000Occurrences(ocorrencias);

    if(passagem.compare("0") == 0)
        print_vetor(vetor);
    else if (passagem.compare("1") == 0)
    {
        for (const auto& par : ocorrencias) {
            std::cout << par.first << " - " << par.second << std::endl;
        }
    }
    else if (passagem.compare("2") == 0)
    {
        for (const auto& par : topOcorrencias) {
            std::cout << par.first << " - " << par.second << std::endl;
        }
    }
    else   
        std::cout << "Não foi achado passagem para isso..." << std::endl;

    return 0;
}

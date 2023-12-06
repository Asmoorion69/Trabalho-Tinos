#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

struct Register{
    std::string codOperation;
    std::string month;
};
void insertSort(std::vector<std::string>& codes){
    int n = codes.size();
    for(int i = 1; i < n; i++){
        std::string key = codes[i];
        int j = i - 1;

        while(j >= 0 && codes[j] > key){
            codes[j + 1] = codes[j];
            j = j - 1;
        }
        codes[j + 1] = key;
    }
}

void searchCodeInFiles(const std::vector<std::string>& namesFiles/*, const std::string& searchCod*/){
    std::string nameFile;
    //bool codFound = false;

    for (const auto& file : namesFiles) {
        nameFile = file;
        std::ifstream inputFile(nameFile);

        std::string cod;
        std::vector<std::string> codes;
        while (inputFile >> cod){
            /*if (cod == searchCod){
                std::cout << "Codigo de operacao encontrado no arquivo: " << nameFile << std::endl << std::endl;
                codFound = true;
            }*/
            if(cod.size() == 10){
                codes.push_back(cod);
            }
        }

        inputFile.close();

        std::sort(codes.begin(), codes.end());

        std::cout << "Codigos ordenados em oredem alfabetica " << nameFile << ":" << std::endl;
        for(const std::string code : codes){
            std::cout << code << std::endl;
        }
        std::cout << std::endl;
    }

    /*if (!codFound){
        std::cout << "Codigo de operacao nao encontrado nos arquivos" << std::endl;
    }*/
}

int main(){
    std::ifstream fileNames("dados.txt");

    std::vector<std::string> namesFiles;
    std::string nameFile;
    while (std::getline(fileNames, nameFile)){
        namesFiles.push_back(nameFile);
        std::cout << "Arquivo " << nameFile << " adicionado a lista "<< std::endl << std::endl;
    }

    fileNames.close();

    /*std::string searchCod;
    std::cout << "Digite o codigo de operacao a ser procurado: ";
    std::cin >> searchCod;*/

    searchCodeInFiles(namesFiles);

    return 0;
}




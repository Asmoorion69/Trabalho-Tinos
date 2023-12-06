#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

void insertBinarySort(std::vector<std::string>& codes){
    int n = codes.size();
    for(int i = 1; i < n; i++){
        std::string key = codes[i];
        int left = 0;
        int right = i - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(codes[mid] < key){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        for(int j = i - 1; j >= left; j--){
            codes[j + 1] = codes[j];
        }
        codes[left] = key;
    }
}

/*bool codFoundInFile(const std::string& fileName, const std::string& searchCod){
    std::ifstream inputFile(fileName);

    std::string line;
    while (std::getline(inputFile, line)){
        if(line.find(searchCod) != std::string::npos){
            inputFile.close();
            return true;
        }
    }

    inputFile.close();
    return false;
}*/

void searchCodInFiles(const std::vector<std::string>& namesFiles){
    //bool codFound = false;
    std::string nameFile;

    for(const auto& file : namesFiles){
        nameFile = file;
        std::ifstream inputFile(nameFile);

        std::string cod;
        std::vector<std::string> codes;

        while(inputFile >> cod){
            if(cod.size() == 10){
                codes.push_back(cod);
            }
        }

        inputFile.close();

        insertBinarySort(codes);

        std::cout << "Codigos ordenados em ordem alfabetica do arquivo" << nameFile << ":" << std::endl;
        for(const auto& code : codes){
            std::cout << code << std::endl;
        }
        std::cout << std::endl;
    }
}

int main(){
    std::ifstream fileNames("dados.txt");

    std::vector<std::string> namesFiles;
    std::string nameFile;
    
    while(std::getline(fileNames, nameFile)){
        namesFiles.push_back(nameFile);
        std::cout << "Arquivo " << nameFile << " adicionado a lista" << std::endl << std::endl;
    }
    fileNames.close();

    /*std::string searchCod;
    std::cout << "Digite o cdigo de operacao a ser procurado: ";
    std::cin >> searchCod;*/

    searchCodInFiles(namesFiles);

    return 0;
}
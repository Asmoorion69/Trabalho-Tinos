#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

class QuickSort{
    private:
    std::vector<std::string> namesFiles;

    int part(std::vector<std::string>& array, int low, int high){
        std::string pivo = array[high];
        int i = low - 1;

        for(int j = low; j <= high - 1; j++){
            if(array[j] <= pivo){
                i++;
                std::swap(array[i], array[j]);
            }
        }
        std::swap(array[i + 1], array[high]);
        return(i + 1);

    }

    void quickSort(std::vector<std::string>& array, int low, int high){
        if(low < high){
            int pi = part(array, low, high);

            quickSort(array, low, pi - 1);
            quickSort(array, pi + 1, high);
        }
    }

    public:
    void addFile(const std::string& fileName){
        namesFiles.push_back(fileName);
    }

    void searchCod(){
        for(const auto& file : namesFiles){
            std::ifstream inputFile(file);

            std::string cod;
            std::vector<std::string> codes;

            while(inputFile >> cod){
                if(cod.size() == 10){
                    codes.push_back(cod);
                }
            }
            inputFile.close();

            quickSort(codes, 0, codes.size() - 1);

            std::cout << "Codigos ordenados em ordem alfabetica do arquivo" << file << ":" << std::endl;
            for(const auto& code : codes){
                std::cout << code << std::endl;
            }
            std::cout << std::endl;
        }
    }
};

int  main(){
    QuickSort fileSearch;
    std::string nameFile;
    std::ifstream fileNames("dados.txt");

    while(std::getline(fileNames, nameFile)){
        fileSearch.addFile(nameFile);
        std::cout << "Arquivo " <<nameFile << " adicionado a lista" << std::endl;
    }
    fileNames.close();

    fileSearch.searchCod();

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

class BubbleSort{
    private: 
    std::vector<std::string> namesFiles;

    void bubbleSort(std::vector<std::string>& codes){
        int n = codes.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(codes[j] > codes[j + 1]){
                    std::swap(codes[j], codes[j + 1]);
                }
            }
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

            bubbleSort(codes);

            std::cout << "Codigos ordenados em ordem alfabetica" << file << ":" << std::endl;
            for(const auto& code : codes){
                std::cout << code << std::endl;
            }
            std::cout << std::endl;
        }
    }
};

int main(){
    BubbleSort fileSearch;
    std::string nameFile;
    std::ifstream fileNames ("dados.txt");

    while(std::getline(fileNames, nameFile)){
        fileSearch.addFile(nameFile);
        std::cout << "Arquivo " << nameFile << " adicionado a lista" << std::endl << std::endl;
    }

    fileNames.close();
    
    fileSearch.searchCod();

    return 0;
}
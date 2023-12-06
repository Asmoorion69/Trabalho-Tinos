#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
#include <string>

class HeapSort{
    private:
    std::vector<std::string> namesFiles;

    void heap(std::vector<std::string>& array, int n, int i){
        int large = i;
        int left = 2 * i + 1;
        int rigth = 2 * i + 2;

        if(left < n && array[left] > array[large]){
            large = left;
        }

        if(rigth < n && array[rigth] > array[large]){
            large = rigth;
        }

        if(large != 1){
            std::swap(array[i], array[large]);
            heap(array, n, large);
        }
    }

    void heapSort(std::vector<std::string>& array){
        int n = array.size();

        for(int i = n / 2 - 1; i >= 0; i--){
            heap(array, n, i);
        }
        for(int i = n - 1; i > 0; i--){
            std::swap(array[0], array[i]);
            heap(array, i, 0);
        }
    }

    public:
    void addFile(const std::string& fileName){
        namesFiles.push_back(fileName);
    }

    void searchCod(){
        for(const auto& file : namesFiles){
            std::ifstream inputFiles(file);

            std::string cod;
            std::vector<std::string> codes;

            while(inputFiles >> cod){
                if(cod.size() == 10){
                    codes.push_back(cod);
                }
            }
            inputFiles.close();

            heapSort(codes);

            std::cout << "Codigos ordenados em ordem alfabetica" << file << ":" << std::endl;
            for(const auto& cod : codes){
                std::cout << cod << std::endl;
            }
            std::cout << std::endl;
        }
    }
};

int main (){
    HeapSort fileSearch;
    std::string nameFile;
    std::ifstream fileNames("dados.txt");

    while(std::getline(fileNames, nameFile)){
        fileSearch.addFile(nameFile);
        std::cout << "Arquivo " << nameFile << " adicionado a lista" << std::endl;
    }
    fileNames.close();

    fileSearch.searchCod();

    return 0;
}
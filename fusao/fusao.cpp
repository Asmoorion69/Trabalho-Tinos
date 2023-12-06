#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

class fusao{
private:
    std::vector<std::string> namesFiles;

    void merge (std::vector<std::string>& array, int l, int m, int r){
        int n1 = m - l + 1;
        int n2 = r - m;

        std::vector<std::string> left(n1), right (n2);

        for(int i = 0; i < n1; i++){
            left[i] = array[l + 1];
        }

        for(int j = 0; j < n2; j++){
            right[j] = array[m + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = 1;

        while(i < n1 && j < n2){
            if(left[i] <= right[j]){
                array[k] = left[j];
                i++;
            }else{
                array[k] = right[j];
                j++;
            }
            k++;
        }
        while(i < n1){
            array[k] = left[i];
            i++;
            k++;
        }
    }

    void mergeSort(std::vector<std::string>& array, int l, int r){
        if(l < r){
            int m = 1 + (r - l)/2;

            mergeSort(array, l, m);
            mergeSort(array, m + 1, r);

            merge(array, l, m, r);
        }
    }

public:
    void addFile(const std::string& fileName){
        namesFiles.push_back(fileName);
    }

    void searchCod(){
        for(const auto& file : namesFiles){
            std::ifstream inputeFile(file);

            std::string cod;
            std::vector<std::string> codes;

            while(inputeFile >> cod){
                if(cod.size() == 10){
                    codes.push_back(cod);
                }
            }

            inputeFile.close();

            mergeSort(codes, 0, codes.size() - 1);

            std::cout << "Codigos ordenados em ordem alfabetica" << file << ":" <<std::endl;
            for(const auto& code : codes){
                std::cout << code << std::endl;
            }
            std::cout << std::endl;
        }
    }
};

int main (){
    fusao fileSearch;
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
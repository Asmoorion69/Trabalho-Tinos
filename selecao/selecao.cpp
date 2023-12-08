#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void selectionSort(std::vector<std::string>& codes, int *comp, int *mov){
    int n = codes.size();
    std::string aux;
    for(int i = 0; i < n - 2; i++){
        int minIndex = i;
        for(int j = i + 1; j < n - 1; j++){
            if(codes[j] < codes[minIndex]){
                minIndex = j;
            }
            (*comp)++;
        }
        aux = codes[i];
        codes[i] = codes[minIndex];
        codes[minIndex] = aux;
        (*mov) += 3;
    }
}

void printVector(std::vector<std::string>& codes){
    for(int i = 0; i < codes.size(); i++){
        std::cout << codes[i] << std::endl;
    }
}

int main(){
    std::string aux;
    int comparacoes[5] = {};
    int movimentacoes[5] = {};

    std::vector<std::string> codesMes1;
    std::vector<std::string> codesMes2;
    std::vector<std::string> codesMes3;
    std::vector<std::string> codesMes4;
    std::vector<std::string> codesMes5;

    std::ifstream fileName1 ("mes_1.txt");
    std::ifstream fileName2 ("mes_2.txt");
    std::ifstream fileName3 ("mes_3.txt");
    std::ifstream fileName4 ("mes_4.txt");
    std::ifstream fileName5 ("mes_5.txt");

    while(std::getline(fileName1, aux)){
        codesMes1.insert(codesMes1.end(), aux);
    }
    while(std::getline(fileName2, aux)){
        codesMes2.insert(codesMes2.end(), aux);
    }
    while(std::getline(fileName3, aux)){
        codesMes3.insert(codesMes3.end(), aux);
    }
    while(std::getline(fileName4, aux)){
        codesMes4.insert(codesMes4.end(), aux);
    }
    while(std::getline(fileName5, aux)){
        codesMes5.insert(codesMes5.end(), aux);
    }

    selectionSort(codesMes1, &comparacoes[0], &movimentacoes[0]);
    selectionSort(codesMes2, &comparacoes[1], &movimentacoes[1]);
    selectionSort(codesMes3, &comparacoes[2], &movimentacoes[2]);
    selectionSort(codesMes4, &comparacoes[3], &movimentacoes[3]);
    selectionSort(codesMes5, &comparacoes[4], &movimentacoes[4]);

    printVector(codesMes1);
    printVector(codesMes2);
    printVector(codesMes3);
    printVector(codesMes4);
    printVector(codesMes5);
    std::cout << std::endl;

    for(int i = 0; i < 5; i++){
        std::cout << "Para mes " << i+1 << ":" << std::endl;
        std::cout << "Comparacoes: " << comparacoes[i] << std::endl;
        std::cout << "Movimentacoes: " << movimentacoes[i] << std::endl << std::endl;
    }

    fileName1.close();
    fileName2.close();
    fileName3.close();
    fileName4.close();
    fileName5.close();


    return 0;
}
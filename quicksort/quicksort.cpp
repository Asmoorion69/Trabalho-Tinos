#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int qsort(std::vector<std::string>& array, int low, int high, int* comp, int* mov){
    int i = low, j = high;
    std::string pivo = array[(low+high)/2], aux;

    do{
        while(array[i] < pivo){
            (*comp)++;
            i++;
        }
        (*comp)++;
        while(pivo < array[j]){
            (*comp)++;
            j--;
        }
        (*comp)++;
        if(i<=j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            (*mov)++;
            i++;
            j--;
        }
    }while(i<=j);
    if(low < j){
        qsort(array, low, j, comp, mov);
    }
    if(i < high){
        qsort(array, i, high, comp, mov);
    }

    }

void quickSort(std::vector<std::string>& array, int n, int* comp, int* mov){
    qsort(array, 0, n-1, comp, mov);
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

    quickSort(codesMes1, codesMes1.size(), &comparacoes[0], &movimentacoes[0]);
    quickSort(codesMes2, codesMes2.size(), &comparacoes[1], &movimentacoes[1]);
    quickSort(codesMes3, codesMes3.size(), &comparacoes[2], &movimentacoes[2]);
    quickSort(codesMes4, codesMes4.size(), &comparacoes[3], &movimentacoes[3]);
    quickSort(codesMes5, codesMes5.size(), &comparacoes[4], &movimentacoes[4]);

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
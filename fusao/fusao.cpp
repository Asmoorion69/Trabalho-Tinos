#include<iostream>
#include <fstream>
#include <vector>
#include <string>

//Combina duas partes ordenadas do vetor
void merge(std::vector<std::string>& a, int L, int h, int R, std::vector<std::string>& c, int* comp, int* mov){
    int i = L;
    int j = h + 1;
    int k = L - 1;

    while(i <= h && j <= R){
        k++;
        if(a[i] < a[j]){
            c[k] = a[i];
            (*mov)++;
            i++;
        }
        else{
            c[k] = a[j];
            (*mov)++;
            j++;
        }
        (*comp)++;

    }
    while(i <= h){
        k++;
        c[k] = a[i];
        (*mov)++;
        i++;
    }
    while(j <= R){
        k++;
        c[k] = a[j];
        (*mov)++;
        j++;
    }
}

//Realiza uma passagem da ordenação, chamando a função merge 
void mpass(std::vector<std::string>& a, int n, int p, std::vector<std::string>& c, int* comp, int* mov){
    int i = 0;
    while(i <= n - 2 * p){
        merge(a, i, i + p - 1, i + 2 * p - 1, c, comp, mov);
        i = i + 2 * p;
    }
    if(i + p - 1 < n){
        merge(a, i, i + p - 1, n - 1, c, comp, mov);
    }
    else{
        for(int j = i; j <= n - 1; j++){
            c[j] = a[j];
            (*mov)++;
        }
    }
}

//Impplementa o algoritmo Merge Sort para ordenar o vetor de strings
void mergeSort(std::vector<std::string>& a, int* comp, int* mov){
    std::vector<std::string> c;
    c.resize(a.size());
    int n = a.size();
    int p = 1;
    
    while(p < n){
        mpass(a, n, p , c, comp, mov);
        p *= 2;
        mpass(c, n, p, a, comp, mov);
        p *= 2;
    }
}

//Imprime os elemntos do vetor de strings
void printVector(std::vector<std::string>& codes){
    for(int i = 0; i < codes.size(); i++){
        std::cout << codes[i] << std::endl;
    }
}

//Le os códigos dos cincos arquivos mes_i
int main(){
    std::string aux;
    int comparacoes[5] = {};
    int movimentacoes[5] = {};

//Armazena os códigos em vetores separados para cada mes
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

//Ordena os códigos usando MergeSort
    mergeSort(codesMes1, &comparacoes[0], &movimentacoes[0]);
    mergeSort(codesMes2, &comparacoes[1], &movimentacoes[1]);
    mergeSort(codesMes3, &comparacoes[2], &movimentacoes[2]);
    mergeSort(codesMes4, &comparacoes[3], &movimentacoes[3]);
    mergeSort(codesMes5, &comparacoes[4], &movimentacoes[4]);

//Imprime os códigos ordenados de cada mes
    printVector(codesMes1);
    printVector(codesMes2);
    printVector(codesMes3);
    printVector(codesMes4);
    printVector(codesMes5);
    std::cout << std::endl;

//Exibe o numero de comparações e movimetações realizadas em cada ordenação
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
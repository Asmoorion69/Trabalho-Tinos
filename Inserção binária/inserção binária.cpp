#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//Ordena o vetor de strings usando o algoritmo de inserção binaria
void insertBinarySort(std::vector<std::string>& codes, int* comp, int* mov){
    int n = codes.size();
    for(int i = 1; i < n; i++){
        std::string key = codes[i];
        int left = 0;
        int right = i;

        while(left < right){
            int mid = (right + left) / 2;

            if(codes[mid] <= key){
                left = mid + 1;
            }else{
                right = mid;
            }
            (*comp)++;
        }
        int j = i;
        while(j > right){
            codes[j] = codes[j-1];
            (*mov)++;
            j--;
        }
        codes[right] = key;
        (*mov)++;
    }
}

//Imprime os elementos do vetor de strings
void printVector(std::vector<std::string>& codes){
    for(int i = 0; i < codes.size(); i++){
        std::cout << codes[i] << std::endl;
    }
}

//Le os códigos dos arquivos mes_i
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

//Ordena os códigos de cada mes usando o algoritimo de inserção binaria
    insertBinarySort(codesMes1, &comparacoes[0], &movimentacoes[0]);
    insertBinarySort(codesMes2, &comparacoes[1], &movimentacoes[1]);
    insertBinarySort(codesMes3, &comparacoes[2], &movimentacoes[2]);
    insertBinarySort(codesMes4, &comparacoes[3], &movimentacoes[3]);
    insertBinarySort(codesMes5, &comparacoes[4], &movimentacoes[4]);

//Imprime os c´´odigos oredenados de cada mes
    printVector(codesMes1);
    printVector(codesMes2);
    printVector(codesMes3);
    printVector(codesMes4);
    printVector(codesMes5);
    std::cout << std::endl;

//Eibe o numero de comparacoes e movimentações realizadas em cada ordenação 
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
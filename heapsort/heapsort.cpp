#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void heapify(std::vector<std::string>& array, int L, int R){
    int i = L;
    int j = 2 * L;
    std::string x = array[L];

    if (j < R && array[j] < array[j + 1]) {
        j++;
    }
    while ((j <= R) && (x < array[j])) {
        array[i] = array[j];
        i = j;
        j = 2*j;
       if (j < R && array[j] < array[j + 1]) {
            j++;
        }
    }
        
    array[i] = x;
}

void heapSort(std::vector<std::string>& array, int n){
    for(int L = n/2; L >= 0; L--){
        heapify(array, L, n);
    }
    for(int R = n-1; R >= 1; R--){
        std::string w = array[0];
        array[0] = array[R];
        array[R] = w;
        heapify(array, 0, R-1);
    }
}

void printVector(std::vector<std::string>& codes){
    for(int i = 0; i < codes.size(); i++){
        std::cout << codes[i] << std::endl;
    }
}

int main(){
    std::string aux;

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

    heapSort(codesMes1, codesMes1.size());
    heapSort(codesMes2, codesMes2.size());
    heapSort(codesMes3, codesMes3.size());
    heapSort(codesMes4, codesMes4.size());
    heapSort(codesMes5, codesMes5.size());

    printVector(codesMes1);
    printVector(codesMes2);
    printVector(codesMes3);
    printVector(codesMes4);
    printVector(codesMes5);

    fileName1.close();
    fileName2.close();
    fileName3.close();
    fileName4.close();
    fileName5.close();

    return 0;
}
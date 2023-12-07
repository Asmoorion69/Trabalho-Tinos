#include <iostream>
#include <fstream>
#include <vector>
#include <string>
 
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

    bubbleSort(codesMes1);
    bubbleSort(codesMes2);
    bubbleSort(codesMes3);
    bubbleSort(codesMes4);
    bubbleSort(codesMes5);

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
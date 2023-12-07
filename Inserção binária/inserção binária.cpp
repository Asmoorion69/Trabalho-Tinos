#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void insertBinarySort(std::vector<std::string>& codes){
    int n = codes.size();
    for(int i = 1; i < n; i++){
        std::string key = codes[i];
        int left = 0;
        int right = i - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(codes[mid] < key){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        for(int j = i - 1; j >= left; j--){
            codes[j + 1] = codes[j];
        }
        codes[left] = key;
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

    insertBinarySort(codesMes1);
    insertBinarySort(codesMes2);
    insertBinarySort(codesMes3);
    insertBinarySort(codesMes4);
    insertBinarySort(codesMes5);

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
#include <iostream>
#include <fstream>
#include "dataIO.hpp"

std::ifstream inFile;
std::ofstream outFile;


void createInFile(std::string fileName){
    inFile.open(fileName);
    return;
}
void createOutFile(std::string fileName){
    outFile.open(fileName);
    return;
}

void outputFile(char *inner){
    using namespace std;
    outFile << inner << endl;
    return ;
}

void outputFile(int inner){
    using namespace std;
    outFile << inner << endl;
    return;
}

void closeInFile(){
    inFile.close();
}
void closeOutFile(){
    outFile.close();
}
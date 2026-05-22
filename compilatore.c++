#include <fstream>
#include <iostream>
#include <string>
using std::string;

int main(
    int argc , //numero argomenti  
    char argv[])//lista argomenti con 0 che è se stesso
    {

    std::cout<<"Copyright (c) 2026 CofC-FM"<<std::endl<<"Compilatore C in assembly 16 bit"<<std::endl<<"Per più informazioni sul codice o sulla licenza vista https://github.com/CofC-FM/Compiler-C-C-in-asm-16-bit";

    std::ifstream file("test.txt");

    if (!file.is_open()) {
        std::cout << "Errore apertura file\n";
        return 1;
    }

    string linea;//linea del file
    
    while (std::getline(file, linea)) {
        
    }

    return 0;
}
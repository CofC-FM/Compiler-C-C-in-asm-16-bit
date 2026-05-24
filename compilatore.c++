#include <fstream>
#include <iostream>
#include <string>
using std::string;

string nfile;
bool org=false;


int main(
    int argc , //numero argomenti  
    char* argv[])//lista argomenti con 0 che è se stesso
    {
    std::setlocale(LC_ALL,"it_IT.utf8");
    std::cout<<"Copyright (c) 2026 CofC-FM"<<std::endl<<"Compilatore C in assembly 16 bit"<<std::endl<<"Per più informazioni sul codice o sulla licenza vista https://github.com/CofC-FM/Compiler-C-C-in-asm-16-bit";

    nfile="output.asm";//nome file output default
    if(argc==1){
        std::cout<<"Errore nessun argomento passato";
    }
    if(argc>2){//verifica argomenti
        string arg1="-o";
        string b1=argv[2];
        if(b1==arg1){
            nfile=argv[3];
        }
    }
    
    std::ofstream ffile(nfile);//file finale
    string gg=argv[1];
    std::ifstream file(gg);//file input

    if (!file.is_open() || !ffile.is_open()) {
        std::cout << "Errore apertura file\n";
        return 1;
    }

    string linea;//linea del file
    
    while (std::getline(file, linea)) {//traduzione effettiva
        {//org
        if (linea.rfind("#define ORG",0)==0 && !org){
            org=true;
            int x=0;
            char c=';';
            ffile<<"org ";
            while(!(linea[12+x]==c)){                            
                ffile<<linea[12+x];
                x++;
            }
        }
        ffile<<"\n";//chiudi riga obbligatorio
        }
        
    }
    file.close();
    std::cout<<std::endl<<"Operazione riuscita";
    return 0;
}
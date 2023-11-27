#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// variabili
string nome_programma;
string script_fi;
string color = "a";

int i;
int n_arg;

// funzioni n parametri
void func_1arg(string par_1);
void func_2arg(string par_1, string par_2);
void func_3arg(string par_1, string par_2, string par_3);

// funzioni con 1 parametro
void help();
void screenshot();

// funzioni con 2 parametri
void txt_color(string color);
void download_f(string file_download);
void download_url(string url_fi);
void esegui(string file_ese);

// funzioni con 3 parametri
void esegui_specifico(string tipo_ese, string file_ese);

int main(int argc, char *argv[]){
    if(argc > 1){

        // caricamento variabili
        nome_programma = argv[0];
        script_fi = argv[1];
        n_arg = argc - 1;

        switch (n_arg){

        case 1: func_1arg(argv[1]); break;
        case 2: func_2arg(argv[1], argv[2]); break;
        case 3: func_3arg(argv[1], argv[2], argv[3]); break;
        
        default: cout<<"Errore: nessuna funzione trovata con: "<<n_arg<<" argomenti"; break;
        }

    }else if(argc == 1){
        cout<<"Errore: devi inserire un argomento \n";
    }/*
    else if(argc > 2){
        cout<<"Errore: hai inserito troppi argomenti \n";
    }*/

    return 0;
}

// funzioni 1 arg
void func_1arg(string par_1){
    string par_a = par_1;
    if(par_a == "v" || par_a == "version") cout<<"Versione di programma: Alpha 0.1\n";
    if(par_a == "h" || par_a == "help") help();
    if(par_a == "s" || par_a == "screenshot") screenshot();
}

void screenshot(){
    int risultato = system("PowerShell -ExecutionPolicy Bypass -File funzioni/screen.ps1");  
    if (risultato == 0) {
        cout << "Screenshot eseguito! (cartella screenshot)\n";
    } else {
        cout<< "Si è verificato un errore.";
    }
}

void help(){
    ifstream inputFile("info.txt");
    if (!inputFile.is_open()) cout<<"Errore nell apertura del file per lettura:\nVerificare che il file 'info.txt' sia esistente, in caso contrario installare nuovamente il programma\n";
    
    string line;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    inputFile.close();
}

// funzioni 2 arg
void func_2arg(string par_1, string par_2){
    string par_a = par_1, par_b = par_2;
    if(par_a == "color") txt_color(par_b);
    if(par_a == "download" || par_a == "d") download_f(par_b);
    if(par_a == "download_url" || par_a == "d_url") download_url(par_b);
    if(par_a == "esegui" || par_a == "e") esegui(par_b);
}

void txt_color(string color){
    string colore = color;
    string comando = "color " + colore;
    int risultato = system(comando.c_str());
}

void download_f(string file_download){
    string file = file_download;
    string url = "https://explt.altervista.org/uploads/" + file;
    string comando = "curl -O " + url;

    int risultato = system(comando .c_str());

    if (risultato == 0) {
        cout << "Comando eseguito: file "<<file<<" scaricato con successo!\n";
    } else {
        cout<< "Si è verificato un errore nell'esecuzione del comando.";
    }
}

void download_url(string url_fi){
    string url = url_fi;
    string comando = "curl -O " + url;

    int risultato = system(comando.c_str());

    if (risultato == 0) {
        cout << "Comando eseguito: url "<<url<<" scaricato con successo!\n";
    } else {
        cout<< "Si è verificato un errore nell'esecuzione del comando.";
    }
}

void esegui(string file_ese){
    string file = file_ese;
    string comando = "start " + file;
    int risultato = system(comando.c_str());  
}

// funzioni 3 arg
void func_3arg(string par_1, string par_2, string par_3){
    string par_a = par_1, par_b = par_2, par_c = par_3;
    if(par_a == "esegui" || par_a == "e") esegui_specifico(par_b, par_c);
}

void esegui_specifico(string tipo_ese, string file_ese){
    string tipo = tipo_ese;
    string file = file_ese;
    string comando;

    if(tipo == "vbs"){
        string comando = "start cmd /c cscript " + file;
        int risultato = system(comando.c_str());  
    }
    if(tipo == "ps1"){
        string comando = "PowerShell -ExecutionPolicy Bypass -File" + file;
        int risultato = system(comando.c_str());  
    }

}
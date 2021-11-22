#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "tk.cpp"


using namespace std;



void LeDados (){
   ifstream arq("teste.csv");
   
   if(arq.is_open())
    {
        cout << "Informacoes armazenadas no arquivo:\n\n***" << endl;
        string stream super;
        string temp = "";        
        string id;
        string text;
        string votes;
        string version;
        string date;
        
          
        text = "";
        getline(arq,id,',');
        
        getline(arq,super,'"');
        getline(arq,super,'"');
        
        for (int i=0; i < (int)super.size(); i++){
           
           if ( super[i] != ',' )
           {
               cout << "Entreou no if" << endl;
               text += super[i];
                              
           }else{
             text += " ";                              
          }         
               
        }
        getline(arq,votes,',');
        getline (arq,version, ',');
        getline(arq,date,'\n');
        
        //cout << temp << endl;
        
        
        cout << "-------------------" << endl;
        cout << "Imprimindo a Review" << endl;
        cout << "-------------------" << endl;
        cout << "Id: " << id << endl;
        cout << "Texto: " << text << endl;
        cout << "Votos: " << votes << endl;
        cout << "Versao do App: " << version << endl;
        cout << "Data da Review: " << date << endl;
        cout << "-------------------" << endl;
        cout << "Fim"<< endl;
        cout << "-------------------" << endl;
        
        // ERRO: irá gerar lixo de memória, pois val irá armazenar todos os dígitos na sequência
        //int intval; 
        //arq >> intval;
        // cout << str << '\n' << val << '\n' << intval << endl;
        
        cout << "\n***" << endl;
        
    
       
         
    }


    else
        cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;
}



void readCharbyChar(){

    ifstream file ("teste.csv");
    ofstream printer;

    printer.open( "outfile.txt", ios::out);
    
    if (file.is_open()){
    
    string id;
    string text;
    string votes;
    string version;
    string date;
    
    char data;

    while (!file.eof()){
    
    // form id string
    while (data != '\n')
    {
        //cout << data;
        file.get(data);
        id += data;
    }
    cout << endl;
    cout << "Id: " << id << endl;
    printer << "Id: " << id<< endl;


/**
    // form text string
    if (data == '"'){
    
    while (data != '"')
    {
        cout << data;
        file.get(data);
        text += data;
    }
    cout << endl;
    
    }else{
        while (data != '"')
    {
        cout << data;
        file.get(data);
        text += data;
    }
    cout << endl;
    }
    cout << "Text: " << text << endl;

    // form Votes string
    while (data != ',')
    {
        cout << data;
        file.get(data);
        votes += data;
    }
    cout << endl;
    cout << "Votes: " << votes << endl;

    // form App Version Data
    while (data != ',')
    {
        cout << data;
        file.get(data);
        version += data;
    } cout << endl;
    cout << "App Version: " << version << endl;

    // form Date Data
    while (data != '\n')
    {
        cout << data;
        file.get(data);
        date += data;
    } 
    cout << endl;
    cout << "Date: " << date << endl;
    cout << "----------------------------------------------" << endl;
  
   **/ 
    }

    }
    else 
     cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;

}



int main(){

    LeDados();
    return 0;
}


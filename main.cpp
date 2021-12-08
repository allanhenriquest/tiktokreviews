#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "tk.cpp"

using namespace std;

void PreProcessamento(ifstream &csv, ofstream &bin)
{

    TikTokReviews r;
    int bufSize = 10000000;
    char *buffer = new char[bufSize];
    //string primeiraLinha;
    //getline(csv, primeiraLinha); //pula a primeira linha
    csv.read(buffer, bufSize);
    int campo = 0;
    bool inCampoText = false;
    bin << buffer << endl;
    //gcount() é o total de caracteres lidos


   

    while (csv.gcount() > 0)
    {
        
        int ini = 0;
        for (int pos = 0; pos < csv.gcount(); pos++)
        {

            if (buffer[pos] == ',')
            {
                if (!inCampoText)
                {
                    if (campo == 2)
                    {
                        cout << "entrou campo 2" << endl;
                        //int val = atoi(&buffer[ini]);
                        //bin.write(reinterpret_cast<const char *>(&atoi), sizeof(int));
                        bin.write(&buffer[ini], pos - ini);
                        ini = pos + 1; // pula a vírgula
                        cout << "Valor de ini: " << ini << endl;
                        campo = (campo + 1) % 5;
                        bin << endl;
                        cout << "Valor de pos: "<< pos << endl;
                    }
                    else
                    {
                        cout << "Campo atual: " << campo << endl;
                        bin.write(&buffer[ini], pos - ini);
                        ini = pos + 1; // pula a vírgula
                        cout << "Valor de ini: " << ini << endl;
                        campo = (campo + 1) % 5;
                        cout << "Proximo Campo: " << campo << endl;
                        bin << endl;
                        cout << "Valor de pos: "<< pos << endl;
                    }
                }
            }
            else if (buffer[pos] == '"')

            {   
                
                if ( buffer[pos] == '"') {        
                    if (buffer[pos + 1] != '"')
                    {
                        if (buffer[pos + 1] == ',')
                        {
                            // encerrando o campo text
                            cout << "Encerrando Campo Text" << endl;
                            inCampoText = false;
                        }
                        else
                        {
                            // começando o campo text
                            cout << " Campo Text Identificado " << endl;
                            inCampoText = true;
                            cout << "Campo atual: " << campo << endl;
                            bin.write(&buffer[ini], pos - ini);
                            ini = pos + 1; // pula a vírgula
                            cout << "Valor de ini: " << ini << endl;
                            campo = (campo + 1) % 5;
                            cout << "Proximo Campo: " << campo << endl;
                            bin << endl;
                            cout << "Valor de pos: "<< pos << endl;
                        }
                    }
                }
                
            } else if (buffer[pos] == '\n'){

                cout << "Campo atual: " << campo << endl;
                        bin.write(&buffer[ini], pos - ini);
                        ini = pos + 1; // pula a vírgula
                        cout << "Valor de ini: " << ini << endl;
                        campo = (campo + 1) % 5;
                        cout << "Proximo Campo: " << campo << endl;
                        inCampoText = false;
                        bin << endl;
                        cout << "Valor de pos: "<< pos << endl;
                       

            }
            // switch (campo)
            // {

            // case 0: // campo de id

            //     if (buffer[pos] == ',')
            //     {
            //         bin.write(&buffer[ini], pos - ini);
            //         ini = pos + 1; // pula a vírgula
            //         campo = (campo + 1) % 5;
            //         break;
            //     }

            // case 1: // campo de texto

            //     if (buffer[pos] == ',' ||
            //         buffer[ini] == '"' && buffer[pos] == '"' && buffer[pos] == ',')
            //     {
            //         bin.write(&buffer[ini], pos - ini);
            //         ini = pos + 1; // pula a vírgula
            //         campo = (campo + 1) % 5;
            //         break;
            //     }

            // case 2: // campo de votos

            //     if (buffer[pos] == ',')
            //     {
            //         int val = atoi(&buffer[ini]);
            //         bin.write(reinterpret_cast<const char *>(&atoi), sizeof(int));
            //         ini = pos + 1; // pula a vírgula
            //         campo = (campo + 1) % 5;
            //         break;
            //     }

            // case 3: // campo de versao do app

            //     if (buffer[pos] == ',')
            //     {
            //         bin.write(&buffer[ini], pos - ini);
            //         ini = pos + 1; // pula a vírgula
            //         campo = (campo + 1) % 5;
            //         break;
            //     }

            // case 4: // campo de data

            //     if (buffer[pos] == ',')
            //     {
            //         bin.write(&buffer[ini], pos - ini);
            //         ini = pos + 1; // pula a vírgula
            //         campo = (campo + 1) % 5;
            //         break;
            //     }

            //     return;
            // }
        }

        csv.read(buffer, bufSize);
    }

    bin.close();
    csv.close();
}

void readCharbyChar()
{

    ifstream file("teste.csv");
    ofstream printer;

    printer.open("outfile.txt", ios::out);

    if (file.is_open())
    {

        string id;
        string text;
        string votes;
        string version;
        string date;

        char data;

        while (!file.eof())
        {

            // form id string
            while (data != '\n')
            {
                //cout << data;
                file.get(data);
                id += data;
            }
            cout << endl;
            cout << "Id: " << id << endl;
            printer << "Id: " << id << endl;

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

int main()
{

    ifstream csv("teste.csv");
    ofstream bin("binario.bin");

    PreProcessamento(csv, bin);

    return 0;
}

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include "tk.cpp"

using namespace std;

/*--------------------------------------------------------------------------------------------------------------

Função de Pré - Processamento: Realiza o processsamento dos dados do arquvio csv, separando os campos e as linhas
para a escrita no arquivo binário. 

Variaveis: 
registraTeste: Gera um arquivo "registroTeste.txt" para registrar como o algoritmo esta lendo o arquivo;
csv: Abre o arquivo csv em modo de leitura;
i: conta a posição do caracter na linha;
j: auxilia na contagem de carecters para armazenar no vetor auxiliar;
primeiaLinha: Descarta a primeira linha, cabeçalho do arquivo;

--------------------------------------------------------------------------------------------------------------*/
void PreProcessamento2()
{

    // Declarar Variaveis
    ofstream registraTeste("registroTeste2.txt");
    FILE *csv = fopen("teste30.csv", "r");
    int i, j;
    char aux[1000000000], linha[1000000000];
    TikTokReviews r;
    int contalinhas = 0;
    //Descarta o cabeçalho
    char primeiraLinha[100];
    fgets(primeiraLinha, 54, csv);
    registraTeste << "Pula a Primeira Linha: " << primeiraLinha << endl;
    registraTeste << "------------------------------------------------" << endl;

    //Laco de repeticao le a linha caracter por caracter, armezanando os campos
    while (fgets(linha, 100000, csv) != NULL)
    {
        contalinhas++;
        i = 0;                                     //contador do caracter igual a 0;
        j = 0;                                     // contador auxiliar igual a zero;
        while (linha[i] != 'g' && linha[i] != '"') //descarta lixo de memoria;
            i++;
        cout << "Primeiro caractere da linha: " << linha[i] << endl; // verifica se ouve leitura de lixo de memoria
        cout << linha << endl;                                       // imprime a linha no console para verificar se está correta;
        if (linha[i] != '"')// descarta eventuais aspas inicias;
        { 

            // ----------------------------------------------------------------------------------------------------------
            // ----------------------------------LEITURA DO CAMPO ID-----------------------------------------------------
            //-----------------------------------------------------------------------------------------------------------

            while (linha[i] != ',')
            { //CONDICAÇÃO DE PARADA: ','

                aux[j] = linha[i];
                i++;
                j++;
            }

            aux[j] = '\0'; // MARCA FIM VETOR AUXILIAR
            registraTeste << "Valor do ID: " << aux << endl;
            cout << "id: " << aux << endl;
            r.setId(aux);
            cout << "r.id: " << r.getId() << endl;

            j = 0; // // VOLTA VETOR AUXILIAR PARA POSIÇÃO 0;
            i++;   // DESCARTA VIRGULA

            // ----------------------------------------------------------------------------------------------------------
            // ----------------------------------LEITURA DO CAMPO TEXT---------------------------------------------------
            //-----------------------------------------------------------------------------------------------------------

            if (linha[i] == '"')
            {
                i++;                    //DESCARTA A ASPAS
                while (linha[i] != '"') //PROCURA FECHAR AS ASPAS, LE INCLUSIVE A VIRGULA
                {
                    aux[j] = linha[i];
                    i++;
                    j++;
                }
                aux[j] = '\0'; //RESETA VETOR AUXILIAR
                registraTeste << "Valor do TEXT:(Vírgula no Meio): " << aux << endl;
                cout << "texto: " << aux << endl;
                r.setText(aux);
                cout << "r.text " << r.getText() << endl;
                j = 0; // VOLTA VETOR AUXILIAR PARA POSIÇÃO 0;
                i++;   //DESCARTA AS ASPAS
                i++;   //DESCARTA A VIRGULA POS-ASPAS
            }
            else
            { //CASO NÃO POSSUA VÍRGULA NO MEIO DO TEXTO

                while (linha[i] != ',')
                { // LE ENQUANTO NAO ACHA VIRGULA

                    aux[j] = linha[i];
                    i++;
                    j++;
                }
                aux[j] = '\0'; //RESETA VETOR AUXILIAR
                registraTeste << "Valor do TEXT (SEM VIRGULA): " << aux << endl;
                cout << "texto: " << aux << endl;
                r.setText(aux);
                cout << "r.text " << r.getText() << endl;

                j = 0; // VOLTA VETOR AUXILIAR PARA POSIÇÃO 0;
                i++;   // DESCARTA VIRGULA POSTERIOR;
            }

            // ----------------------------------------------------------------------------------------------------------
            // ----------------------------------LEITURA DO CAMPO APP VOTES----------------------------------------------
            //-----------------------------------------------------------------------------------------------------------

            while (linha[i] != ',') //LE ENQUANTO NAO ACHA VIRGULA
            {
                aux[j] = linha[i];
                i++;
                j++;
            }
            aux[j] = '\0'; //RESETA VETOR AUXILIAR
            registraTeste << "Valor do VOTOS: " << aux << endl;
            cout << "votos: " << aux << endl;
            
            j = 0; 
            i++;
        
        // ----------------------------------------------------------------------------------------------------------
        // ----------------------------------LEITURA DO CAMPO APP VERSION--------------------------------------------
        //-----------------------------------------------------------------------------------------------------------
         
            while (linha[i] != ',')
            {
                aux[j] = linha[i];
                i++;
                j++;
            }
            aux[j] = '\0';
            registraTeste << "Valor do VESION: " << aux << endl;
            cout << "versao: " << aux << endl;
            r.setAppVersion(aux);
            cout << "r.versao: " << r.getAppVersion() << endl;

            j = 0;
            i++;

        // ----------------------------------------------------------------------------------------------------------
        // ----------------------------------LEITURA DO CAMPO DATA---------------------------------------------------
        //-----------------------------------------------------------------------------------------------------------
        
            while (linha[i] != '\n')
            {
                aux[j] = linha[i];
                i++;
                j++;
            }
            aux[j] = '\0';
            registraTeste << "Valor do DATA: " << aux << endl;
            registraTeste << "-----------------------------------------------" << endl;
            cout << "data: " << aux << endl;
            r.setDate(aux);
            cout << "r.date: " << r.getDate() << endl;
        }

        else
        {
            registraTeste << "-----------------------------------------------" << endl;
            registraTeste << "BUG REPORT: IDENTIFICOU ASPAS NO INICIO" << endl;
            registraTeste << linha << endl;
            registraTeste << "-----------------------------------------------" << endl;
            
            cout << "entrou no else " << endl;
            i++;
            while (linha[i] != ',')
            {
                cout << linha[i] << endl;
                aux[j] = linha[i];
                i++;
                j++;
            }
            aux[j] = '\0';
            registraTeste << "Valor do ID: " << aux << endl;
            cout << "id: " << aux << endl;
            r.setId(aux);
            cout << "r.id " << r.getId() << endl;

            i++;
            i++;
            j = 0;
            while (linha[i] != '"')
            {
                aux[j] = linha[i];
                i++;
                j++;
            }
            aux[j] = '\0';
            registraTeste << "Valor do TEXT: " << aux << endl;
            cout << "texto: " << aux << endl;
            r.setText(aux);
            cout << "r.text " << r.getText() << endl;

            i++;
            i++;
            j = 0;
            while (linha[i] != ',')
            {
                aux[j] = linha[i];
                i++;
                j++;
            }
            aux[j] = '\0';
            registraTeste << "Valor do VOTES: " << aux << endl;
            cout << "votos: " << aux << endl;

            j = 0;
            i++;
            while (linha[i] != ',')
            {
                aux[j] = linha[i];
                i++;
                j++;
            }
            aux[j] = '\0';
            registraTeste << "Valor do VERSION: " << aux << endl;
            cout << "versao: " << aux << endl;
            r.setAppVersion(aux);
            cout << "r.versao: " << r.getAppVersion() << endl;

            j = 0;
            i++;
            while (linha[i] != '"')
            {
                aux[j] = linha[i];
                i++;
                j++;
            }
            aux[j] = '\0';
            registraTeste << "Valor do DATA: " << aux << endl;
            registraTeste << "------------------------------------------ " << endl;
            cout << "data: " << aux << endl;
            r.setDate(aux);
            cout << "r.date: " << r.getDate() << endl;
        }
    }
    
    registraTeste << "------------------------------------------ " << endl;
    registraTeste << "Total de Linhas Lidas: " << contalinhas << endl;
    
    registraTeste.close();
}

void PreProcessamento(ifstream &csv, ofstream &bin)
{

    string linha;
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

    while (!csv.eof())
    {
        getline(csv, linha);
        cout << linha;
    }

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
                        cout << "Valor de pos: " << pos << endl;
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
                        cout << "Valor de pos: " << pos << endl;
                    }
                }
            }
            else if (buffer[pos] == '"')

            {

                if (buffer[pos] == '"')
                {
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
                            cout << "Valor de pos: " << pos << endl;
                        }
                    }
                }
            }
            else if (buffer[pos] == '\n')
            {

                cout << "Campo atual: " << campo << endl;
                bin.write(&buffer[ini], pos - ini);
                ini = pos + 1; // pula a vírgula
                cout << "Valor de ini: " << ini << endl;
                campo = (campo + 1) % 5;
                cout << "Proximo Campo: " << campo << endl;
                inCampoText = false;
                bin << endl;
                cout << "Valor de pos: " << pos << endl;
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

    FILE *bin = fopen("binario.bin", "w");

    PreProcessamento2();

    return 0;
}

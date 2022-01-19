// versao que le todos os campos com fun��es
// resolver o problema de campos ausentes

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "tk.cpp"

using namespace std;

char linha[100000];

void leId(char id[], int *i, int *j){
	*i = 0;
    *j = 0;
    while (linha[*i] != 'g' && linha[*i] != '"')
    	(*i)++;
	//    	cout << "Primeiro caractere da linha: " << linha[i] << endl;	
    //	cout << linha << endl;
    	
	while (linha[*i] != ','){
    	//		cout << linha[i] << endl;
		id[*j] = linha[*i];
		(*i)++;
		(*j)++;
	}
	id[*j] = '\0';
    	//	cout << "id: " << aux << endl;
}

bool leTexto(char texto[], int *i, int *j, bool quebra)
{
	//cout << "LInha dentro do leTexto: " << linha << endl;
	*j = 0;
	if (!quebra)
		(*i)++;
	else (*i)--;
	if (linha[*i] == '"'){
		(*i)++;
    	while (linha[*i] != '"'){
    		if (linha[*i] == '\n'){
    			texto[*j] = '\0';
    			return true;
    		}
    		texto[*j] = linha[*i];
			(*i)++;
			(*j)++;
		}
		(*i)++;
		texto[*j] = '\0';
	    	//	cout << "texto: " << aux << endl;
	    	//	cout << "r.text " << r.getText() << endl;
	    	//	getch();
	}
    else {
		while (linha[*i] != ','){
    		if (linha[*i] == '\n'){
				texto[*j] = '\0';
    			return true;
    		}
			texto[*j] = linha[*i];
			(*i)++;
			(*j)++;
		}
		texto[*j] = '\0';
	    	//	cout << "texto: " << aux << endl;
	    	//	cout << "r.text " << r.getText() << endl;
	    	//	getch();
    	
	}
	return false;
}

void leVotos(char votos[], int *i, int *j)
{
	*j = 0; 
	(*i)++;
	while (linha[*i] != ','){
		votos[*j] = linha[*i];
		(*i)++;
		(*j)++;
	}
	votos[*j] = '\0';
}

void leVersao(char versao[], int *i, int *j)
{
	*j = 0;
	(*i)++;
	while (linha[*i] != ','){
		versao[*j] = linha[*i];
		(*i)++;
		(*j)++;
	}
	versao[*j] = '\0';
	//	cout << "versao: " << aux << endl;
}

void leData(char data[], int *i, int *j)
{
	*j = 0;
	(*i)++;
	while (linha[*i] != '\n'){
		data[*j] = linha[*i];
		(*i)++;
		(*j)++;
	}
	data[*j] = '\0';
	//	cout << "data: " << aux << endl;
}



void PreProcessamento2()
{
	
	
	FILE *csv = fopen("tiktok_app_reviews.csv", "r");
	FILE *binario = fopen("tiktok_app_reviews.bin", "wb");  
	ofstream registraTeste("output01.txt");
	
	int i, j;
	bool quebra = false;
	char aux[100000], texto1[100000], texto2[100000];
	TikTokReviews r;
    long countLinha = 0;
  //  char *buffer = new char[bufSize];
    string primeiraLinha;
	registraTeste << "Pula a Primeira Linha: " << primeiraLinha << endl;
    registraTeste << "------------------------------------------------" << endl;
 //   getline(csv, primeiraLinha); //pula a primeira linha
 //   cout << primeiraLinha << endl;
 	
	 if (binario == NULL)
	 	printf("Arquivo binario nao pode ser aberto");
	 	
	 fgets(linha, 100000, csv);
    int campo = 0;
    bool inCampoText = false;
    while (fgets(linha, 100000, csv)!= NULL){
		//cout << "Linha : " << linha << endl;
		//cout << "Campo : " << campo << endl;
		switch(campo){
    		case 0: // le id 
				leId(aux, &i, &j);
				r.setId(aux);
				registraTeste << "------------------------------------------------" << endl;
				registraTeste << "Valor do ID: " << r.getId() << endl;
    			campo++;
    		//cout << "r.id: " << r.getId() << endl;
    	//	getch();
    		case 1:
    			quebra = leTexto(texto2, &i, &j, quebra); 
    			if (quebra){
    				i = 0;
  					//cout << "entro no if"<< endl;
					strcat(texto1, texto2);
  					i++;
  				//	j++;
  					//cout << "Texto 2 dentro do if " << texto2 << endl;
  					//cout << "Texto 1 dentro do if " << texto1 << endl;
  					break;
  				}
  				else {
				  strcpy(texto1, texto2);
				  //cout << "Texto 2 dentro do else " << texto2 << endl;
  				  //cout << "Texto 1 dentro do else " << texto1 << endl;

				}
    			r.setText(texto1);
    			//cout << "texto: " << texto1 << endl;
				registraTeste << "Valor do TEXT: " << r.getText() << endl;
				campo++;
			case 2: 	
				leVotos( aux, &i, &j);
				//cout << "votos: " << aux << endl;
				campo++;
				registraTeste << "Valor dos UPVOTES: " << r.getUpvotes() << endl;
				//r.setVotos(aux);
				//	getch();
			case 3:
				leVersao( aux, &i, &j);
				r.setAppVersion(aux);
				registraTeste << "Valor da VERSAO: " << r.getAppVersion() << endl;
				campo++;
				//cout << "r.versao: " << r.getAppVersion() << endl;				
				//	getch();
			case 4:
				leData( aux, &i, &j);
				r.setDate(aux);
				registraTeste << "Valor da DATA: " << r.getDate() << endl;
                registraTeste << "-----------------------------------------------" << endl;
				campo = 0;
				//cout << "r.date: " << r.getDate() << endl;				
    			
    	}
    	fwrite(&r, sizeof(TikTokReviews), 1, binario);
    	countLinha++;
		registraTeste << "############################################### " << endl;
        registraTeste << "Linhas Lidas: " << countLinha << endl;
        registraTeste << "############################################### " << endl;
    	//getch();
	}

	registraTeste.close();
	fclose(binario);
	fclose(csv);
    
}

void leBinario(){
    FILE *bin = fopen("tiktok_app_reviews.bin", "rb");
	ofstream registraBinario("resultadoArmazenamento.txt");
    TikTokReviews r;
    int i = 0;
    
    if (bin == NULL){
    	cout << "Erro: arquivo nao pode ser aberto" << endl;
    	return;
	}
	while (fread(&r, sizeof(TikTokReviews), 1, bin) != 0){
		cout << "Linha : " << i << endl;
		r.PrintReview();
		registraBinario << "------------------------------------------------" << endl;
		registraBinario << "Valor do ID: " << r.getId() << endl;
		registraBinario << "Valor do TEXT: " << r.getText() << endl;
		registraBinario << "Valor dos UPVOTES: " << r.getUpvotes() << endl;
		registraBinario << "Valor da VERSAO: " << r.getAppVersion() << endl;
		registraBinario << "Valor da DATA: " << r.getDate() << endl;
        registraBinario << "-----------------------------------------------" << endl;

		i++;
	}
	registraBinario.close();
	fclose(bin);
}

int main()
{

    PreProcessamento2();
	cout << "Lendo binario " << endl;
    leBinario();

    return 0;
}

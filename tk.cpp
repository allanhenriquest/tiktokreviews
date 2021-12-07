/*

IMPLEMENTAÇÃO DA ESTRUTURA DE DADOS DA AVALIAÇÃO DO TIK TOK

*/

#include "tk.hpp"
#include <string>

using namespace std;

// Implementação do construtor e métodos de acesso

TikTokReviews::TikTokReviews(){  
     
};


TikTokReviews::TikTokReviews (string i, string t, double u, string a, string d){
        
     id = i;
     text = t;
     upvotes = u;
     app_version = a;
     date = d;

};

    string TikTokReviews::getId(){
        return id;
    };
    
    void TikTokReviews::setId( string i ){
        id = i;
    };

    string TikTokReviews::getText(){
        return text;
    };
    
    void TikTokReviews::setText(string t) {
        text = t;
    };

    double TikTokReviews::getUpvotes(){
        return upvotes;
    };
    
    void TikTokReviews::setUpvotes(double u){
        upvotes = u;
    };

    string TikTokReviews::getAppVersion(){
        return app_version;
    };

    void TikTokReviews::setAppVersion( string a ){
        app_version = a;        
    };

    string TikTokReviews::getDate(){
        return date;
    };
    
    void TikTokReviews::setDate(string d){
        date = d;

    };
    
    void TikTokReviews::PrintReview(){
        cout << "-------------------" << endl;
        cout << "Imprimindo a Review" << endl;
        cout << "-------------------" << endl;
        cout << "Id: " << id << endl;
        cout << "Texto: " << text << endl;
        cout << "Votos: " << upvotes << endl;
        cout << "Versao do App: " << app_version << endl;
        cout << "Data da Review: " << date << endl;
        cout << "-------------------" << endl;
        cout << "Fim"<< endl;
        cout << "-------------------" << endl;
        
    };
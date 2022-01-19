/*

ESTRUTURA PARA ARMAZENAMENTO DAS AVALIAÇÕES DO APP TIK TOK

*/
#include <iostream>
#include <string>

using namespace std;

class TikTokReviews {

    private:
    
    string id;
    string text;
    int upvotes;
    string app_version;
    string date;

    public:

    //Class Constructor

    TikTokReviews();
    TikTokReviews (string i, string t, int u, string a, string d);

    std::string getId();
    void setId(string id);

    std::string getText();
    void setText(string text);

    int getUpvotes();
    void setUpvotes(int upvotes);

    std::string getAppVersion();
    void setAppVersion(string app_version);

    std::string getDate();
    void setDate(string date);
    
    void PrintReview();

};


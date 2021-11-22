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
    double upvotes;
    string app_version;
    string date;

    public:

    //Class Constructor

    TikTokReviews (string i, string t, double u, string a, string d);

    std::string getId();
    void setId(string id);

    std::string getText();
    void setText(string text);

    double getUpvotes();
    void setUpvotes(double upvotes);

    std::string getAppVersion();
    void setAppVersion(string app_version);

    std::string getDate();
    void setDate(string date);
    
    void PrintReview();

};


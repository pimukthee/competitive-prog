#include <iostream>
#include <map>
#include <string>
using namespace std;
map <string,bool> dic;
int main()
{
    int T;
    cin >> T;
    string dict,word,sword;
    while(T--)
    {
        cin.ignore();
        getline(cin,dict);
        dic.clear();
        word="";
        for(int i=0; i<dict.size(); i++)
        {
            if(dict[i]!=' ')
                word+=dict[i];
            else
            {
                dic[word]=true;
                word="";
            }
        }
        dic[word]=true;
        cin >> word;
        sword="";
        for(int i=0; word[i]; i++)
        {
            if(!dic[sword]||dic[sword+word[i] ])
                sword+=word[i];
            else
            {
                cout << sword+" ";
                sword=word[i];
               //cout << sword << endl << endl;
            }
        }
        cout << sword << endl;
    }
    return 0;
}

#include <cstdio>
#include <map>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int cases,total,c=0;
    scanf("%d",&cases);
    string s;
    getchar();
    while(c<=cases){
        total=0;
        c++;
        map<string,int> m;
        getline(cin,s);
        while(s.compare("")!=0){
            m[s] += 1;
            getline(cin,s);
            //cout << "s:"<<s<<"|"<<endl;
            total++;
        }
        bool check=false;;
        for(auto it = m.begin() ;it!=m.end() ; it++){
            check = true;
            printf("%s %.4f\n",it->first.c_str(),(double)(it->second)/total*100);
        }
        if(check && c<=cases)printf("\n");
    }

    return 0;
}

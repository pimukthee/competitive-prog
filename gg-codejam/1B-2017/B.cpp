#include <iostream>
#include <string>
#include <map>
#include <cstdio>

using namespace std;
string rep[6] = {"R", "O", "Y", "G", "B", "V"};
map <char,int> m;

string backtrack(string s,int num[]){
    //R, O, Y, G, B, V
    string res="IMPOSSIBLE";
   // cout << s <<endl;
    int temp=0;
    for(int i=0;i<6;i++) temp += num[i];
   // cout << s.length() <<endl ;
    if(s==""){
        cout << "x";
        for(int i=0;i<6;i++){
            if(num[i]>0){
                num[i]--;
                res = backtrack(s+rep[i],num);
                num[i]++;
                if(res!="IMPOSSIBLE" && res.back()!=res.front())return res;
                else res = "IMPOSSIBLE";
            }
        }
    }
    else if(temp == 0){
        cout << "$";
        return s;
    }
    else{
        cout << "*";
        for(int i=2;i<5;i++){
            int pos = (m[s.back()]+i)%6;
            if(num[pos]>0){
                num[pos]--;
                res = backtrack(s+rep[pos],num);
                num[pos]++;
                if(res!="IMPOSSIBLE") return res;
            }
        }
    }
    return res;
}


int main(){
    //R, O, Y, G, B, V
    int N,T,c=0,num[6];
    cin >> T;
    m['R']=0;
    m['O']=1;
    m['Y']=2;
    m['G']=3;
    m['B']=4;
    m['V']=5;
    while(c++<T){
        cin >> N;
        for(int i=0;i<6;i++) cin >> num[i];
        string k = "";
        printf("Case #%d: ",c);
        cout << backtrack(k,num) <<endl;
    }
    return 0;
}

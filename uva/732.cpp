#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;
string s,s2;
int n;
char str[100005];
void kuy(string ss,string st,string b,string ans,int cnt,string target)
{
    if(cnt == n*2 && b.compare(s2)==0)
    {
        cout << ans << endl;
        return;
    }
    if(ss.size()>0)
        kuy(ss.substr(1,ss.size()-1),st+ss[0],b,ans+"i ",cnt+1,target);
    if(st.size()>0&&st.back()==target[0]&&target.size()>0)
        kuy(ss,st.substr(0,st.size()-1),b+st[st.size()-1],ans+(cnt==(n*2-1)?"o":"o "), cnt+1, target.substr(1,target.size()-1));
}
int main()
{
    while(scanf(" %s",str)>0)
    {
        s = string(str);
        cin >> s2;
        n = s.size();
        cout << "[\n";
        kuy(s,"","","",0,s2);
        cout << "]\n";
    }
    return 0;
}

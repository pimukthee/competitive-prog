#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector <char >ans;
string s1,s2;
void print(int i)
{
    for(char j='a' ; j<='z'; j++)
    {
        if(j!=s1[i] && j!=s2[i])
        {
            ans.push_back(j);
            return ;
        }
    }
}
int main()
{
    int n,t,diff=0,diff1,diff2;
    cin >> n >> t;
    cin >> s1 >> s2;
    for(int i=0; i<n; i++)
        if(s1[i]!=s2[i])
            diff++;
    diff1=diff2=diff;
    for(int i=0; i<n; i++)
    {
        if(t==diff1 && t==diff2 && s1[i]==s2[i])
            ans.push_back(s1[i]);
        else if(t>diff1 && t>diff2 &&s1[i]==s2[i])
        {
            t--;
            print(i);
        }
        else
        {
            if(t<diff1)
            {
                ans.push_back(s1[i]);
                if(s1[i]!=s2[i])
                diff1--;
            }
            else if(t<diff2)
            {
                ans.push_back(s2[i]);
                if(s1[i]!=s2[i])
                diff2--;
            }
            else
                print(i);
        }
    }
    if(diff1!=diff2)
        cout << -1;
    else
        for(int i=0;i<n; i++)
            cout << ans[i];
    return 0;
}

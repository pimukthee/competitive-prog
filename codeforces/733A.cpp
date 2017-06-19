#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <string>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pi pair<int,int>
using namespace std;
int main()
{
    int start = -1,ans = 0;
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
        {
            ans = max(ans,i-start);
            start = i;
        }
    }
    ans = max(ans,(int)s.size()-start);
    cout << ans;
    return 0;
}

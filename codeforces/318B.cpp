#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int si = s.length(),h=0;
    long long ans=0;
    for(int i=4; i<si; i++)
    {
        if(s[i]=='y' && s[i-1]=='v' && s[i-2]=='a' && s[i-3]=='e' && s[i-4]=='h')
            h++;
        else if(s[i]=='l' && s[i-1]=='a' && s[i-2]=='t' && s[i-3]=='e' && s[i-4]=='m')
            ans+=h;
    }
    cout << ans;
    return 0;
}

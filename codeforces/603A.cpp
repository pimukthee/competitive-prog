#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n,sum=1;
    string s;
    cin >> n >> s;
    for(int i=1; i<s.size(); i++)
        sum += (s[i]!=s[i-1]);
    cout << min(sum+2,n);
    return 0;
}

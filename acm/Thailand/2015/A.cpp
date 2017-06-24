#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map <string,int> ans;
int main()
{
    int i=1;
    string s="abcdefghi";
    do
    {
        ans[s]=i++;
    }while(next_permutation(s.begin(),s.end()));
    int T;
    cin >> T;
    while(T--)
    {
        cin >> s;
        cout << ans[s] << endl;
    }
    return 0;
}

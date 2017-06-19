#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int T,ans,temp,n,k;
    string s;
    cin >> T;
    while(T--)
    {
        cin >> n >> k;
        cin >> s;
        ans = 0;
        for(int i=k-1; i<n; i++)
        {
            temp=1;
            for(int j=i; j>=i-k+1; j--)
                temp*=s[j]-'0';
            ans=max(ans,temp);
        }
        cout << ans << endl;
    }
    return 0;
}

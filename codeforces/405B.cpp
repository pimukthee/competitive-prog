#include <cstdio>
#include <utility>
using namespace std;
char str[3005];
int main()
{
    int n,ans=0;
    scanf("%d %s",&n,str);
    pair <char,int> prev;
    prev.first = 'a';
    prev.second = -1;
    for(int i=0; i<n; i++)
    {
        if(str[i]!='.' && str[i]!= prev.first)
        {
            if(prev.first == 'a' && str[i]=='R')
                ans+=i;
            else if(prev.first=='R' && str[i]=='L' && (i-prev.second+1)&1)
                ans++;
            else if(prev.first=='L' && str[i]=='R')
                ans += i-prev.second-1;
            prev.first=str[i];
            prev.second=i;
        }
    }
    if(prev.first != 'R')
        ans+=n - prev.second -1;
    printf("%d",ans);
    return 0;
}

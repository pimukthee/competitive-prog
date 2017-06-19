#include <cstdio>
#include <algorithm>
using namespace std;
bool pok[125];
int poke[125];
char str[100005];
int main()
{
    int n,ans=200000,total=0,index=0;
    scanf("%d %s",&n,str);
    for(int i=0; i<n; i++)
    {
        char c = str[i];
        if(!pok[c])
            total++;
        pok[c]=true;
    }
    for(int i=0; i<=n; )
    {
        int cur=0;
        for(int j='a'; j<='z'; j++)
            if(poke[j])
                cur++;
        for(int j='A'; j<='Z'; j++)
            if(poke[j])
                cur++;
        if(cur==total)
        {
            ans=min(ans,i-index);
            poke[str[index]]--;
            index++;
        }
        else
        {
            poke[str[i]]++;
            i++;
        }
    }
    printf("%d",ans);
    return 0;
}

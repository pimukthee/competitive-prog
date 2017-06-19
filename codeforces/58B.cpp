#include <cstdio>
#include <vector>
using namespace std;
vector <int> p;
bool chk[1000010];
int main()
{
    int i;
    for(i=2; i<=1000000; i++)
    {
        if(!chk[i])
        {
            p.push_back(i);
            for(int j=i+i; j<=1000000; j+=i)
                chk[j]=true;
        }
    }
    int n;
    scanf("%d",&n);
    printf("%d ",n);
    while(n>1)
    {
        int s = p.size();
        for(i=0; i<s; i++)
        {
            if(n%p[i]==0)
            {
                n/=p[i];
                break;
            }
        }
        printf("%d ",n);
        if(i==s) break;
    }
    return 0;
}

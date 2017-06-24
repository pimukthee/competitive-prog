#include <cstdio>
bool chk[10000010];
int num[10000010];
int main()
{
    for(int i=2; i<=10000000; i++)
    {
        if(!chk[i])
        {
            for(int j=i+i; j<=10000000; j+=i)
                chk[j] = true;
        }
    }
    num[1]=num[2]=1;
    num[3]=2;
    for(int i=4; i<=10000000; i++)
    {
        num[i]=num[i-1];
        if(chk[i])
            num[i]++;
    }
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",num[n]);
    }
    return 0;
}
/*1 2 3 4 5 6 7 8 9 10
  1 1 2 3 3 4 4 5 6 7*/

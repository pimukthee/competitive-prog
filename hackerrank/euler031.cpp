#include <cstdio>
int coin[]={1,2,5,10,20,50,100,200};
int ans[100005]={1};
int main()
{
    int T;
    for(int i=0; i<8; i++)
        for(int j=coin[i]; j<=100000; j++)
        {
            ans[j]+=ans[j-coin[i]];
            ans[j]%=1000000007;
        }

    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        printf("%d\n",ans[N]);
    }
    return 0;
}

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
int time[3005];
int main()
{
    int sum,k;
    memset(time,-1,sizeof time);
    for(int i=1; i<=3000; i++)
    {
        for(int j=1; j<=3000; j++)
        {
            sum = i*i+j*j;
            k =sqrt(sum);
            if(k*k==sum&&i+j+k <=3000)
                time[i+j+k]= std::max(time[i+j+k],i*j*k);
        }
    }

    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        printf("%d\n",time[N]);
    }
    return 0;
}

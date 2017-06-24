#include <cstdio>
int main()
{
    int t;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        long long i;
        for(i=0; 3*(i+1)*(i+2)<=2*n; i++);
        n-=3*i*(i+1)/2;
        i++;
        //printf("%lld \n",n);
        if(n>2*i||n==0) printf("splash\n");
        else if(n>i) printf("%lld jum%s\n",i,i==1?"p":"ps");
        else printf("%lld dolphi%s\n",i,i==1?"n":"ns");

    }
    return 0;
}

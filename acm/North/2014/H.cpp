#include <cstdio>
#include <algorithm>
int a[105],b[105];
int main()
{
    char c;
    while(scanf("%d%c",&a[0],&c)!=EOF)
    {
        int n =1;
        if(c!='\n')
            while(scanf("%d%c",&a[n++],&c)&&c!='\n');
        for(int i=0; i<n; i++)
            scanf("%d",&b[i]);
        std::sort(a,a+n);
        std::sort(b,b+n);
        int ans = 1;
        for(int i=0; i<n; i++)
            if(a[i]>=b[i])
                ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}

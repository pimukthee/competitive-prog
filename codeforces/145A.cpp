#include <cstdio>
#include <algorithm>
using std::max;
char a[100005],b[100005];
int f,s;
int main()
{
    scanf("%s %s",a,b);
    for(int i=0; b[i]; i++)
    {
        if(b[i]=='4' && b[i]!=a[i])
            f++;
        else if(b[i]=='7' && b[i]!=a[i])
            s++;
    }
    printf("%d",max(f,s));
    return 0;
}

#include <cstdio>
int arr[250];
int main()
{
    int n,m;
    char c;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n*m; i++)
    {
        scanf(" %c",&c);
        arr[c]++;
    }
    if(arr['B']+arr['W']+arr['G']==n*m)
        printf("#Black&White");
    else
        printf("#Color");
    return 0;
}

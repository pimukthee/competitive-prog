#include <cstdio>
#include <cstring>
char str[5005];
int main()
{
    int s,prev=0,ans=0,left,right;
    scanf("%s",str+1);
    s = strlen(str+1);
    for(int i=4; i<=s; i++)
    {
        if(str[i]=='r' && str[i-1]=='a' && str[i-2]=='e' && str[i-3]=='b')
        {
            right = s-i+1;
            left = (i-3)-prev;
            ans+=left*right;
            prev = i-3;
        }
    }
    printf("%d",ans);
    return 0;
}

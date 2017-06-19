#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char str[1001];
int main()
{
    string ans="";
    int mult=0,time=1;
    bool dot=false,nz=false;
    scanf("%s",str);
    for(int i=strlen(str)-1; i>=0; i--)
    {
        if(str[i]=='e')
            break;
        mult+=(str[i]-'0')*time;
        time*=10;
    }
    for(int i=0; str[i]!='e'; i++)
    {
        if(mult==0&&dot)
            ans+=".";
        if(dot==true)
        {
            mult--;
            if(str[i]!='0'&&mult<0)
                nz=true;
        }
        if(str[i]!='.')
            ans+=str[i];
        else
            dot = true;
    }
    while(mult-->0) ans+="0";
    for(int i=0; i<ans.size(); i++)
    {
        if(!nz&&ans[i]=='.')
            break;
        else
            printf("%c",ans[i]);
    }
    return 0;
}

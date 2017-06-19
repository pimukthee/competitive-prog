#include <cstdio>
#include <cstring>
char str1[100005],str2[100005];
int main()
{
    scanf("%s %s",str1,str2);
    int len1 = strlen(str1),len2 = strlen(str2),f=0,s,c=0;
    if(len1!=len2)
        printf("NO");
    else
    {
        for(int i=0; i<len1; i++)
        {
            if(str1[i]!=str2[i])
            {
                if(f == 0)
                    f=i;
                else
                    s=i;
                c++;
            }
        }
        if(c!=2)
            printf("NO");
        else
            if(str1[f]==str2[s]&&str1[s]==str2[f])
                printf("YES");
            else
                printf("NO");
    }
    return 0;
}

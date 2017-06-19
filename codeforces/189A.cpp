#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
using namespace std;
int arr[10000],l[5],n;
int main()
{
    scanf("%d%d%d%d",&n,&l[0],&l[1],&l[2]);
    arr[0]=0;
    for(int i=0; i<=2; i++)
    {
        for(int j=l[i]; j<=n; j++)
            if(arr[j-l[i]]!=0 || j==l[i])
            arr[j]=std::max(arr[j-l[i]]+1,arr[j]);
    }
    printf("%d",arr[n]);
    return 0;
}

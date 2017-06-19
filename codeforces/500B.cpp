#include <cstdio>
#include <algorithm>
using namespace std;
int arr[305],k,temp[305],n;
char A[305][305];
bool visited[305];
void dfs(int i,int vis)
{
    if(!visited[arr[i]]) k=min(arr[i],k);
    temp[i]=vis;
    for(int j=0; j<n; j++)
        if(A[i][j]=='1' && temp[j]!=vis)
            dfs(j,vis);

}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    for(int i=0; i<n; i++)
        scanf(" %s",A[i]);
    for(int i=0; i<n; i++)
    {
        k = n;
        dfs(i,i+1);
        visited[k] = true;
        printf("%d ",k);
    }
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
bool path[30][30];
int node[30],deg[30],a[30],b[30];
bool isSafe(int k,int m)
{
    for(int i=1; i<=25; i++)
        if( path[k][i] && m == node[i])
            return false;
    return true;
}
bool colouring(int k,int m)
{
    bool chk=false;
    for(int i=1; i<=m; i++)
    {
        if(isSafe(k,i))
        {
            node[k]=i;
            if(k+1<=25 && chk!=true)
                chk |= colouring(k+1,m);
            else
                return true;
        }
    }
    node[k]=0;
    return chk;
}
int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i] >> b[i];
        deg[a[i]]++;
        deg[b[i]]++;
    }
    for(int i=1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            if(i!=j&&(a[i]==a[j] || a[i]==b[j] || b[i]==a[j] || b[i]==b[j]))
                path[i][j]=true;
    int k = *max_element(deg,deg+25);
    if(colouring(1,k))
        cout << k <<endl;
    else
        cout << k+1 << endl;
    return 0;
}

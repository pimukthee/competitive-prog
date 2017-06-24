#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
bool path[30][30];
int node[30],deg[30];
bool isSafe(int k,int m)
{
    for(int i=1; i<=20; i++)
        if( path[k][i] && m == node[i])
            return false;
    return true;
}
bool colouring(int k,int m)
{
    bool chk=false;
    //cout << k << endl;
    for(int i=1; i<=m; i++)
    {
        if(isSafe(k,i))
        {
            node[k]=i;
            if(k+1<=20 && chk!=true)
                chk = chk | colouring(k+1,m);
            else
                return true;
        }
    }
    return chk;
}
int main()
{
    int T;
    cin >> T;
    cin.ignore();
    while(T--)
    {
        string allint;
        getline(cin,allint);
        istringstream is(allint);
        int a,b;
        for(int i=0; i<=25; i++)
        {
            deg[i]=node[i]=0;
            for(int j=0; j<=25; j++)
                path[i][j]=false;
        }
        while(is>>a)
        {
            is >> b;
            //cout << a << " " << b << " ";
            deg[a]++;
            deg[b]++;
            path[a][b]=path[b][a]=true;
        }
       // cout << endl;

       int k =*max_element(deg,deg+25);
     //   cout << "MD = " << k <<endl;
      //  cout << colouring(1,k) << endl;
       // for(int i=1; i<=20; i++)
        //    cout << node[i] << " ";
        cout << ">= ";
        if(colouring(1,k))
                cout << k <<endl;
        else cout << k+1 << endl;
    }
    return 0;
}
/*1
2 3 2 4 2 14 3 4 3 6 4 9 5 6 5 7 5 17 6 7 7 12 8 9 8 10 8 11 9 10 10 21 11 12 11 13 12 13 13 24 14 15 14 16 15 16 15 20 16 19 17 18 17 19 18 19 18 23 20 21 20 22 21 22 22 25 23 24 23 25 24 25*/

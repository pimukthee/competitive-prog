#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;

const int TROPO_SIZE = 30;
int tropo[TROPO_SIZE];
int edge[TROPO_SIZE][TROPO_SIZE];
int cnt;
int c;
bool hasAns;
void dfs(vector <int> v)
{
    if(v.size()==cnt)
    {
        hasAns = true;
        for(int i=0; i<v.size()-1; i++)
            cout << char(v[i]+'A') << " ";
        cout << char(v.back()+'A');
        cout << endl;
    }
    else
    {
        for(int i = 0; i<=26; i++)
        {
            if(tropo[i]==0)
            {
                tropo[i]=-1;
                for(int j=0; j<=26; j++)
                {
                    if(edge[i][j]>0)
                        tropo[j]--;
                    edge[i][j]--;
                }
                v.push_back(i);
                dfs(v);
                v.pop_back();
                tropo[i]=0;
                for(int j=0; j<=26; j++)
                {
                    edge[i][j]++;
                    if(edge[i][j]>0)
                        tropo[j]++;
                }
            }
        }
    }
}
void parse_input()
{
    for(int i=0; i<TROPO_SIZE; i++)
    {
        tropo[i] = -1;
        for(int j=0; j<TROPO_SIZE; j++)
        {
            edge[i][j] = 0;
        }
    }
    scanf(" ");
    string line;
    getline(cin, line);
    stringstream in(line);
    char node;
    cnt=0;
    hasAns = false;
    while(in >> node)
    {
        //cout << int(node-'A') << endl;
        if(tropo[node-'A']==-1)
            cnt++;
        tropo[int(node-'A')] = 0;
    }

    getline(cin, line);
    stringstream in2(line);
    char connect[10];
    int f,t;
    while(in2 >> connect)
    {
        f = connect[0]-'A';
        t = connect[2]-'A';
        edge[f][t] = 1;
        tropo[t]++;
       // cout << f << " " << t << endl;
    }
    vector <int> v;
    if(c) cout << endl;
    c++;
    dfs(v);
    if(!hasAns)
        cout << "NO\n";
}

int main(int argc, const char * argv[])
{

    int TEST;
    cin >> TEST;
    while(TEST--)
    {
        //  int tropo[TROPO_SIZE]; // -1 not exsist, otherwise how many edge connect to them
        // int edge[TROPO_SIZE][TROPO_SIZE]; // adj edge
        parse_input();

        // Logic Here

    }
    return 0;
}

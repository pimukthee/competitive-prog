#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <string>
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
using namespace std;
int c[300];
int main()
{
    int n;
    string s;
    cin >> n >> s;
    for(char i:s)
        c[i]++;
    cout << max(c['x'],c['X'])-s.size()/2 << endl;
    for(char i: s)
    {
        if(c[i]>s.size()/2)
        {
            c[i]--;
            cout << (i=='x'?'X':'x');
        }
        else
            cout << i;
    }
    return 0;
}

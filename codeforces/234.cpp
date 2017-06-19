#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <fstream>
#include <sstream>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pi pair<int,int>
using namespace std;
pi a[1005];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        cin >> a[i].F;
        a[i].S = i+1;
    }
    sort(a,a+n);
    cout << a[n-k].F <<endl;
    for(int i=n-1; i>=n-k; i--)
        cout << a[i].S << " ";
    return 0;
}

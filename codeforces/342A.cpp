#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define sqr(x) x*x
#define LL long long
#define F first
#define S second
#define vi vector<int>
#define pi pair<int,int>
using namespace std;

int cs[8];

int main(){

    int n, x;

    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        cs[x]++;
    }
    n /= 3;

    if(cs[1] == n && cs[2] + cs[3] == n && cs[2] >= cs[4] && cs[4] + cs[6] == n && cs[6] >= cs[3]){
    while(cs[4]--)--cs[2],cout<<"1 2 4\n";
    while(cs[2]--)cout<<"1 2 6\n";
    while(cs[3]--)cout<<"1 3 6\n";
  }else cout<<"-1\n";
    return 0;
}

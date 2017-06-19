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
#define MAXN 100000
using namespace std;
vi p;
bool prime[MAXN];
int a,b;
int finddiv(int n)
{
    int j = sqrt(n),sum=0;
    for(int i=1; i<=j; i++)
    {
        if(n%i==0)
        {
            if(i>b)   sum++;
            if(n/i>b) sum++;
        }
    }
    if(j*j == n && j>b) sum--;
    return sum;
}
int main()
{
    cin >> a >> b;
    if(a<b)
        cout << "0";
    else if(a==b)
        cout << "infinity";
    else
        cout << finddiv(a-b);
    return 0;
}

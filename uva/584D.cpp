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
bool checkprime(int n)
{
    if(n==1) return false;
    if(n==0) return true;
    int j = sqrt(n);
    for(int i=2; i<=j; i++)
        if(n%i==0)
            return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    for(int i=n; i>=2; i--)
    {
        if(checkprime(i))
        {
            if(i==n)
            {
                cout << "1\n" << n;
                return 0;
            }
            for(int j=n-i;  j>=2; j--)
            {
                if(checkprime(j)&& checkprime(n-i-j))
                {
                    if(n-i-j!=0)
                    {
                        cout << "3\n" << i << " " << j << " " << n-i-j;
                        return 0;
                    }
                    else
                    {
                        cout << "2\n" << i << " " << j;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

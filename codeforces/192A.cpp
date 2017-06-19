#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
using namespace std;
vector <long long> arr;
int main()
{
    long long n;
    cin >> n;
    arr.pb(0);
    for(int i=1; arr.back()<n; i++)
        arr.pb(arr.back()+1ll*i);
    for(int i=arr.size()-1; i>0; i--)
    {
        if(n-arr[i]>0&&binary_search(arr.begin(),arr.end(),n-arr[i]))
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}

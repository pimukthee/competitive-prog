#include <iostream>
#include <algorithm>
using namespace std;
int a[15];
int main()
{
    int n ,div = 1000000000;
    cin >> n;
    for (int i = 1; i <= 9; i++)
    {
        cin >> a[i];
        div = min(div, a[i]);
    }
    int len = n / div;
    if (len == 0)
        cout << -1;
    else
    {
        for(; len>=0; len--)
        {
            for(int i=9; i>=1; i--)
            {
                if(n>=a[i] && (n-a[i])/div == len)
                {
                    cout << i;
                    n-=a[i];
                    break;
                }
            }
        }
    }
}

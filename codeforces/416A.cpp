#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    char ans;
    bool imp=false;
    int n;
    long long left=-2000000000,right=2000000000,x;
    cin >> n;
    while(n--)
    {
        cin >> s >> x >> ans;
        if(s==">")
        {
            if(ans=='Y')
                left = max(left,x+1);
            else
                right = min(x,right);
        }
        else if(s=="<")
        {
            if(ans=='Y')
                right = min(right,x-1);
            else
                left = max(left,x);
        }
        else if(s==">=")
        {
            if(ans=='Y')
                left = max(x,left);
            else
                right = min(right,x-1);
        }
        else
        {
            if(ans=='Y')
                right = min(x,right);
            else
                left = max(left,x+1);
        }
        if(left>right)
            imp=true;
    }
    if(imp)
        cout << "Impossible";
    else
        cout << (left+right)/2;
    return 0;
}

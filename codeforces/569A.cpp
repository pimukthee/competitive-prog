#include <iostream>
using namespace std;
int main()
{
    int t,s,q,a;
    cin>>t>>s>>q;
    for(; s<t; s*=q,a++);
    cout<<a;
    return 0;
}

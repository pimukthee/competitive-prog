#include <iostream>
using namespace std;
int main()
{
    int m,cur=0,i;
    cin >> m;
    for(i= 5; cur < m; i+=5)
    {
        int zero=0,k=i;
        while(k>0)
        {
            zero+=k/5;
            k/=5;
        }
        cur = zero;
   //     cout << cur << endl;
    }
    if(cur!=m)
        cout << 0 ;
    else
    {
        cout << 5 << endl;
        for(int k=i-5; k<i; k++)
            cout << k << " ";
    }
    return 0;
}

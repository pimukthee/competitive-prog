#include <iostream>
#include <cstdio>
using namespace std;
long long temp,table[5][500000],num,diff;
int w,h;
void assign(int in,int i,int pos)
{
    if(in)
    {
        if(!(i&1))
        {
            table[pos][i] = temp;
            temp += diff;
        }
        else table[pos][i] = 0;
    }
    else
    {
        if((i&1))
        {
            table[pos][i] = temp;
            temp += diff;
        }
        else table[pos][i] = 0 ;
    }
}
void debug()
{
    for(int i=0; i<=w+1; i++)
        cout << table[1][i] << " ";
    cout << endl;
    for(int i=0; i<=w+1; i++)
        cout << table[2][i] << " ";
    cout << endl;
    for(int i=0; i<=w+1; i++)
        cout << table[3][i] << " ";
    cout << endl;
}
int main()
{
    int T;
    long long sum = 0,cur = 1;
    int k[5],in,row;
    cin >> T;
    while(T--)
    {
        cin >>  num >>  diff >>  h >> w;
        for(int i=0; i<=w+1; i++)
        {
            table[1][i]=table[2][i]=table[3][i]=-1;
        }
        in = row =0;
        cur = 1;
        k[0] = (w+1)>>1;
        k[1] = k[0]-(w&1);
        while(cur <= num)
        {
            row ++;
            cur += k[in]*diff;
            in^=1;
        }
        in ^= 1;
        cur -= diff;
        cur -= (k[in]-1)*diff;

        temp = cur;
        //middle
        for(int i=1; i<=w; i++)
            assign(in,i,2);
        //top
        temp = cur - (k[in^1])*diff;
        if(row>1)
            for(int i=1; i<=w; i++)
                assign(in^1,i,1);
        //down
        temp = cur +k [in]*diff;
        if(row<h)
            for(int i=1; i<=w; i++)
                assign(in^1,i,3);

        //debug();
        for(int i=1; i<=w; i++)
        {
            if(table[2][i]==num)
            {
                printf("%lld\n%lld\n%lld\n%lld\n",table[1][i-1],table[1][i+1],table[3][i-1],table[3][i+1]);
            }
        }
    }
    return 0;
}

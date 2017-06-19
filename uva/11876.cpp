#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> prime,seq;
int ANS[1000005];
bool notprime[1000005],chk[1000005];
int NOD(int N)
{
    int i=0,PF = prime[0],ans=1;
    while(PF* PF <= N)
    {
        int power = 0;
        while(N%PF==0)
        {
            N/=PF;
            power++;
        }
        ans *= power+1;
        PF = prime[++i];
    }
    if(N!=1) ans*=2;
    return ans;
}
int main()
{
    int T,A,B;
    for(int i=2; i<=1000000; i++)
    {
        if(!notprime[i])
        {
            prime.push_back(i);
            for(int j=i+i; j<=1000000; j+=i)
                notprime[j]=true;
        }
    }
    seq.push_back(1);
    chk[1]=true;
    for(int i=1; seq.back()<=1000000; i++)
    {
        seq.push_back(seq[i-1]+NOD(seq[i-1]));
        chk[seq.back()]=true;
    }

    for(int i=0; i<=1000000; i++)
    {
        ANS[i]=ANS[i-1];
        if(chk[i])
            ANS[i]++;
    }
    scanf("%d",&T);
    for(int c=1; c<=T; c++)
    {
        scanf("%d%d",&A,&B);
        printf("Case %d: %d\n",c,ANS[B]-ANS[A-1]);
    }
    return 0;
}

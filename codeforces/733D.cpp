#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pi pair<int,int>
using namespace std;
struct cube
{
    int s[5],in;
    bool operator <(const cube& w) const
    {
        if(s[0]!=s[0]) return s[0]<w.s[0];
        else if(s[1]!=w.s[1]) return s[1]<w.s[1];
        else return s[2]<w.s[2];
    }
}rec[100005];
pair <double,pi> ans;
bool check(int i,int aa,int bb, int cc)
{
    double r = 1.0*min(aa,min(bb,cc))/2.0;
    if(r > ans.F)
    {
        ans.F = r;
        ans.S.F = rec[i].in;
        ans.S.S = rec[i+1].in;
        return true;
    }
    return false;
}
int bsearch()
{
    int mid,l,r;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(rec[mid].s[index]==rec[i].s[index])
            a
    }
}
int main()
{
    int n,num;
    int aa,bb,cc;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d",&aa,&bb,&cc);
        rec[i].s[0] = min(aa,min(bb,cc));
        rec[i].s[2] = max(aa,max(bb,cc));
        rec[i].s[1] = min(max(aa,bb),min(max(aa,cc),max(bb,cc)));
        rec[i].in = i+1;
    }
    sort(rec,rec+n);
    for(int i=0; i<n; i++)
    {
        printf("%d %d %d\n",rec[i].s[0],rec[i].s[1],rec[i].s[2]);
        double r = (1.0*min(rec[i].s[0],min(rec[i].s[1],rec[i].s[2])))/2.0;
        if(r > ans.F)
        {
            num = 1;
            ans.F = r;
            ans.S.F = rec[i].in;
        }
        bool chk = true;
        while(chk)
        {
            chk = false;
            if(rec[i].s[0]==rec[i+1].s[0]&&rec[i].s[1]==rec[i+1].s[1])
               chk = check(i,rec[i].s[0],rec[i].s[1],rec[i].s[2]+rec[i+1].s[2]);
            if(rec[i].s[0] == rec[i+1].s[0] && rec[i].s[2] == rec[i+1].s[2]);
                chk = check(i,rec[i].s[0],rec[i].s[2],rec[i].s[1]+rec[i+1].s[1]);
            if(rec[i].s[1] == rec[i+1].s[1] && rec[i].s[2] == rec[i+1].s[2]);
                chk = check(i,rec[i].s[1],rec[i].s[2],rec[i].s[0]+rec[i+1].s[0]);
            /*if(rec[i].a==rec[i+1].a&&rec[i].b==rec[i+1].c)
                chk = check(i,rec[i].a,rec[i].b,rec[i].c+rec[i+1].b);
            if(rec[i].a==rec[i+1].a&&rec[i].c==rec[i+1].b)
                chk = check(i,rec[i].a,rec[i].c,rec[i].b+rec[i+1].c);
            if(rec[i].a==rec[i+1].a&&rec[i].c==rec[i+1].c)
                chk = check(i,rec[i].a,rec[i].c,rec[i].b+rec[i+1].b);*/
        }

    }
    printf("%d\n",num);
    //cout << ans.F << endl;
    printf("%d",ans.S.F);
    if(num==2)
        printf(" %d",ans.S.S);
    return 0;
}

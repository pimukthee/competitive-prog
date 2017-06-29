#include <bits/stdc++.h>

using namespace std;

vector <int> seq;
int app[300005],last[300005];

int main() {
    int n,ans=0,q,t,x,cur=0;
    scanf("%d%d",&n,&q);
    while(q--) {
        scanf("%d%d",&t,&x);
        if(t==1) {
            seq.push_back(x);
            app[x]++;
            ans++;
        }
        else if(t==2) {
            ans-=app[x];
            last[x]=seq.size();
            app[x]=0;
        }
        else {
            for(; cur<=x-1; cur++)
            {
                if(cur >= last[seq[cur]])
                {
                    ans--;
                    app[seq[cur]]=max(0,app[seq[cur]]-1);
                }
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
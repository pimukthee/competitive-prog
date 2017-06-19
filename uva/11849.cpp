#include <cstdio>
#include <set>
using namespace std;
int main(){
    int t,n,m;
    scanf("%d %d",&n,&m);
    while(!(n==0 && m == 0)){
        set<int> s;
        for(int i=0;i<n;i++){
            scanf("%d",&t);
            s.insert(t);
        }
        int ans=0;
        for(int i=0;i<m;i++){
            scanf("%d",&t);
            if(s.find(t)!=s.end())
                ans++;
        }
        printf("%d\n",ans);
        scanf("%d %d",&n,&m);
    }
    return 0;
}

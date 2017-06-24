#include <cstdio>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
stack <pair<int,int> > st;
int l[100005],r[100005],a[100005],water[100005];
int CalculateWater(int i)
{
    int sum;
    if(water[i]!=-1)
        return water[i];
    int lt = l[i],rt = r[i];
    if(lt==-1 || rt == -1)
        return 0;
    else
    {
        int x;
        sum = (rt-lt)*(min(a[rt],a[lt])-a[i]);
        if(a[rt]<a[lt])
            x = rt;
        else
            x = lt;
        sum+=CalculateWater(x);
    }
    return water[i]=sum;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            l[i]=r[i]=water[i]=-1;
        }

        st.push(make_pair(1000000,-1));
        for(int i=0; i<n; i++)
        {
            while(st.top().first <= a[i])
                st.pop();
            l[i] = st.top().second;
            st.push(make_pair(a[i],i));
        }
        while(!st.empty()) st.pop();
        st.push(make_pair(1000000,-1));
        for(int i=n-1; i>=0; i--)
        {
            while(st.top().first <= a[i])
                st.pop();
            r[i] = st.top().second;
            st.push(make_pair(a[i],i));
        }
        while(!st.empty()) st.pop();
        int ans=0,x;
        for(int i=0; i<n; i++)
            ans = max(ans,a[i]+CalculateWater(i));
        printf("%d\n",ans);
    }
    return 0;
}
/*1
10
3 4 2 3 5 2 1 4 3 2*/

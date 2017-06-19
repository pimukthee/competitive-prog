#include <iostream>
#include <vector>
using namespace std;
vector <pair<int,int> > ans;
int main()
{
    int x,y,a,b;
    cin >> x >> y >> a >> b;
    for(int i=a; i<=x; i++)
        for(int j=b; j<=y; j++)
            if(i>j)
                ans.push_back(make_pair(i,j));
    int s = ans.size();
    cout << s <<  endl;
    for(int i=0; i<s; i++)
        cout << ans[i].first<< " " <<ans[i].second << endl;
    return 0;
}

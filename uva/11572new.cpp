#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
	int t,ans,n,x,l;
	cin>>n;
	while(n--){
		cin>>t;
		l = ans = 0;
		map<int,int> m;
		for(int i=1;i<=t;i++){
			cin >> x;
			if(m.find(x)!=m.end()){
				l = max(l,m[x]);
			}
			ans = max(i-l,ans);
			m[x] = i;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}

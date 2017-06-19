#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>
#include <map>
using namespace std;
int main(){
	int n,d,x;
	long long ans;
	cin>>n;
	while(n>0){
		priority_queue<int> gpq;
		priority_queue<int , vector<int> , greater<int> > lpq;
		map<int,int> m;
		ans = 0;
		for(int j=0;j<n;j++){
			cin >> d;
			for(int i=0;i<d;i++){
				cin>>x;
				gpq.push(x);
				lpq.push(x);
				if(m[x]) m[x]++;
				else m[x]=1;
			}
			while(m[gpq.top()]<=0) gpq.pop();
			while(m[lpq.top()]<=0) lpq.pop();
			ans+=gpq.top()-lpq.top();
			m[gpq.top()]--;
			m[lpq.top()]--;
			gpq.pop(); lpq.pop();
			
		}
		cin>>n;
		cout<<ans<<"\n";	
	}
	return 0;
}

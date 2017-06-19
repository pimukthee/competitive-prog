#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(){
	int a,b,n,x;
	cin>>n;
	while(n!=0){
		priority_queue<int, vector<int> ,greater<int> > pq;
		for(int i=0;i<n;i++){
			cin>>x;
			pq.push(x);
		}
		long long ans = 0,t;
		while(pq.size()>1){
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			ans+=a+b;
			pq.push(a+b);
		}
		cout<<ans<<endl;
		cin>>n;
	}
}

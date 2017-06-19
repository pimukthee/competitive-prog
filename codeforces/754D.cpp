#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
struct A{
	int l,r,i;
	bool operator <(const A &other)const{
		if(l!=other.l) return l<other.l;
		else return r<other.r;
	}
}p[300010];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>p[i].l>>p[i].r;
		p[i].i=i+1;
	}
	sort(p,p+n);
	priority_queue<int, vector<int>, greater<int> > pq;
	int j=0,ans=0,pos;
	for(int i=0;i<n;i++){
		if(j<k){
			pq.push(p[i].r);	
			j++;
		}
		if(j==k){
			if(pq.top() - p[i].l+1 > ans ){
				ans = pq.top()-p[i].l + 1;
				pos = i; 
			}
			pq.pop();
			j--;
		}
	}
	int maxl = p[pos].l;	
	if(ans){
		cout<<ans<<endl;
		for(int i=0;i<k;pos--){
			if(p[pos].r >= ans + maxl - 1 ){
				cout<<p[pos].i<<" ";
				i++;
			}
		}
	}
	else{
		cout<<"0"<<endl;
		for(int i=0;i<k;i++){
			cout<<p[i].i<<" ";
		}
	}
	return 0;
}

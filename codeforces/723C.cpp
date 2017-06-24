#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int main(){
	int n,m,b[2010],t,exceed=0;
	cin >> n >> m;
	memset(b,0,2010);	
	for(int i=0;i<n;i++){
		cin >> t;	
		if( t<=m) b[t]++;
		else exceed ++;
	}
	int ix,iy;
	auto comp = [] (pair<int,int> &a , pair<int,int> &b ) -> bool {return a.second > b.second; }; 
	priority_queue< pair<int ,int> , vector<pair<int,int> >, decltype(comp) > pq (comp);
	for(int i=1;i<=m;i++)
		pq.push( make_pair(i,b[i]) );
	
	//while(!pq.empty()){
	//	cout << pq.top().first<<" "<<pq.top().second<<endl;
	//	pq.pop();
	//}
	int at,p,count=0,mx=-1;
	cout << "begin" <<endl;
	while(!pq.empty() && exceed>0){
		at = pq.top().first;
		pq.pop();
		p = b[pq.top().first] - b[at];
		if(p==0) p=1;		
		b[at] += exceed < p ? 0 : p;
		exceed -= p;
		pq.push( make_pair(at,b[at]) );
		count+=p;
		mx = max(mx,b[at]);
		
	}
	cout << mx << " " << count << endl;
	for(int i=1;i<=n;i++)
		cout<< b[i] << " ";
	cout<< endl;
	
	return 0;

}

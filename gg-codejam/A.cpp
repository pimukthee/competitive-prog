#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstdio>
#include <vector>
#include <cmath>
#define mp make_pair
typedef pair<int,int> pii;

using namespace std;


int main(){
	int t=0,T,r,h;
	cin >> T;
	while(t++<T){
		cin >> n >> k;
		double ans =0;
		priority_queue<pii> pq;
		for(int i=0;i<n;i++){
			cin >> r >> h;
			pq.push(mp(r,h));
		}
		vector<pii> v;
		while(!pq.empty()){
			double ah = 2.0*M_PI*pq.top().first;
			double aw = M_PI*pow(pq.top().second,2);
			if(v.empty()){
				v.push_back(pq.top());	
				ans = aw + ah;
			}
			else if(v.size()<k){
				v.push_back(pq.top());	
				ans += ah;
			}
			else{
				double loss = 9999999999999999;
				int index=-1;
				for(int j=0;j<v.size()-1;j++){
					double bh = 2.0*M_PI*v[j].first;
					if(loss>bh){
						loss = bh;
						index = j;	
					}	
				}	
				double bh = 2.0*M_PI*v.back().first;
				double bw = M_PI*pow(v.back().second,2);
				if(loss>bh+bw){
					loss = = bh+bw;
					index = v.size()-1;
				}
				if(v.size()==1 && loss < ah+aw){
					v[0] = pq.top();
					ans = ah+aw;
				}
				else if(loss < ah){
					v.erase(v.begin()+index);
					v.push_back(pq.top());
					ans = ans - loss + ah;
				}
			}
			printf("Case #%d: %lf",t,ans);
		}
	}
	return 0;
}

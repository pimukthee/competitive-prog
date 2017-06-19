#include <iostream>
#include <algorithm>
#include <utility>
#include <cstddef>
#include <cfloat>
#include <queue>
#include <cstdio>
#include <vector>
#define mp make_pair
#include <cmath>
//#define M_PI 3.141592653589793238462643383279502884L /* pi */
//#define M_PI 3.14159265358979323846
using namespace std;
typedef pair<int,int> pii;




int main(){
	int t=0,T,r,h,k,n;
	cin >> T;
	while(t++<T){
		cin >> n >> k;
		long double ans =0L;
		priority_queue<pii> pq;
		for(int i=0;i<n;i++){
			cin >> r >> h;
			pq.push(mp(r,h));
		}
		vector<pii> v;
		while(!pq.empty()){
			long double ah = 2.0L*M_PI*pq.top().first*pq.top().second;
			long double aw = M_PI*pq.top().first*pq.top().first;
			if(v.empty()){
				v.push_back(pq.top());	
				ans = aw + ah;
			}
			else if(v.size()<k){
				v.push_back(pq.top());	
				ans += ah;
			}
			else{
				long double loss = LDBL_MAX;
				int index=-1;
				if(v.size()>1){
					long double b = 2.0L*M_PI*v[0].first*v[0].second;
					long double c = M_PI*(v[0].first*v[0].first - v[1].first*v[1].first);
					if(loss>b+c){
						loss = b+c;
						index = 0;	
					}
				}
				for(int j=1;j<v.size();j++){
					long double bh = 2.0L*M_PI*v[j].first*v[j].second;
					if(loss>bh){
						loss = bh;
						index = j;	
					}	
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
			pq.pop();
		}
		printf("Case #%d: %.9f\n",t,(double)ans);
	}
	return 0;
}

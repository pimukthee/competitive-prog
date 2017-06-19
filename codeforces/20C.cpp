#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <functional>
#define mp make_pair
#define pb push_back
#define INF 10000000000000
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef priority_queue<ii, vector<ii>, greater<ii> > p_q;

int n,m,s,t,x;
vector<ii> adj[100001];
bool visit[100001];
long long w[100001];

int dijkstra(int s){
	p_q pq;
	w[s] = 0;
	pq.push(ii(0,s));	
	while(!pq.empty()){
		ii tmp = pq.top();
		pq.pop();
		if(visit[tmp.second]) continue; 
		visit[tmp.second] = true;
		for(ii e : adj[tmp.second]){
			if(w[e.first]>e.second+w[tmp.second]){
				w[e.first] = e.second+w[tmp.second];
				pq.push(ii(w[e.first],e.first));			
			}
		}
	}
}

vi backtrack(int n){
	vi ans;
	int present=n;

	while(w[n]!=INF){
		ans.pb(present);
		if(present == 1) break;
		for(ii e : adj[present]){
			if(w[present] - e.second == w[e.first] ){	
				present = e.first;
				break;
			}
		}
	}
	return ans;
}

int main(){

	for(int i=0;i<100001;i++) w[i]=INF;
	for(int i=0;i<100001;i++) visit[i] = false;	
	
	cin >> n >> m;

	for(int i=0;i<m;i++){
		scanf("%d %d %d",&s,&t,&x);
		adj[s].pb(ii(t,x));
		adj[t].pb(ii(s,x));	
	}	
	
	dijkstra(1);

	vi ans = backtrack(n);

	if(w[n]==INF) cout << -1;
	else
		for(int i = ans.size()-1 ; i>=0 ;i--)
			cout << ans[i] << ' ';
}

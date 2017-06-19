#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2000000000; 
using namespace std;
typedef pair<int,int> ii;
int T,n,m,a,b,c;
bool mark[110*100];
pair<int,ii> edge[110*110];
vector<int> e;
typedef vector<int> vi;

class UnionFind {
	private: vi p, rank;
	public:
		UnionFind(int N) { 
			N+=10;
			rank.assign(N, 0);
			p.assign(N, 0); 
			for (int i = 0; i < N; i++) 
				p[i] = i;
		}
		int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
		bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
		bool unionSet(int i, int j) {
			if (!isSameSet(i, j)) {
				int x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y]) p[y] = x;
				else {
					p[x] = y; 
					if (rank[x] == rank[y]) rank[y]++; 
				}
				return true;
			}
			return false;
		}
};

int MST(bool p){
	int count=0,ans=0;
	UnionFind s(110*110);
	for(int i=0;i<m;i++){
		if( mark[i] ) continue;
		if( s.unionSet(edge[i].second.first,edge[i].second.second) ){
			ans += edge[i].first;
			if(!p) e.push_back(i);
			count++;
		}
		if(count==n-1) return ans; 
	}
	return INF;
}


int main(){
	cin>>T;
	while(T--){
		e.clear();
		cin >> n >> m;
		for(int i=0;i<110*110+10;i++) mark[i] = false;
		for(int i=0;i<m;i++){
			cin >> a >> b >> c;
			edge[i] = pair<int,ii>(c,ii(a,b));
		}
		sort(edge,edge+m);	
		int ans1,ans2=INF;
		ans1 = MST(false);		
			
		for(int i=0;i<e.size();i++){
			mark[e[i]] = true;	
			int x =  MST(true);
			ans2 = min(ans2,x);
			mark[e[i]] = false;
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}

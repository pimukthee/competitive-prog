#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
bool mark[60][60];
int n;
typedef pair<int,int> ii;
vector<ii> adj[60];

bool dfs(stack<ii> st,int node){
	bool chk = false;
	if(adj[node].size()%2==1) return false;
	for(int i=0;i<adj[node].size();i++){
		
		st.push( ii(node,adj[node][i].second) );
		mark[node][adj[node][i]] = true;
		mark[adj[node][i]][node] = true;
		return dfs(st,adj[node][i]);
		chk = true;
	}
	if(!chk){
		while(!st.empty()){
			printf("%d %d\n",st.top().first,st.top().second);
			st.pop();
			return true;
		}
	}

}


int main(){
	int T,a,b,c=1;
	scanf("%d",&T);
	while(T--){
		
		for(int i=0;i<60;i++)
			for(int j=0;j<60;j++)
				mark[i][j] = false;
	
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d %d",&a,&b);
			adj[a].push_back(ii(b,1));
			adj[b].push_back(ii(a,1));
		}
		stack<int> st;
		printf("Case #%d\n",c++);
		if(! dfs(st , a)) printf("some beads may be lost\n");	
		printf("\n");
	}
}
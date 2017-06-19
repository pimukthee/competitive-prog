#include <cstdio>
#include <queue>
#include <utilty>
#define obs -1
#define INF 9999999

using namespace std;

struct vertex{
	pair<int,int> left,right,up,down; 
	int w;
}map[1010][1010];
int n,t;

int main(){
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++) map[i][0].w=map[0][i].w=map[n+1][i].w=map[i][n+1].w=INF;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&t);
			if(t==0) map[i][j]=INF;
			else map[i][j]=obs;
		}
	}
	pair<int,int> left,right;
	bool isLeft=true;
	for(int i=1;i<=n;i++){
		left = make_pair(i,1);
		
		for(int j=1;j<=n;j++){
			if(map[i][j].w==INF) 
		}
	}
	

	while(true){
		
		
	}
	printf("%d\n",map[n][n].w);
}

#include <cstdio>
#include <queue>
#include <utility>
#define obs -1
#define ice 9999999
using namespace std;

struct vertex{
	int w;
	pair<int,int> left,right,down,up;
}map[1010][1010];

int n,w;
queue <pair <pair<int,int>, int> > q;

bool canMove(int r,int c,int w,int d){
	if(w<map[r][c].w) return true;
	return false;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&map[i][j].w);
		}
	}
	for(int i=0;i<=n+1;i++) map[i][0].w=map[0][i].w=map[n+1][i].w=map[i][n+1].w=obs;			
	for(int i=1;i<=n;i++){
		for( int j=1;j<=n;j++){
			if(map[i][j].w==0) map[i][j].w=ice;
			else map[i][j].w=obs; 
		}
	}	
	pair<int,int> left,right,up,down;
	for(int i=1;i<=n;i++){
		left=make_pair(i,1);
		for(int j=1;j<=n;j++){
			if(map[i][j].w==ice){
				map[i][j].left=left;
			}
			else{
				left=make_pair(i,j+1);
			}
		}
	}

	for(int i=1;i<=n;i++){
		right=make_pair(i,n);
		for(int j=n;j>=1;j--){
			if(map[i][j].w==ice){
				map[i][j].right=right;
			}
			else{
				right=make_pair(i,j-1);
			}
		}
	}

	for(int j=1;j<=n;j++){
		up=make_pair(1,j);
		for(int i=1;i<=n;i++){
			if(map[i][j].w==ice){
				map[i][j].up=up;
			}
			else{
				up=make_pair(i+1,j);
			}
		}
	}

	for(int j=1;j<=n;j++){
		down = make_pair(n,j);
		for(int i=n;i>=0;i--){
			if(map[i][j].w==ice){
				map[i][j].down=down;
			}
			else{
				down=make_pair(i-1,j);
			}
		}
	}
	q.push(make_pair(make_pair(1,1),0));
	int r,c,w;
	while(!q.empty()){
	//	printf("|%ld|",q.size());
		r = q.front().first.first;
		c = q.front().first.second;
		w = q.front().second;
		q.pop();
		if(w<map[r][c].w){
			map[r][c].w = w;
			q.push(make_pair(map[r][c].left,w+c-map[r][c].left.second));
			q.push(make_pair(map[r][c].right,w-c+map[r][c].right.second));
			q.push(make_pair(map[r][c].up,w+r-map[r][c].up.first));
			q.push(make_pair(map[r][c].down,w-r+map[r][c].down.first));
		}
	}

	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		printf("%d ",map[i][j].w);
	// 	}
	// 	printf("\n");
	// }

	// for(int i=1;i<=n;i++){
	// 	printf("%d %d\n",map[i][3].down.first,map[i][3].down.second);
	// }
	printf("%d\n",map[n][n].w);
}

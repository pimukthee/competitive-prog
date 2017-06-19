#include <cstdio>
#define obs -1
#define ice 9999999
int n,map[1010][1010],dir[1010][1010];

bool canMove(int r,int c,int w,int d){
	if(w<map[r][c]) return true;
	else if(w==map[r][c]){
		if( (dir[r][c]&(1<<d))==0 ) return true;
	}	
	return false;
}

void depth(int r,int c,int w,int d){
// d | 0 right | 1 left | 2 up | 3 down
	map[r][c]=w ;
	dir[r][c]= dir[r][c]|(1<<d);
	if(r==n && c==n) {
		return ;
	}
	if(d==0){
		if(canMove(r,c+1,w+1,d)){
			while(map[r][c+1]!=obs)	map[r][++c] = ++w;
		}
		if(map[r][c+1]==obs && !(r==n && c==n)){
			if(canMove(r+1,c,w+1,3)) depth(r+1,c,w+1,3);
			if(canMove(r-1,c,w+1,2)) depth(r-1,c,w+1,2);
		}
	}
	else if(d==1){
		if(canMove(r,c-1,w+1,d)){
			while(map[r][c-1]!=obs) map[r][--c] = ++w;		
		} 
		if(map[r][c-1]==obs && !(r==n && c==n)){
			if(canMove(r+1,c,w+1,3)) depth(r+1,c,w+1,3);
			if(canMove(r-1,c,w+1,2)) depth(r-1,c,w+1,2);
		}
	}
	else if(d==2){
		if(canMove(r-1,c,w+1,d)){
			while(map[r-1][c]!=obs) map[--r][c]=++w;
		}
		if(map[r-1][c]==obs  && !(r==n && c==n)){
			if(canMove(r,c-1,w+1,1)) depth(r,c-1,w+1,1);
			if(canMove(r,c+1,w+1,0)) depth(r,c+1,w+1,0);
		}
	}		
	else{
		if(canMove(r+1,c,w+1,d)){
			while(map[r+1][c]!=obs) map[++r][c]=++w; 
		}
		if(map[r+1][c]==obs && !(r==n && c==n)){
			if(canMove(r,c-1,w+1,1)) depth(r,c-1,w+1,1);
			if(canMove(r,c+1,w+1,0)) depth(r,c+1,w+1,0);
		}
	}
}

int main(){

	scanf("%d",&n);
	for(int i=0;i<=n+1;i++) map[i][0]=map[n+1][i]=map[i][n+1]=map[0][i]=obs;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==1) map[i][j]=obs;
			else map[i][j]=ice;
		}
	}
	
	if(map[1][2] == ice)
		depth(1,1,0,0);
	if(map[2][1] == ice)
		depth(1,1,0,3);
	printf("%d\n",map[n][n]);
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++)
			printf("%d ",map[i][j]);
		printf("\n");
	}
	return 0;
}

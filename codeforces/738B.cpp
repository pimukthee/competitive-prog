#include <cstdio>
int n,m,tb[1010][1010];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&tb[i][j]);
		}
	int sum=0,right=0,left=0;
	for(int i=1;i<=n;i++){
		left = 0,right=0;
		for(int j=1;j<=m;j++){
			if(tb[i][j]==1){
				sum+=right+right*left;
				right = 0;
				left = 1;
			}
			else right++;
		}
		sum+= right*left;
	}
	for(int i=1;i<=m;i++){
		left = 0,right=0;
		for(int j=1;j<=n;j++){
			if(tb[j][i]==1){
				sum+=right+right*left;
				right = 0;
				left = 1;
			}
			else right++;
		}
		sum+= right*left;
	}
	printf("%d\n",sum);
	return 0;
}

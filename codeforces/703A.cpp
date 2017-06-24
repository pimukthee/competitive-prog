#include <cstdio>

int main(){
	int n,a,b,x,y;
	scanf("%d",&n);
	a=b=0;
	for(int i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		if(x>y) a++;
		else if(y>x) b++;
	}
	if(a==b) printf("Friendship is magic!^^");
	else if(a>b) printf("Mishka");
	else printf("Chris");
}

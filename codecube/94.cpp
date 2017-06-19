#include <cstdio>

int main(){
	int n;
	char a,b;
	bool isAcc=true;
	scanf("%d",&n);
	scanf(" %c",&a);
	for(int i=1;i<n;i++){
		scanf("%c",&b);
		if(a==b) isAcc=false;
		a=b;
	}
	if(isAcc) printf("Accepted\n");
	else printf("Wrong Answer\n");
}

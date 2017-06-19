#include <cstdio>

int main(){
	int n,aa,ad;
	char c;
	scanf("%d",&n);
	aa = ad =0;
	for(int i=0;i<n;i++){
		scanf(" %c",&c);
		if(c=='A') aa++;
		else if(c=='D') ad++;
	}
	if(aa>ad) printf("Anton\n");
	else if(ad>aa) printf("Danik\n");
	else printf("Friendship\n");
	return 0;
}

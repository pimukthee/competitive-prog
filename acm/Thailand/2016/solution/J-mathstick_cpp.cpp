#include<stdio.h>
#include<string.h>

int checkpair(int x,int y){
	if(x==0 && y==0){
		return 1;
	}
	if(x==1 && y==1){
		return 1;
	}
	if(x==2 && y==2){
		return 1;
	}
	if(x==5 && y==5){
		return 1;
	}
	if(x==6 && y==9){
		return 1;
	}
	if(x==8 && y==8){
		return 1;
	}
	if(x==9 && y==6){
		return 1;
	}
	return 0;
}

int checksolo(int x){
	if(x==0 || x==1 || x==2 || x==5 || x==8 || x==0){
		return 1;
	}
	return 0;
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		char input[200];
		scanf("%s",input);
		int len = strlen(input);
		int i=0,j=len-1,ans = 1;
		for(;i<j;i++,j--){
			if(0==checkpair(input[i]-'0',input[j]-'0')){
				ans = 0;
				break;
			}
		}
		if(i==j){
			if(0==checksolo(input[i]-'0')){
				ans = 0;
			}
		}
		if(ans==1) printf("Y\n");
		else printf("N\n");
	}
	return 0;
}




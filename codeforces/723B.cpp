#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n;
	char str[300];
	scanf("%d",&n);
	scanf("%s",str);
	bool inp = false,isw=true;
	int incount=0,outcount=0,t=0;
	for(int i=0;i<n;i++){
		if(str[i]=='_'){
			if(!inp) outcount = max( outcount,t );	
			else if(isw) incount+=1;
			t = 0;
			isw = false;
		}	
		else if(str[i]=='(') {
			inp= true;
			if(isw) outcount = max( outcount, t);
			t=0;
			isw = false;
		}
		else if(str[i]==')'){
			inp=false;
			if(isw) incount++;
			t=0;
			isw = false;
		}
		else isw=true,t++;
	}
	if(isw) outcount = max(outcount,t);
	printf("%d %d\n",outcount,incount);
}

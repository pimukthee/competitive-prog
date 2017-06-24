#include <cstdio>
#include <cstdio>
int main(){
	int n,th,tm,h,m,ans=1,c=1;
	scanf("%d",&n);
	scanf("%d %d",&h,&m);
	for(int i=1;i<n;i++){
		scanf("%d %d",&th,&tm);
		if(h==th && m==tm) c++;	
		else{
			ans = c>ans ? c : ans;
			c=1;
		}
		h=th; m=tm;
	}
	if(h==th && m==tm) ans = c>ans ? c : ans;

	printf("%d\n",ans);
}

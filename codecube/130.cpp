#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
	int n,k,t[100010],ans=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&t[i]);
	}
	sort(t,t+n,greater<int>());
	for(int i=0;i<n;i+=k){
		ans+=t[i];
	}
	printf("%d",ans);
}

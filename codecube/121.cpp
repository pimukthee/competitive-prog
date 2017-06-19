#include <cstdio>
#include <algorithm>
using namespace std;
struct edge{
	int s,t,w;
	bool operator <(const edge &other)const{
		return w<other.w;
	}
}e[1000010];

int n,m,head[100010],p[100010],lvl[100010],sel,j;
int findHead(int x){
	if(head[x]!=x){
		head[x] = findHead(head[x]);
		return head[x];
	}
	else return x;
}

int Union(int a,int b){
	int ha,hb;
	ha=findHead(a);
	hb=findHead(b);
	if(ha==hb) return -1;
	else{
		if(lvl[ha]<lvl[hb]){
			head[ha]=hb;
		}
		else if(lvl[ha]==lvl[hb]){
			head[hb]=ha;
			lvl[ha]++;
		}
		else{
			head[hb]=ha;
		}
		return p[a]+p[b];
	}
}

int main(){
	long ans=0;
	int c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) head[i]=i;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&e[i].s,&e[i].t);
		e[i].w = p[e[i].s]+p[e[i].t];
	}
	sort(e,e+m);
	while(sel<n-1){		
		c = Union(e[j].s,e[j].t);
		if(c>=0) ans+=c,sel++;
		j++;
	}
	printf("%ld",ans);	
	
	
}

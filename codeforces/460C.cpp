#include <iostream>
#include <vector>
#include <algorithm>
int w,n,m,a[100000+100];
using namespace std;


int f(int x){
	long long day,ans,t;
	vector<int> v(200010,0);
	day = max(0,x-a[0]);
	v[w] = -day;
	ans = day;
	for	(int i=1;i<n;i++){
		t = x-a[i];
		day+=v[i];
		if( t>day ){
			v[i+w] = -t+day;
			ans += t-day;
			day += t-day;
		}	
	}
	if(ans==m) return 0;
	else if(ans<m){
		if((m-ans)<n/w) return 0;	
		return -1;
	}	
	return 1;	
}

long long bsearch(int l,int r){
	if(l>r) return l;
	long long mid = (l+r)/2;
	int p = f(mid);
	if( p==0 ) return mid;	
	else if ( p==-1 ) return bsearch(mid+1,r);
	else return bsearch(l,mid); 
}

int main(){
	cin>>n>>m>>w;
	for(int i=0;i<n;i++)
		cin>>a[i];
	long long k = bsearch(1,1000000000);
	cout<<k<<endl;
	return 0;
}

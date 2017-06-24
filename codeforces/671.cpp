#include <iostream>
#include <algorithm>
using namespace std;
int n,k;
long long  minv,maxv,c[500000+10];

bool check(long long p,int mode){
	long long s = 0LL;
	for(int i=0;i<n;i++){
		if(mode) s+=max(0ll,c[i]-p);
		else s+=max(0ll,p-c[i]);
	}
	if(!mode) return s>k; 
	return s<=k;
}
// mode 1 as max , mode 0 as min
long long bsearch(int l,int r,int mode){
	long long mid = (l+r)/2;
	if(l>r){
		if(!mode) return r;	
		else return l;
	}
	else{
		if(check(mid,mode)){
			bsearch(l,mid-1,mode);
		}
		else{
			bsearch(mid+1,r,mode);	
		}
	}
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>c[i];
	
	minv = bsearch(1,100000000,0);
	maxv = bsearch(1,100000000,1);
	cout<<maxv-minv<<endl;
	return 0;
}

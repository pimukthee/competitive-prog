#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int n,k;
long long  minv,maxv,c[500000+10];

bool check(long long p,int mode){
	long long s = 0LL;
	for(int i=0;i<n;i++){
		if(mode) s+=max(0ll,c[i]-p);
		else s+=max(0ll,p-c[i]);
	}
	if(mode) return s>k; 
	return s<=k;
}
// mode 1 as max , mode 0 as min
long long bsearch(long long l,long long r,int mode){
	long long mid = (l+r)/2;
	if(l>r){
		 if(!mode) return r;	
		 else return l;
		//return mid;
	}
	else{
		if(!check(mid,mode)){
			return bsearch(l,mid-1,mode);
		}
		else{
			return bsearch(mid+1,r,mode);	
		}
	}
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)
		scanf("%lld",&c[i]);
	long long avg=0;
	for(int i=0;i<n;i++)
		avg+=c[i];

	minv = bsearch(1,(long long)floor((avg*1.0)/n),0);
	maxv = bsearch((long long)ceil((avg*1.0)/n),100000000000000000,1);
	cout<<maxv-minv<<endl;
	return 0;
}
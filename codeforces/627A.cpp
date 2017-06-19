#include <iostream>
using namespace std;
int main(){
	long long ans=1,s,x;
	cin>>s>>x;
	if(	(s-x)%2==1 ){
		cout<<0<<endl;
	}
	else{
		int j=0,cnt=0;
		while( x>>j > 0 ){
			if((x>>j)&1 && (((s-x)/2)>>j)&1){
				cout<<0<<endl;
				return 0;
			}
			cnt += (x>>j)&1;
			j++;
		}
		for(int i=0;i<cnt;i++)
			ans*=2;	
		if(s==x) ans-=2;
		cout<<ans<<endl;
	}
}

#include <iostream>

using namespace std;

int main(){
	int k,r;
	cin>>k>>r;
	int p = 1;
	while(p<10){
		if( (k*p)%10 == r || (k*p)%10==0 ) break;
		p++;
	}
	cout<<p<<endl;
	return 0;
}

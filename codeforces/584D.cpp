#include <iostream>
#include <cstring>
#include <ctime>
int prime[1000000000+10];
using namespace std;
int main(){
	memset(prime,0,100000);
	for(int i=2;i<=1000000;i++){
		for(int j=2; i*j<=1000000;j++){
			prime[i*j] = 1;
		}
	}
	int c=0;	
	for(int i=1;i<=1000000;i++){
		if(!prime[i])c++, cout<<i<<endl;
	}
	cout<<c<<endl;
}

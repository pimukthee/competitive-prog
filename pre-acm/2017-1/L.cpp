#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool isPrime[200000+10];

int main(){
	for(int i=0;i<200000+10;i++) isPrime[i] = true;	
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i<200000+10;i++){
		for(int j=2;i*j<200000+10;j++){
			isPrime[i*j] = false;
		}	
	}
	int n;
	cin >> n;
	int l=2000000;
	n = abs(n);
	for(int i=2;i<=200000;i++){
		if(isPrime[i]){
			l = min(l,abs(i-n));
		}	
	}
	cout << l <<endl;
	return 0;
}

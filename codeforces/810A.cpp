#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	double s=0.0,t,p,k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> t;
		s += t;
	}
	if(s/n<k-0.5)
	cout << ceil((n*(k-0.5)-s)/0.5) << endl;	
	else
	cout << 0 <<endl;	
	return 0;
}

#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int turn = 1;
	while(n>=0 && m>=0){
		if(turn%2==1) n -= turn;
		else m -= turn;
		turn ++;	
	}	
	if(n<0) cout << "Vladik";
	else cout << "Valera";	
	return 0;
}

#include<iostream>
using namespace std;
int main(){
	int a;
	string b;
	cin >> a >> b;
	bool up,down,left,right;
	up=down=left=right = true;
	for(int i = 0; b[i]; i++){
		if(b[i] == '0')
			left = right = down = false;
		if(b[i] == '1' || b[i] == '2' || b[i] == '3')
			up = false;
        if(b[i] == '7' || b[i] == '9')
			down = false;
		if(b[i] == '1' || b[i] == '4' || b[i] == '7')
			left = false;
		if(b[i] == '3' || b[i] == '6' || b[i] == '9')
			right = false;

	}
	if(left || up || right || down)
		cout << "NO" ;
    else
		cout << "YES" ;
}

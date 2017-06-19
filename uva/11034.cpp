#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){

	int l,time,C,m;
	cin>>C;
	while(C--){
		time = 0;
		cin>>l>>m;
		int pos,length;
		string side;
		l *= 100;
		queue <int> left,right;
		for(int i=0;i<m;i++){
			cin>>length>>side;
			if( side.compare("left") == 0 ) left.push(length);
			else right.push(length);
		}
		length = pos = 0 ;
		while(!left.empty() || !right.empty()){
			length=0;
			if( pos == 0) {
				while(!left.empty() && length + left.front() <=l){
					length+=left.front();
					left.pop();
				}
			}
			else{
				while(!right.empty() && length + right.front() <=l){
					length+=right.front();
					right.pop();
				}
			}
			time++;
			pos = (pos+1)%2;
		}
		cout<<time<<endl;
	}
	return 0;
}

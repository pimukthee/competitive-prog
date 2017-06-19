#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct a{
	int number,period,t;
	bool operator <(const a &o)const{
		if(t!=o.t) return t>o.t;
		else return number>o.number;
	}

}ar,temp;

int main(){
	string command;	
	int q,t,p,c;
	cin>>command;
	priority_queue<a> pq;
	while( command.compare("Register")==0){
		cin>>q>>p;
		ar.number=q;
		ar.period=ar.t=p;
		pq.push(ar);
		cin>>command;
	}
	cin>>t;
	while(t){
		temp = pq.top();
		pq.pop();
		c = temp.t;
		cout<<temp.number<<endl;
		temp.t+=temp.period;
		pq.push(temp);
		t--;
	}	
	return 0;
}

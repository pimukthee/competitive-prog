#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct a{
	int number,time;
	string side;
	bool operator <(const a &o)const{
		if(time!=o.time) return time>o.time;
		else number>o.number;
	}
}car[20010];

int main(){
	int Case,n,m,t,out[20010];
	cin >> Case;

	while(Case--){
		queue <a> left,right;
		cin>>n>>t>>m;
		for(int i=0;i<m;i++){
			car[i].number = i;
			cin>> car[i].time >> car[i].side;
			if(car[i].side.compare("left")==0) left.push(car[i]);
			else right.push(car[i]);
		}
		int time=0,pos = 0,count,another;
		while(!left.empty() || !right.empty() ){
			count =0 ;
			another=0;
			if(pos==0){
				while(!left.empty() && left.front().time<=time && count<n){
					out[left.front().number] = time+t;	
					left.pop();
					count ++;
				}
				if(!right.empty() && right.front().time<=time) another = 1;
			}
			else{
				while(!right.empty() && right.front().time<=time && count<n){
					out[right.front().number] = time+t;
					right.pop();
					count ++;
				}
				if(!left.empty() && left.front().time<=time) another = 1;
			}
			if(count>0 || another)	time+=t,pos = (pos+1)%2;
			else time++;
		}
		for(int i=0;i<m;i++)
			cout<<out[i]<<endl;
		if(Case)cout<<endl;
	

	}
	return 0;
}

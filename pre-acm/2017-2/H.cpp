#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct A{
	int diff,pos;
	char name;
	bool operator <(const A & o)const{
		if(diff != o.diff ) return diff > o.diff;
		else return pos > o.pos;
	}
};

struct B{
	char name;
	int sc;
	bool operator <(const B & o)const{
		if(sc != o.sc ) return sc > o.sc;
		else return name < o.name;
	}
}contestant[30];

int main(){
	int n,r,x,m,sc;
	char person;
	cin >> n >> r;
	for(int i=0;i<n;i++){
		contestant[i].name = 'A'+i;
		contestant[i].sc = 0;
	}
	for(int i=n;i<26;i++){
		contestant[i].sc = -1;
	}
	while(r--){
		cin >> x;
		cin >> m;
		priority_queue<A> pq;

		for(int i=0;i<m;i++){	
			A temp;
			cin >> temp.name >> sc ;	
			temp.pos = i;
			temp.diff = abs(sc - x);
			pq.push(temp);
		}
		int j=3;
		while(!pq.empty() && j>0){
//			cout << pq.top().diff<<endl;
			if(pq.top().diff==0) contestant[pq.top().name-'A'].sc += j+3;
			else contestant[pq.top().name-'A'].sc += j;
			j--;
			pq.pop();
		}
//		cout << endl;
	}

	sort(contestant,contestant+n);
	int score = contestant[0].sc;
	int i=0;
	while(i<n){	
		cout << contestant[i].sc ;
		while(i<n && contestant[i].sc == score){
			cout << ' '<< contestant[i].name;
			i++;
		}
		score = contestant[i].sc;
		cout << '\n';
	}
	return 0;
}



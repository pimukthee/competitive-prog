#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
	int t,sg,sb,n,x;
	cin>>n;
	while(n--){
		priority_queue<int> g,b;
		cin>>t>>sg>>sb;
		for(int i=0;i<sg;i++){
			cin>>x;
			g.push(x);
		}
		for(int i=0;i<sb;i++){
			cin>>x;
			b.push(x);
		}
		while(!g.empty() && !b.empty() ){
			queue<int> tg,tb;
			for(int i = 0 ;i < t;i++){
				if(g.empty() || b.empty() ) break;
				if(g.top() > b.top())
					tg.push(g.top() - b.top() );
				else if(g.top() < b.top())
					tb.push(b.top() - g.top() );
				g.pop();
				b.pop();
			}
			while(!tg.empty()) g.push(tg.front()),tg.pop();
			while(!tb.empty()) b.push(tb.front()),tb.pop();
		}
		if(g.empty() && b.empty() ) cout<<"green and blue died"<<endl;
		else if(!g.empty()){
			cout<<"green wins"<<endl;
			while(!g.empty()){
				cout<<g.top()<<endl;
				g.pop();
			}
		}
		else {
			cout<<"blue wins"<<endl;
			while(!b.empty()){
				cout<<b.top()<<endl,
				b.pop();
			}
		}
		if(n>0)	cout<<endl;
	}
}



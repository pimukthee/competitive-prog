#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int head[30],acorn,tree;

int findhead(int a){
	if(head[a]==a) return a;
	else{
		head[a] = findhead(head[a]);
		return head[a];
	}
}

bool u(int a,int b){
	int ha,hb;
	ha = findhead(a);
	hb = findhead(b);
	if(ha == hb) return false;
	else{
		head[hb]=ha;	
		return true;
	}
}

int main(){
	int Case;
	cin>>Case;
	string in;
	while(Case--){
		cin>>in;
		bool isVertex[30];
		memset(isVertex,false,30);
		vector<int> adj[30];
		while(in.at(0)=='('){
			adj[in.at(1)-'A'].push_back(in.at(3)-'A');
			cin>>in;
		}
		cin>>in;
		for(int i=0;i<in.length();i+=2){
			isVertex[in.at(i)-'A']=true;
		}
		tree=0;
		acorn=0;
		bool connect[30];
		for(int i=0;i<30;i++) head[i]=i,connect[i]=false;
		for(int i=0;i<30;i++){
			if(isVertex[i]){
				for(int j=0;j<adj[i].size();j++){
					u(i,adj[i][j]); 
					connect[i]=connect[adj[i][j]] = true;
				}
			}
		}
		for(int i=0;i<30;i++){
			if(isVertex[i]){
				if(!connect[i]) acorn++;
				else if(head[i]==i) tree++;	
			}
		}
		cout<<"There are "<<tree<<" tree(s) and "<<acorn<<" acorn(s)."<<endl;	
	}
	return 0;
}

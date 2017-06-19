#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1000000+10];

int main(){
    int n,m,t,a,b;
	
    while(cin >> n){
	    cin>>m;
		for(int i=0;i<1000000+10;i++) v[i].clear();	
	    for(int i=0;i<n;i++){
	        cin >> t;
			v[t].push_back(i);	
		}
	/*	for(int i=0;i<n;i++){
			cout<<i<<endl;
			for(int j=0;j<v[i].size();j++){
				cout<<v[i][j]<<' ';
			}
			cout<<endl;
		}*/
		for(int i=0;i<m;i++){
			cin >> a >> b;
			if(v[b].empty() || a>v[b].size()) cout<<0<<endl;
			else cout<<v[b][a-1]+1<<endl;
		}
	}
	return 0;
}

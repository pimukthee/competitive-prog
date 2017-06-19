#include <iostream>
#include <vector>
#include <utility>
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> ii; 
typedef vector<ii> vii;

int main(){
	int n,m,r,t[100001],x;
	while(cin >> m >> n){
		vii v[n];	
		for(int i=0;i<m;i++){
			cin >> r;
			for(int j=0;j<r;j++)
				cin >> t[j];
			
			for(int j=0;j<r;j++){
				cin >> x;
				v[t[j]-1].pb(mp(i,x));
			}
		}
		cout << n << ' ' << m <<endl;
	
		for(int i=0;i<n;i++){
			cout << v[i].size();
			for(int j=0;j<v[i].size();j++)
				cout << ' ' << v[i][j].first+1;
			cout << endl;
			if(v[i].size()) cout<<v[i][0].second;
			for(int j=1;j<v[i].size();j++)
				cout << ' ' << v[i][j].second; 
			cout<< endl;	
		}
	}
	return 0;
}

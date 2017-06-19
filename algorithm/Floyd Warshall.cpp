#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF 100000000
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N,M,s,t,w;
int adj[500][500],p[500][500];

void print(int i,int j){
	if(i!=j) print(i,p[i][j]);
	cout << ' ' <<j ;
}

int main(){
	
	cin >> N >> M;

		
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			adj[i][j] = INF;
			p[i][j] = i;
		}
	for(int i=0;i<N;i++) adj[i][i] = 0;

	for(int i=0;i<M;i++){
		cin >> s >> t >>w;
		adj[s][t] = w;
	}	

	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(adj[i][k] + adj[k][j] < adj[i][j]){
					adj[i][j] = adj[i][k] + adj[k][j]; 
					p[i][j] = p[k][j];
				}
	cin >> s >> t;
	while(s!=-1 && t!=-1){
		cout << "hello";
		print(s,t);
		cin >> s >>t;
	}	

	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

template <typename T>
using pql = priority_queue<T, vector<T>, greater<T> >; 
template <typename T>
using pqm = priority_queue<T>;

#define INF 1e9
#define mp make_pair
#define pb push_back
#define PI 3.141592653589793238

int path[101][101];
int weight[101][101];
char map[101][101];
int mr[4] = { -1, 0, 1, 0 };
int mc[4] = {  0, 1, 0,-1 };		
char p[4] = {'U','R','D','L'};
int fr,fc, N, M;

void dfs(int r,int c,int w,int parent){
//	cout<< "head" << r << ' ' << c << ' ' << w << ' ' << parent << endl;
//	cout << weight[r][c] << ' ' << w << endl;	
	if(weight[r][c] > w){
		weight[r][c] = w;
		path[r][c] = parent;	
	}
	else return;
	
	if(map[r][c]=='F'){
		fr = r;
		fc = c;
		return;
	} 
	for(int i=0;i<4;i++){
		if(r + mr[i] > N || r + mr[i] < 1) continue;
		if(c + mc[i] > M || c + mc[i] < 1) continue;	
//		cout <<  r + mr[i] << c + mc[i] << ' ';
//		cout<< map[r+mr[i]][c+mc[i]] << ' ' << weight[r+mr[i]][c+mc[i]] << endl;
		if( map[r+mr[i]][c+mc[i]] != '*' && weight[r+mr[i]][c+mc[i]] > w+1)
			dfs(r+mr[i],c+mc[i],w+1,i);
	}
}

string backtrack(){
	string ans = "";
	//cout << fr << ' ' << fc <<endl;
	int r = fr;
	int c = fc;
	//cout << "hello " << r << ' ' << c<<endl;;
	while(!(r == 1 && c == 1)){
		//cout <<"y"<< r << ' ' << c <<endl;
		ans.pb(path[r][c]);	
		int tr = r - mr[path[r][c]];
		int tc = c - mc[path[r][c]];
		r = tr;
		c = tc;
	}	
	return ans;
}

int main(){
	
	cin >> N >> M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			scanf(" %c",&map[i][j]); 
		}


	bool invVer = false, invHorz = false;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=M;j++){
			path[i][j] = '\0';
			weight[i][j] = INF;
		}
	}
	dfs(1,1,0,0);

	string ans = backtrack();
//	for(int e : ans)
//		cout<<e<<' ';
	int wr=1, wc=1;
	bool iVer = false, iHorz = false;	
	bool c_iVer = false, c_iHorz = false;
	int tempr = wr, tempc = wc;
	int pos = ans.length()-1;
	int tr,tc;
	while(pos>=0){
			//printf("%d %d\n",wr,wc);
//		fflush(stdout);
		if(ans[pos]%2==0){
			if(!c_iVer){
				printf("%c\n",p[ans[pos]]);
				fflush(stdout);
				scanf("%d %d",&tr,&tc);
				c_iVer = true;
				if(tr == wr && tc == wc){
					iVer = true;
				}
				else{
					pos --;
				}
				wr = tr;
				wc = tc;
			}
			else{
				if(iVer){
					printf("%c\n",p[(ans[pos--]+2)%4]);
					fflush(stdout);
				}
				else{
					printf("%c\n",p[ans[pos--]]);
					fflush(stdout);
				}
				scanf("%d %d",&tr,&tc);	
				wr = tr; wc = tc;
			}
		}
		else{
			if(!c_iHorz){
				printf("%c\n",p[ans[pos]]);
				fflush(stdout);
				scanf("%d %d",&tr,&tc);
				c_iHorz = true;
				if(tr == wr && tc == wc){
					iHorz = true;
				}
				else{
					pos --;
				}
				wr = tr;
				wc = tc;
			}
			else{
				if(iHorz){
					printf("%c\n",p[(ans[pos--]+2)%4]);
					fflush(stdout);
				}
				else{
					printf("%c\n",p[ans[pos--]]);
					fflush(stdout);
				}
				scanf("%d %d",&tr,&tc);	
				wr = tr; wc = tc;
			}
		}	
	}

	return 0;
}

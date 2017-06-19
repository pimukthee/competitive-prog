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
#define push_back pb
#define PI 3.141592653589793238

char path[101][101];
int w[101][101];

bool check(string s1,string s2){
	if(s1.size() <= 1){
		s1 = "0" + s1;
	}	
	if(s2.size() <= 1){
		s2 = "0" + s2;
	}
	for(int i=0;i<s1.length();i++)
		if(s1[i] != s2[s2.length()-i-1]) return false;
	return true;
}

int main(){
	int h,m;
	char c;
	cin >> h >> c >> m;
	int ans = 0;
	while( !check(to_string(h),to_string(m)) ){
		h = (m+1)%60 == 0 ? (h+1)%24 : h;
		m = (m+1)%60;
		ans ++ ;
	}	

	cout << ans << endl;
	return 0;
}

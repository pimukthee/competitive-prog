#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <utility>
#include <math.h>
#include <cstring>
#define FOR(i,x,y) for(int i=x;i<=y;i++)
#define ROF(i,x,y) for(int i=x;i>=y;i--)
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define sz(X) ((int)(X).size()) 
#define MAX_int (1<<31)-1
#define MIN_int -(1<<31)+1

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI; 



int main(){

	string A,B;
	int a=0,b=0,maxx=-1;
	cin >> A >> B;
	int	ans = 0;	
	while( 1 ){
		if(a >= A.length() ) break;
		else if(b>=B.length()) break;
		else{
			if(A[a] == B[b] ) a++,b++,ans +=2;
			else b++,ans-=1;
		}
	}
	
	cout << ans;
	return 0;
}

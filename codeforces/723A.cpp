#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int a,b,c,m=99999;
	scanf("%d %d %d",&a,&b,&c);
	for(int i=1;i<=100;i++){
		m = min( m, abs(a-i)+abs(b-i)+abs(c-i) );	
	}
	printf("%d\n",m);
}

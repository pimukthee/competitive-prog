#include<cstdio>

char work(long long k,long long n,bool s){
    long long m = (k-1LL)/3LL;

	if(k==4LL){
		if(n==3LL){
		   	if(s) return 'P';
			else return 'A';
		}
		else{
			if(s) return 'A';
			else return 'P';
		}
	}
	else if(n == m+1LL ){
        if(!s) return 'P';
        else return 'A';
	}
	else{
		if(n<=m) return work(m,n,s);
		else if(n>2LL*m+1LL) return work(m,n-2LL*m-1LL,s);
		else return work(m,n-m-1LL,!s);
	}
}

int main(){

	int x,T;
	long long int n,k;
	scanf("%d",&T);
		
	while(T--){
		scanf("%ld",&n);
		x = 1;
		k = 4LL;
		while( k < n ){
			k = 3LL*k + 1LL;
			x++;
		}
		printf("%lf\n",work(k,n,false);
	}
	return 0;
}

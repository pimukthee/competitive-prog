#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	int k,n,m,countWord=0,wordEqual=0;
	char in1[110],in2[110];
	scanf("%d",&k);
	while(k--){
		scanf("%d %d",&n,&m);
		scanf("%s",in1);
		countWord=0;
		countWord+=strlen(in1);
		for(int i=1;i<m;i++){
			scanf("%s",in2);
			int k=0,j=n-1;
			wordEqual=0;
			while(j>=0) {
				k=0;
				if(in1[j]==in2[k]){
					int p=j;
					for(p=j;p<n && in1[p]==in2[k];p++) k++;
					if(p==n) wordEqual = max(k,wordEqual);
					
				}
				j--;
			}
			countWord+=(n-wordEqual);
			strcpy(in1,in2);

		}		
				
		printf("%d\n",countWord);
			
	}		
}

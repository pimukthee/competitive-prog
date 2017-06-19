#include <iostream>

using namespace std;
char t[30][30];
int T,R,C;

void merge(int col,int l2,int r2){
	for(int i=l2;i<=r2;i++){
		for(int j=0;j<R;j++)
			t[j][i] = t[j][col];	
	}
}


bool dq(int left,int right){
	int c=0; char x;
	
	for(int i=left;i<=right;i++){
		for(int j=0;j<R;j++){
			if(t[j][i]!='?') x=t[j][i],c++;
		}
	}
//	cout << left << " " <<right <<' '<<c<<endl;
	if(c==0) return false;
	else if(c==1){
		for(int i=left;i<=right;i++)
			for(int j=0;j<R;j++)
				t[j][i]=x;
		return true;
	}
	else if(left==right){
		int i=0;
		while(t[i][left]=='?') i++;
		for(int j=0;j<i;j++) t[j][left]=t[i][left];		
		int j = i+1;
		while(j<R){
			if(t[j][left]=='?') t[j][left] =t[i][left];
			else i=j;	
			j++;
		}
		return true;
	}
	else if(c>1){
		bool p1 = dq(left,(left+right)/2);
		bool p2 = dq((left+right)/2+1,right);
		if(!p1) merge((left+right)/2+1,left,(left+right)/2);
		if(!p2) merge((left+right)/2,(left+right)/2+1,right);
		return true;
	}
	return true;
}



int main(){
	int loop=0;

	cin >> T;
	while(loop++<T){
		cin >> R >> C;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				cin >> t[i][j];
		}
		dq(0,C-1);
		cout<<"Case #"<< loop <<":"<<endl;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				cout<<t[i][j];
			cout<<endl;
		}
	}
	
	return 0;
}

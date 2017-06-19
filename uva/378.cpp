#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;

int main(){
	double n,x1,x2,x3,x4,y1,y2,y3,y4;
	double dx1,dx2,dy1,dy2,c1,c2;
	double ax,ay;
	cin>>n;
	cout<<"INTERSECTING LINES OUTPUT"<<endl;
	while(n--){
		string ans = "NONE";
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		dx1 = x2-x1;
		dy1 = y2-y1;
		dx2 = x4-x3;	
		dy2 = y4-y3;
		c1 = ( -dx1*y1 + dy1*x1 );
		c2 = ( -dx2*y3 + dy2*x3 );
		if(dx1==0 && dx2==0 ){
			if( c1 == c2 ) ans="LINE";
			else ans="NONE";
		}
		else if( (dx1!=0 && dx2!=0) && (dy1/dx1 == dy2/dx2 ) ){
			if( -dx1 * y3 + dy1 * x3 == c1 ) ans="LINE";
			else ans="NONE";
		}	
		else{
			ans = "POINT ";
			ax = ( (c1*-dx2 ) - (c2*-dx1) )/( dy1*-dx2 - dy2*-dx1 );
			ay = ( (c2*dy1 ) - (c1*dy2) )/( dy1*-dx2 - dy2*-dx1 );
		}
		cout<<ans;
		if(ans.compare("POINT ")==0){
			if( abs(ay)*100<=0.00) ay=0.00;
			if( abs(ax)*100<=0.00) ax=0.00;
			printf("%.2lf %.2lf",ax,ay);
		}
		cout<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}

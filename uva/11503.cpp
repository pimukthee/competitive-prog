#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class unionFind{
	private:
		map<string,int> rank,size;	
		map<string,string> p;
	public:
		unionFind(){
		}
		void initial(string s){
			if(size[s] == 0 ){
				size[s] = 1;
				rank[s] = 0;	
				p[s]=s;	
			}
		}
		string findHead(string s){
			if(s == p[s] ) return s;
			else return p[s] = findHead(p[s]);
		}
		int unionSet(string a,string b){
			string ha = findHead(a);
			string hb = findHead(b);
			if(ha!=hb){
				if(rank[ha]>rank[hb]) p[hb]=ha,size[ha]+=size[hb];
				else if(rank[ha]<rank[hb]) p[ha]=hb,size[hb]+=size[ha];
				else p[ha]=hb,size[hb]+=size[ha],rank[hb]++;
			}
			return size[findHead(ha)];
		}
};

int main(){
	int n,T;
	string s1,s2;
	cin >> T;
	while(T--){
		cin >> n;
		unionFind u;
		for(int i=0;i<n;i++){
			cin >> s1 >> s2;
			u.initial(s1);
			u.initial(s2);
			cout<<u.unionSet(s1,s2)<<endl;	
		}
	}
	return 0;
}

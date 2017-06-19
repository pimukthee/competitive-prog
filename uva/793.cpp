#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;

class UnionFind{
	private:
		vi p,rank;
	public:
		UnionFind(int n){
			n+=10;
			rank.assign(n,0);
			p.assign(n,0);
			for(int i=0;i<n;i++) 
				p[i]=i;
		}
		
		int findHead(int a){
			if(a == p[a]) return a;
			else return p[a] = findHead(p[a]);
		}
		
		bool isSameSet(int a,int b){
			return findHead(a) == findHead(b);
		}
		
		void unionSet(int a,int b){
			int sa = findHead(a);
			int sb = findHead(b);
			if(sa!=sb){
				if(rank[sa] > rank[sb]) p[sa] = sb;
				else if(rank[sa] < rank[sb]) p[sb]=sa;	
				else p[sa]=sb,rank[sa]++;
			}
			
		}
};

int main(){
	int N,a,b,c=0,n=0,CASE;
	string s;
	cin >> CASE;
	while(CASE--){
		cin >> N;
		c = n = 0;
		UnionFind u(N);
		getline(cin,s);
//		cout << CASE<<"s"<<s << endl;
		while(getline(cin,s)){
			if(s.empty()) break;
//			cout << s <<endl;
			int l,r;
			for(int i=s.length()-1;i>=0;i--){
				if(s[i] == ' '){
					a = stoi(s.substr(2,i));
					b = stoi(s.substr(i,s.length()));
					break;
				}
			}
//			cout << a << ' ' << b <<endl;
			if(s[0] == 'c') u.unionSet(a,b);
			else if(u.isSameSet(a,b)) c++; 
			else n++;
		}
		cout<<c<<','<<n<<endl;
		if(CASE) cout<<endl;
	}

	return 0;
}

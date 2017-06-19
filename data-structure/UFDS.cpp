#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

class UnionFind{
	private:
		vi p,rank;
	public:
		UnionFind(int n){
			rank.assign(n,0);
			for(int i=0;i<n;i++) 
				p.push_back(i);
		}
		
		int findHead(int a){
			if(a == p[i]) return a;
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

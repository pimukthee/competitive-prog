/*
Alfonso2 Peterssen(mukel)
SPOJ #8217 "XOR Maximization"
*/
#include <cstdio>

typedef long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAXN = 1 << 17;

int n;
int64 val[MAXN];
int64 ans;

#include <cstdio>
#include <iostream>
using namespace std;
struct IO{static const int MB = 1<<21;bool eof;char tb[MB],ib[MB+1],ob[MB],*ip,*ibe,*op,*obe;inline void fb(){ibe=ib+fread(ib,1,sizeof(ib),stdin);ip=ib;*ibe='\0';}inline char gc(){if(ip>=ibe)fb();return*ip++;}inline bool sb(){while(1){if(ip>=ibe)fb();if(!*ip){eof=1;return 0;}if(*ip>' ')return 1;ip++;}}inline operator bool(){return !eof;}inline void pc(char ch){if(op>=obe)ff();*op++=ch;}IO(){eof=0;fb();op=ob;obe=ob+sizeof(ob);}~IO(){ff();}inline void ff(){fwrite(ob,1,op-ob,stdout);op=ob;}
#define ioOp inline IO& operator
#define rt return *this
ioOp>>(char &v){if(!(v=gc()))eof=1;rt;}ioOp>>(char *buff){if(sb())while((*buff=gc())>' ')buff++;*buff='\0';rt;}ioOp>>(string &str){if(*this>>tb)str=string(tb);rt;}ioOp<<(char v){pc(v);rt;}ioOp<<(const char *buff){while(*buff)pc(*buff++);rt;}ioOp<<(const string &str){rt<<str.c_str();}
#define defOp(vt) ioOp>>(vt& v){if (sb()){v=0;bool neg=(*ip=='-');if(*ip=='-'||*ip=='+')ip++;char ch;while((ch=gc())>' '){v*=10;v+=ch-'0';}if(neg)v=-v;}rt;}
defOp(int)defOp(unsigned int)defOp(long long)defOp(unsigned long long)
#undef defOp
#define defOp(vt) ioOp<<(register vt v){if(v<0){pc('-');v=-v;}int i=0;do tb[i++]=(v%10)+'0';while(v/=10);while(i)pc(tb[--i]);rt;}
defOp(int)defOp(unsigned int)defOp(long long)defOp(unsigned long long)
#undef defOp
#undef ioOp
#undef rt
#define cin io
#define cout io
#define endl ('\n')
}io;

int main()
{
	cin >> n;
	REP(i, n) cin >> val[i];
	
	for (int i = 63; i >= 0; i--)
	{
		int64 p = -1;
		REP(j, n) if ((val[j] >> i) & 1) { p = val[j]; break; }
		if (p < 0) continue ;
		if (!((ans >> i) & 1)) ans ^= p;
		REP(j, n) if ((val[j] >> i) & 1) val[j] ^= p;
 	}

	cout << ans << endl;

	return 0;
}

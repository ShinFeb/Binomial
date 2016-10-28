/*
	Markdown is nice.
	埋个伏笔：
	这里比logdown快一点。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cassert>

using namespace std;

#define prt(x) cout<<#x<<":"<<x<<" "
#define prtn(x) cout<<#x<<":"<<x<<endl
#define shut assert(0)
#define when printf("%.2f\n",1.0*clock()/CLOCKS_PER_SEC)
#define rep(i,s,t) for(int i=s,i##_=t;i<i##_;++i)
#define per(i,s,t) for(int i=(t)-1,i##_=s;i>=i##_;--i)
#define inf (1<<30)
#define INF (1LL<<62)
#define sqr(x) ((x)*(x))
#define pb push_back
#define NOO puts("-1"),0
#define BE(x) (a).begin(),(a).end()

typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef vector<VI> MT;
typedef vector<double> VD;
typedef vector<string> VS;
struct ii
{
	int x,y;
	ii(int x=0,int y=0):x(x),y(y){}
	bool operator<(const ii &a)const{if(x!=a.x)return x<a.x;return y<a.y;}
	bool operator==(const ii&a)const{return x==a.x&&y==a.y;}
	ii friend operator+(ii a,ii b){return ii(a.x+b.x,a.y+b.y);}
	ii friend operator-(ii a,ii b){return ii(a.x-b.x,a.y-b.y);}
};
 
//ll memory freopen

template<class T>void sc(T &x)
{
	x=0;char c;int f=1;
	while(c=getchar(),c<48)if(c=='-')f=-1;
	do x=x*10+(c^48);
	while(c=getchar(),c>47);
	x*=f;
}
template<class T>void nt(T x)
{
	if(!x)return;
	nt(x/10);putchar(x%10+'0');
}
template<class T>void pt(T x)
{
	if(x<0)putchar('-'),x=-x;
	if(!x)putchar('0');else nt(x);
}
template<class T>void pts(T x)
{
	pt(x);putchar(' ');
}
template<class T>void ptn(T x)
{
	pt(x);putchar('\n');
}
template<class v>void pp(v x,int y)
{
	static char ch[]={" \n"};
	pt(x);putchar(ch[y]);
}
template<class T>void PP(T *x,int y)
{
	rep(i,0,y)pp(x[i],i==y-1);
}
template<class T>void Max(T &x,T y){if(x<y)x=y;}
template<class T>void Min(T &x,T y){if(x>y)x=y;}

/* template ends here  */

int main()
{
//	freopen("pro.in","r",stdin);
//	freopen("chk.out","w",stdout);
	
	return 0;
}

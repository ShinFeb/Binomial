#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <set>
#include <map>
#include <complex>
#include <queue>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string.h>
 
using namespace std;
 
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef pair<int,int> ipair;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi=acos(-1.0);
const double eps=1e-13;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(a) (a).begin(),(a).end()
 
template<class T> T sqr(const T &x) { return x*x; }
template<class T> T lowbit(const T &x) { return (x^(x-1))&x; }
template<class T> int countbit(const T &n) { return (n==0)?0:(1+countbit(n&(n-1))); }
template<class T> void ckmin(T &a,const T &b) { if (b<a) a=b; }
template<class T> void ckmax(T &a,const T &b) { if (b>a) a=b; }
 
 
const int maxnode=10000;
const int maxedge=10000;
const int oo=1000000000;
 
int node,src,dest,nedge;
int head[maxnode],point[maxedge],nextp[maxedge],flow[maxedge],capa[maxedge];
int distp[maxnode],Q[maxnode],work[maxnode];
 
void init(int _node,int _src,int _dest)
{
	node=_node;
	src=_src;
	dest=_dest;
	for (int i=0;i<node;i++) head[i]=-1;
	nedge=0;
}
void addedge(int u,int v,int c1,int c2)
{
	point[nedge]=v,capa[nedge]=c1,flow[nedge]=0,nextp[nedge]=head[u],head[u]=(nedge++);
	point[nedge]=u,capa[nedge]=c2,flow[nedge]=0,nextp[nedge]=head[v],head[v]=(nedge++);
}
bool dinic_bfs()
{
	for (int i=0;i<node;i++) distp[i]=-1;
	distp[src]=0;
	int sizeQ=0;
	Q[sizeQ++]=src;
	for (int cl=0;cl<sizeQ;cl++)
		for (int k=Q[cl],i=head[k];i>=0;i=nextp[i])
			if (flow[i]<capa[i] && distp[point[i]]<0)
			{
				distp[point[i]]=distp[k]+1;
				Q[sizeQ++]=point[i];
			}
	return distp[dest]>=0;
}
int dinic_dfs(int x,int exp)
{
	if (x==dest) return exp;
	int res=0;
	for (int &i=work[x];i>=0;i=nextp[i])
	{
		int v=point[i],tmp;
		if (flow[i]<capa[i] && distp[v]==distp[x]+1 && (tmp=dinic_dfs(v,min(exp,capa[i]-flow[i])))>0)
		{
			flow[i]+=tmp;
			flow[i^1]-=tmp;
			res+=tmp;
			exp-=tmp;
			if (exp==0) break;
		}
	}
	return res;
}
int dinic_flow()
{
	int result=0;
	while (dinic_bfs())
	{
		for (int i=0;i<node;i++) work[i]=head[i];
		result+=dinic_dfs(src,oo);
	}
	return result;
}
 
const int maxn=128;
 
int n,m,k;
int g[maxn][maxn];
int s,t;
priority_queue<pair<int,vector<int> > > heap;
 
void add(const VI& c)
{
	int o[maxn],w[maxn][maxn];
	REP(i,n) o[i]=((c[i]==0)?s:(c[i]==1?t:i));
	memset(w,0,sizeof(w));
	REP(i,n) REP(j,n) if (g[i][j]) w[o[i]][o[j]]+=g[i][j];
	init(n,s,t);
	REP(i,n) REP(j,n) if (w[i][j]) addedge(i,j,w[i][j],0);
	int h=dinic_flow();
	heap.push(MP(-h,c));
}
int main()
{
	cin>>n>>m>>k;
	cin>>s>>t;
	--s;
	--t;
	memset(g,0,sizeof(g));
	REP(i,m)
	{
		int x,y,w;
		cin>>x>>y>>w;
		--x;
		--y;
		g[x][y]+=w;
	}
	VI c(n,-1);
	c[s]=0;
	c[t]=1;
	add(c);
	while (!heap.empty())
	{
		pair<int,vector<int> > state=heap.top();
		c=state.second;
		heap.pop();
		int key=-1;
		REP(i,n) if (c[i]<0) key=i;
		if (key<0)
		{
			if ((--k)==0) { printf("%d",-state.first); return 0; }
			continue;
		}
		c[key]=0;
		add(c);
		c[key]=1;
		add(c);
	}
	return 0;
}

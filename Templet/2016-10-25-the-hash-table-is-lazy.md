```cpp
struct MAP
{
	static const int MOD=200000000;
	int s[maxn];
	int h[MOD],ed[maxn],nd[maxn],ecnt;
	MAP()
	{
		memset(h,0,sizeof h);
		ecnt=0;
	}
	bool find(int u,ull v)
	{
		v%=mod;
		for(int i=h[v];i;i=nd[i])if(ed[i]==u)return true;
		return false;
	}
	void operator ()(int u,ull v)
	{
		++ecnt;v%=mod;
		s[ecnt]=v;ed[ecnt]=u;nd[ecnt]=h[v];h[v]=ecnt;
	}
	void clear()
	{
		rep(i,1,ecnt+1)h[s[i]]=0;
		ecnt=0;
	}
}; 
```

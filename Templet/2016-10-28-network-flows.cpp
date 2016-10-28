/*
	比以前的网络流模板简洁一些，来源依然是楼爷。
	现在觉得不封装自然一些，一本正经的一个结构体不如几个简洁的函数优雅。
	可以选择把流量(flow)和容量(cap)分开来，这样容易还原。

	以前提过无向图拆出的2条边不用建反向边，引申出的一种还原方法：
	`for(int i=0;i<ecnt;i+=2)acap[i]=acap[i^1]=(acap[i]+acap[i^1])>>1;`
*/
int n,m;
int dist[maxn],q[maxn];
int point[maxm],nextp[maxm],acap[maxm],ecnt,head[maxn],work[maxn];
void ins(int u,int v,int cap){point[ecnt]=v;nextp[ecnt]=head[u];acap[ecnt]=cap;head[u]=ecnt++;}
int S,T;
int dinic_dfs(int x,int exp)
{
	if(x==T)return exp;
	int res=0,tmp;
	for(int &i=work[x];i>=0;i=nextp[i])
	{
		int y=point[i];
		if(acap[i]&&dist[y]==dist[x]+1&&(tmp=dinic_dfs(y,min(exp,acap[i]))))
		{
			acap[i]-=tmp;
			acap[i^1]+=tmp;
			res+=tmp;
			exp-=tmp;
			if(!exp)break;
		}
	}
	return res;
}
bool dinic_bfs()
{
	rep(i,0,n)dist[i]=-1;
	int l,r;l=r=0;
	q[r++]=S;dist[S]=0;
	while(l<r)
	{
		int x=q[l++];
		for(int i=head[x];i>=0;i=nextp[i])
		{
			int y=point[i];
			if(acap[i]>0&&dist[y]<0)
			{
				dist[y]=dist[x]+1;
				q[r++]=y;
			}
		}
	}
	return dist[T]>=0;
}
int a[maxn],b[maxn];
int dinic_flow()
{
	for(int i=0;i<ecnt;i+=2)acap[i]=acap[i^1]=(acap[i]+acap[i^1])>>1;
	int ans=0;
	while(dinic_bfs())
	{
		rep(i,0,n)work[i]=head[i];
		ans+=dinic_dfs(S,inf);
	}
	return ans;
}
bool vis[maxn];
void bfs()
{
	int l,r;l=r=0;
	memset(vis,0,n);
	q[r++]=S;vis[S]=true;
	while(l<r)
	{
		int x=q[l++];
		for(int i=head[x];i>=0;i=nextp[i])
		{
			int y=point[i];
			if(acap[i]&&!vis[y])
			{
				vis[y]=true;
				q[r++]=y;
			}
		}
	}
}

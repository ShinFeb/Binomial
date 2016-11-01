/*
	二分的很清奇 
	但精妙的还是利用单调性使得合并相邻的一对操作一定合法
	建议多读 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 255
#define oo 1000000000
using namespace std;
int n,k,m,a[maxn],b[maxn],l[maxn],r[maxn],pre[maxn];

bool check(int lim)
{
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	int now=0,s=m;
	for (int i=1;i<=n;i++)
	{
		b[i]=a[i]-lim;
                b[i]=max(0,b[i]);
		l[i]+=b[i];
		r[i]+=b[i];
		now+=b[i];
	}
	s-=now;
	if (s<0) return false;
	while (now>k)
	{
		int minn=oo,t=0;
		pre[1]=0;
		for (int i=2;i<=n;i++)
		{
			if (r[i-1]>0) pre[i]=i-1; else pre[i]=pre[i-1];
			if ((l[i]>0)&&(r[pre[i]]!=0)&&(i-pre[i]-1<minn))
			{
				minn=i-pre[i]-1;
				t=i;
			}
		}
		if (minn==oo) break;
		int num=min(l[t],r[pre[t]]);
		if (num*minn>s)
		{
			now-=s/minn;
			break;
		}
		s-=num*minn;
		r[pre[t]]-=num;
		l[t]-=num;
		now-=num;
	}
	return now<=k;
}
int main()
{
	freopen("Championship.in","r",stdin);
	freopen("Championship.out","w",stdout);
	int ll=0,rr=0;
	scanf("%d%d%d",&n,&k,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]>rr) rr=a[i];
	}
	while (ll<rr)
	{
		int mid=(ll+rr)>>1;
		if (check(mid)) rr=mid; else ll=mid+1;
	}
	printf("%d\n",ll);
	return 0;
}

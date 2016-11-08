/*
	维护一个W*W的矩阵，每次操作可以增加某格子的权值，或询问某子矩阵的总权值。
	修改操作数M<=160000，询问数Q<=10000，W<=2000000。
	对矩阵分块
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define maxl 1500
#define maxm 200010
#define fo(i,u,d) for(int i=u;i<=d;i++)
using namespace std;
struct data{int x,y,id,t,next;};
int n,q=0,w,len,all=0,ty;
int f[maxl][maxl],g[maxl*maxl*3];
data d[maxm*4];
int ans[10100];
int st[maxm];

void adde(int dx,int dy,int h,int x,int y,int q,int t){
	 int wh=(dx-1)*len+dy+h;
	 d[++all].x=x;
	 d[all].y=y;
	 d[all].id=q;
	 d[all].t=t;
	 d[all].next=g[wh];
	 g[wh]=all;
}

void insertq(int x,int y,int q,int t){
	 if ((x==0)|(y==0))return;
	 int dx=(x-1)/len+1,dy=(y-1)/len+1;
	 adde(dx,dy,1,(x-1)%len+1,(y-1)%len+1,q,t);
	 if ((dx>1)&&(dy>1))
	 	adde(1,1,0,dx-1,dy-1,q,t);
 	 if (dy>1)
 	 	adde(1,dx,1+len*len,(x-1)%len+1,dy-1,q,t);
 	 if (dx>1)
 	 	adde(1,dy,1+len*len+len,dx-1,(y-1)%len+1,q,t);
}

void insert(int x,int y,int t){
	 int dx=(x-1)/len+1,dy=(y-1)/len+1;
	 adde(dx,dy,1,(x-1)%len+1,(y-1)%len+1,0,t);
	 adde(1,1,0,dx,dy,0,t);
 	 adde(1,dx,1+len*len,(x-1)%len+1,dy,0,t);
 	 adde(1,dy,1+len*len+len,dx,(y-1)%len+1,0,t);
}

int init(){
	scanf("%d%d",&ty,&w);
	len=int(sqrt(w));if (len*len!=w)len++;
	fo(i,1,len*len*3)g[i]=0;
	while(scanf("%d",&ty)){
		int x1,y1,x2,y2,t;
		if (ty==3)break;
		if (ty==2){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			insertq(x2,y2,++q,1);
			insertq(x2,y1-1,q,-1);
			insertq(x1-1,y2,q,-1);
			insertq(x1-1,y1-1,q,1);
		}
		else{
			scanf("%d%d%d",&x1,&y1,&t);
			insert(x1,y1,t);
		}
	}
	fo(i,0,len)fo(j,0,len)f[i][j]=0;
}

void add(int x,int y,int t){
	 for(int i=x;i<=len;i+=i&-i)
	 	for(int j=y;j<=len;j+=j&-j)
	 		f[i][j]+=t;
}

int cal(int x,int y){
	int i,j,s=0;
	for(i=x;i;i-=i&-i)
	 	for(j=y;j;j-=j&-j)
	 		s+=f[i][j];
	return s;
}

void solve(){
	 fo(i,1,len*len+1+len+len){
	 	st[0]=0;
	 	for(int p=g[i];p;p=d[p].next)
	 		st[++st[0]]=p;
 		for(int p=st[0];p;p--)
	 		if(d[st[p]].id==0)
			 	add(d[st[p]].x,d[st[p]].y,d[st[p]].t);
	 		else
			 	ans[d[st[p]].id]+=d[st[p]].t*cal(d[st[p]].x,d[st[p]].y);
	 	fo(p,1,st[0])
 			if (d[st[p]].id==0)
	 			add(d[st[p]].x,d[st[p]].y,-d[st[p]].t);
	 }
}

int main(){
	freopen("mokia.in","r",stdin);
	freopen("mokia.out","w",stdout);
	init();
	solve();
	fo(i,1,q)
		printf("%d\n",ans[i]);
	return 0;
}

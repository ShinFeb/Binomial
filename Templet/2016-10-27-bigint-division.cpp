/*
	用二分做大整数除法。
	造数据的时候发现我的BigInt清空的不规范。举个例子，求和部分会调用>=len的部分，如果之前没清空就乱了。
	但对单组数据是不会有影响的。
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <set>
#include <bitset>
#include <stack>
 
//long long,memory,freopen
using namespace std;
 
#define rep(i,s,t) for(register int i=s,t_=t;i<t_;i++)
#define per(i,s,t) for(register int i=(t)-1,s_=s;i>=s_;i--)
#define prt(x) cout<<#x<<":"<<(x)<<" "
#define prtn(x) cout<<#x<<":"<<(x)<<endl
#define shut assert(0)
#define when printf("%.2f\n",1.0*clock()/CLOCKS_PER_SEC)
#define sqr(x) ((x)*(x))
#define inf (1<<30)
#define INF (1ll<<62)
 
typedef long long ll;
typedef double db;
typedef vector<int> VI;
struct ii
{
    int x,y;
    ii(int x=0,int y=0):x(x),y(y){}
    inline bool operator<(const ii &a)const{return x==a.x?y<a.y:x<a.x;}
    ii operator+(const ii &a)const{return ii(x+a.x,y+a.y);}
};
typedef vector<ii> VII;
 
template<class v>void sc(v &x)
{
    char c;x=0;int f=1;
    while(c=getchar(),c<48)if(c=='-')f=-1;
    do x=x*10+(c^48);
    while(c=getchar(),c>47);
    x*=f;
}
template<class v>void nt(v x)
{
    if(!x)return;
    nt(x/10);putchar('0'+x%10);
}
template<class v>void pt(v x)
{
    if(x<0)putchar('-'),x=-x;
    if(!x)putchar('0');
    else nt(x);
}
template<class v>void ptn(v x)
{
    pt(x);putchar('\n');
}
template<class v>void pts(v x)
{
    pt(x);putchar(' ');
}
template<class v>void pp(v x,int f)
{
    static char ch[]={" \n    "};
    pt(x);putchar(ch[f]);
}
template<class v>inline void Max(v &x,v y){if(x<y)x=y;}
template<class v>inline void Min(v &x,v y){if(x>y)x=y;}
 
struct BigInt
{
    static const int NUM=1100;
    int num[NUM],len;
    BigInt()
    {
        memset(num,0,sizeof num);
        len=1;
    }
    void half()
    {
        int p=0;
        per(i,0,len)
        {
            if(p)num[i]+=10000;
            p=num[i]&1;
            num[i]>>=1;
        }
        if(len&&!num[len-1])len--;
    }
    void upd(int x)
    {
        num[0]+=x;
        rep(i,0,len)
        {
            if(num[i]>=0&&num[i]<10000)break;
            if(num[i]<0)num[i+1]--,num[i]+=10000;
            else num[i]-=10000,num[i+1]++;
        }
        if(num[len])len++;
        else while(len&&!num[len-1])len--;
    }
    bool operator <(const BigInt &a)const
    {
        if(len!=a.len)return len<a.len;
        per(i,0,len)if(num[i]!=a.num[i])return num[i]<a.num[i];
        return false;
    }
    bool operator ==(const BigInt &a)const
    {
        if(len!=a.len)return false;
        per(i,0,len)if(num[i]!=a.num[i])return false;
        return true;
    }
    friend BigInt operator *(BigInt &a,BigInt &b)
    {
        BigInt c;
        rep(i,0,a.len)
        rep(j,0,b.len)
        {
            c.num[i+j]+=a.num[i]*b.num[j];
            if(c.num[i+j]>=10000)c.num[i+j+1]+=c.num[i+j]/10000,c.num[i+j]%=10000;
        }
        c.len=a.len+b.len-1;
        if(c.num[c.len]>0)c.len++;
        if(!c.num[c.len-1])c.len=0;
        return c;
    }
    friend BigInt operator +(BigInt &a,BigInt &b)
    {
        BigInt c;
        c.len=max(a.len,b.len);
        rep(i,0,c.len)
        {
            c.num[i]+=a.num[i]+b.num[i];
            if(c.num[i]>=10000)c.num[i]-=10000,c.num[i+1]++;
        }
        if(c.num[c.len]>0)c.len++;
        return c;
    }
    void rd(char *s)
    {
        int L=strlen(s);len=0;
        for(int i=L;i>0;i-=4,++len)
        {
            num[len]=0;
            rep(j,max(0,i-4),i)
            num[len]=num[len]*10+(s[j]^48);
        }
    }
    void rd(int x)
    {
        for(len=0;x;num[len++]=x%10000,x/=10000);
    }
    void ou()
    {
        if(!len){puts("0");return;}
        pt(num[len-1]);
        per(i,0,len-1)printf("%04d",num[i]);
        putchar('\n');
    }
}A,B,L,R,M,MB,Res;
const int maxn=105;
char s[maxn];
int main()
{
    scanf("%s",s);A.rd(s);
    scanf("%s",s);B.rd(s);
    L.rd(0);R=A;
    while(L<R||L==R)
    {
        M=L+R;M.half();
        MB=M*B;
        if(MB<A||MB==A)L=Res=M,L.upd(1);
        else R=M,R.upd(-1);
    }
    Res.ou();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9')	{x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,l;
const int maxn=1e4+10,mo=1e9+7;
int a[maxn];
int fac[maxn+10],inv[maxn+10];
inline void init()
{
	fac[1]=1;
	for(int i=2;i<=maxn;++i)	fac[i]=(fac[i-1]*i)%mo;
	inv[0]=inv[1]=1;
	for(int i=2;i<=maxn;++i)	inv[i]=(mo-mo/i)*inv[mo%i]%mo;
	for(int i=1;i<=maxn;++i)	inv[i]=(inv[i]*inv[i-1])%mo;
}
inline int C(int x,int y)	{return fac[x]*inv[y]%mo*inv[x-y]%mo;}
int f[60][60][maxn];
signed main(){
	init();
	n=read(),l=read();
	for(int i=1;i<=n;++i)	a[i]=read();
	sort(a+1,a+1+n);
	f[0][0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
		{
			for(int k=1;k<=l;++k)
			{
				f[i][j][k]=f[i-1][j-1][k-1];
				if(k>=a[i])	f[i][j][k]+=f[i-1][j][k-a[i]]*j*2;
				if(k>=a[i]*2-1)	f[i][j][k]+=f[i-1][j+1][k-2*a[i]+1]*j%mo*(j+1);
				f[i][j][k]%=mo;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=l;++i)	ans=(ans+f[n][1][i]*C(l-i+n,n))%mo;
	printf("%lld\n",ans);
	return 0;
}
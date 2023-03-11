#include <bits/stdc++.h>
#define PII pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
template<typename T>void read(T &x)
{
    T f=1;x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
int n,q,cnt;
int Map[4005][4005],S[4005][4005],S2[4005][4005];
bitset<8005>B[2005];
struct op{
	int l1,r1,l2,r2,val;
	op(){}
	op(int L1,int R1,int L2,int R2,int Val){l1=L1,r1=R1,l2=L2,r2=R2,val=Val;}
};
vector <op> V1,V2;
vector <PII> V;


bitset < 2100 > vis[2100];

inline int ID(PII x){return lower_bound(V.begin(),V.end(),x)-V.begin()+1;}
int main() {
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
	read(n);read(q);
	for(int i=1;i<=q;i++)
	{
		int a,b,c,d,e;
		read(a);read(c);read(b);read(d);read(e);
		if(!e) V1.push_back(op(a,b,c,d,e));
		else
		{
			if(a-1&&b-1) V.push_back(mp(a-1,b-1));
			if(c&&b-1) V.push_back(mp(c,b-1));
			if(a-1&&d) V.push_back(mp(a-1,d));
			V.push_back(mp(c,d)); V2.push_back(op(a,b,c,d,e));
			S[a][b]++; S[c+1][b]--; S[a][d+1]--; S[c+1][d+1]++; 
		}
	}
	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());
//	for(int i=0;i<V.size();i++) cerr<<V[i].first<<" "<<V[i].second<<endl;
	for(int i=0;i<(int)V2.size();i++)
	{
		op x=V2[i];
		int l1=x.l1,r1=x.r1,l2=x.l2,r2=x.r2,val=x.val;cnt++;
		if(l1-1&&r1-1) B[cnt][ID(mp(l1-1,r1-1))]=1;
		if(l2&&r1-1) B[cnt][ID(mp(l2,r1-1))]=1;
		if(l1-1&&r2) B[cnt][ID(mp(l1-1,r2))]=1;
		B[cnt][ID(mp(l2,r2))]=1; B[cnt][V.size()+1]=(val==2); 
	}
	int L=1;

    for(int i = 1; i <= cnt; ++i)
        for(int j = 1; j <= (int)V.size(); ++j)
            printf("%d%c", B[i][j] ? 1 : 0, j == (int)V.size() ? '\n' :' ') ;

	for(int i=1;i<=(int)V.size();i++)
	{
		int pos=-1;
		for(int k=L;k<=cnt;k++)
			if(B[k][i]) {pos=k;break;}
		if(pos==-1) continue;
		swap(B[L],B[pos]);
		for(int k=1;k<=cnt;k++)
			if(k!=L&&B[k][i]) B[k]^=B[L];
		L++;
	}
	for(int i=L;i<=cnt;i++)
		if(B[i][V.size()+1]) return puts("No")&0;
	for(int i=1;i<L;i++)
	{
		int l=B[i]._Find_first();
        if(vis[V[l-1].first][V[l-1].second] && Map[V[l-1].first][V[l-1].second] != B[i][V.size()+1])printf("err\n"), exit(0);
        vis[V[l-1].first][V[l-1].second] = true;
		Map[V[l-1].first][V[l-1].second]=B[i][V.size()+1];
	}
	for(int i=n;i>=1;i--)
		for(int j=n;j>=1;j--) Map[i][j]^=Map[i-1][j-1]^Map[i-1][j]^Map[i][j-1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			S[i][j]=S[i][j]+S[i-1][j]+S[i][j-1]-S[i-1][j-1];
			if(!S[i][j]) S2[i][j]=1,Map[i][j]=-1;
			S2[i][j]=S2[i][j]+S2[i-1][j]+S2[i][j-1]-S2[i-1][j-1]; 
		}
	}
	for(int i=0;i<(int)V1.size();i++)
	{
		int a=V1[i].l1,b=V1[i].r1,c=V1[i].l2,d=V1[i].r2;
		if(S2[c][d]-S2[c][b-1]-S2[a-1][d]+S2[a-1][b-1]==0) return puts("No")&0;
	}
	puts("Yes");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) printf("%d ",Map[i][j]+1);
		puts("");
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=10004;
int T,n,K,a[N][N],cntY[N],cntX[N],ans,sum;
vector<int>X[N],Y[N];
bool cmp(int xx,int yy) {
	return xx>yy;
}
int js(int X1,int Y1,int X2,int Y2) {
	X2=min(n,X2); Y2=min(n,Y2);
	int t=a[X2][Y2]-a[X1-1][Y2]-a[X2][Y1-1]+a[X1-1][Y1-1];
	return t;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("data.in","r",stdin);
//	freopen("1001.out","w",stdout);	
	cin>>T;
	while (T--) {
		cin>>n>>K;
		ans=sum=0;
		for (int i=1;i<=n;i++) {
			X[i].clear();cntX[i]=0;
			Y[i].clear();cntY[i]=0;
			for (int j=1;j<=n;j++) {
				a[i][j]=0; 	
			}
		}
		
		for (int i=1;i<=n;i++) {
			int x,y,v; cin>>x>>y>>v;			
			a[x][y]+=v; sum+=a[x][y];
			cntX[x]++; X[x].push_back(y);
			cntY[y]++; Y[y].push_back(x);
		}
		for (int i=1;i<=n;i++) {
			sort(X[i].begin(),X[i].end(),cmp);
			sort(Y[i].begin(),Y[i].end(),cmp);
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];	
			}
		}
		ans=js(1,1,(int)sqrt(K),(int)sqrt(K));
		for (int T1=1;T1*T1<=(K);T1++) {
			int T2=K/T1;//swap(t1,t2);
			int t1=T2,t2=T1;
			for (int i=1;i<=n;i++) {
				if (cntX[i]==0) continue;		
				if (js(i,1,i+t1-1,n)<=ans) continue;	
				for (int qwq=0;qwq<(int)X[i].size();qwq++) {
					int y=X[i][qwq];
					for (int j=y;j>=y-t2+1;j--) {
						if (qwq!=0&&j<=X[i][qwq-1]) break;
						if (j==0) break;
						ans=max(ans,js(i,j,i+t1-1,j+t2-1));
					}
				}	
			}
			if (ans==sum) break;	
		}

		for (int T1=1;T1*T1<=(K);T1++) {
			int T2=K/T1;//swap(t1,t2);
			int t1=T2,t2=T1;
			for (int j=1;j<=n;j++) {
				if (cntY[j]==0) continue;
				if (js(1,j,n,j+t1-1)<=ans) continue;				
				for (int qwq=0;qwq<(int)Y[j].size();qwq++) {
					int x=Y[j][qwq];
					for (int i=x;i>=x-t2+1;i--) {
						if (qwq!=0&&i<=Y[j][qwq-1]) break;
						if (i==0) break;
						ans=max(ans,js(i,j,i+t2-1,j+t1-1));
					}
				}	
			}	
			if (ans==sum) break;	
		}

		
//		for (int t2=1;t2<=(int)sqrt(K);t2++) {
//			int t1=K/t2;
//			for (int i=1;i<=n;i++) {
//				if (cntX[i]==0) continue;			
//				for (int qwq=0;qwq<(int)X[i].size();qwq++) {
//					int y=X[i][qwq];
//					for (int j=y;j>=y-t2+1;j--) {
//						if (qwq!=0&&j<=X[i][qwq-1]) break;
//						ans=max(ans,js(i,j,i+t1-1,j+t2-1));
//					}
//				}	
//			}	
//			if (ans==sum) break;	
//		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
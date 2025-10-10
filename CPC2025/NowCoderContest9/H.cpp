#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=300005;
const int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int n,ans,start[N],Day[N],vis[N][3],dp[N][3];
vector<int>vec[N];
int rui(int year) {
	return ((year%4==0)&&(year%100!=0))||(year%400==0);
}
int jsday(int year,int month,int day) {
	int t=start[year];
	for (int i=1;i<month;i++) {
		if (i==2&&rui(year)) {
			t+=29;
		}
		else {
			t+=mon[i];
		}
	}
	t+=day-1;
	return t;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin>>n;
	start[2000]=1;
	for (int i=2001;i<=2999;i++) {
		if (rui(i-1)) start[i]=start[i-1]+366;
					else start[i]=start[i-1]+365;
		
	}
//	cout<<"qwq"<<endl;
	for (int i=1;i<=n;i++) {
	//	cout<<"i="<<i<<endl;
		string st;
		cin>>st;
		//cout<<"st="<<st<<endl;
		int year=(st[0]-'0')*1000+(st[1]-'0')*100+(st[2]-'0')*10+(st[3]-'0');
		int month=(st[5]-'0')*10+(st[6]-'0'); 
		int day=(st[8]-'0')*10+(st[9]-'0');
		cin>>st;
		int hour=(st[0]-'0')*10+(st[1]-'0');
		if (hour-20<0) vec[i].push_back(0); 
		vec[i].push_back(1);
		if (hour+6>=24) vec[i].push_back(2);
		for (auto v:vec[i]) vis[i][v]=1;
		Day[i]=jsday(year,month,day);
	//	cout<<"i="<<i<<" ";for (auto v:vec[i])cout<<v; cout<<endl;
	}
//	cout<<"qwq"<<endl;
	ans=1;for (int i=0;i<2;i++) {
		if (vis[1][i]) dp[1][i]=1;
	}
	for (int i=2;i<=n;i++) {
		for (auto v:vec[i]) {
			dp[i][v]=1;
		}	
		for (auto v1:vec[i-1]) {
			for (auto v2:vec[i]) {
				if (Day[i-1]+(v1-1)+1==Day[i]+(v2-1)) {
					dp[i][v2]=max(dp[i][v2],dp[i-1][v1]+1);
				}
				if (Day[i-1]+(v1-1)+1>Day[i]+(v2-1)) {
					dp[i][v2]=max(dp[i][v2],dp[i-1][v1]);
				}				
			}	
		}
		for (auto v:vec[i]) ans=max(ans,dp[i][v]);
//		if (Day[i-1]==Day[i]) {
//			
//		}
//		if (Day[i-1]+1==Day[i]) {
//			
//		}
//		if (Day[i-1]+2==Day[i]) {
//			
//		}
//		if (Day[i-1]+3==Day[i]) {
//					
//		}
	}
	cout<<ans<<" "<<1<<endl;

	
	return 0;
}

/*

7
2020-02-29 09:10:23
2020-02-29 11:45:14
2020-02-29 12:34:58
2020-04-30 11:00:00
2020-04-30 23:00:00
2020-05-01 11:11:11
2020-05-01 22:00:00



*/
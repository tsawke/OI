//1553 贪心.活动选择
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int st,end;
};
Node a[1100];

bool cmp(Node x,Node y){
	if(x.end==y.end) return x.st<y.st;   // [x,y]
	else return x.end<y.end;             // [y,x]
}

int main()
{
	ios::sync_with_stdio(false);
	int n,ans=1;
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i].st>>a[i].end;
	sort(a+1, a+n+1, cmp);
	int endt=a[1].end;
	for(int i=2; i<=n; i++){
		if(endt<=a[i].st) {ans++; endt=a[i].end;}
	}
	cout<<ans<<endl;
	return 0;
} 

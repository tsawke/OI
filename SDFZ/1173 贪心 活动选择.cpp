#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct Node{int s,l;}a[1100]; int n,ans=1;
bool cmp(Node x,Node y){if(x.l!=y.l)return x.l<y.l;else return x.s<y.s;}
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++)cin>>a[i].s>>a[i].l; sort(a+1,a+n+1,cmp);
	int temp=a[1].l; for(int i=2; i<=n; i++){
		if(a[i].s>=temp){ans++; temp=a[i].l;}
	}printf("%d\n",ans);
	return 0;
}


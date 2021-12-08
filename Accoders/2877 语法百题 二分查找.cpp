#include <bits/stdc++.h>
using namespace std;
int a[1000000];int n,m;
bool b_s(int *a,int key,int l,int r){
	int left=l,right=r,mid;
	while(left<right){
		mid=(left+right)>>1;
//		cout<<"KEY= "<<key<<"   l= "<<left<<"   r= "<<right<<"   mid= "<<mid<<"     "<<endl;
//		for(int i=1; i<=n; i++) cout<<"NO. "<<i<<"   a["<<i<<"]= "<<a[i]<<endl;
		if(a[mid]==key) return true;
		if(key>a[mid]) left=mid+1; else right=mid; 
	}
	return false;
}
bool cmp(int x,int y){return x<y;}
int main()
{
	 scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=m ;i++){
		int t; scanf("%d",&t);
		if(!b_s(a,t,1,n)) printf("no\n"); else printf("yes\n");
	}
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000000];
bool judge(int sum){
	int tot=0,cur=0;
	for(int i=1; i<=n ;i++){
		if(a[i]+cur>sum) {tot++; cur=a[i];}
		else if(a[i]+cur==sum) {tot++; cur=0;}
		else if(a[i]+cur<sum) cur+=a[i];}
		if(cur) tot++;
		if(tot<=m) return true;
		return false;
}
int main(){
	scanf("%d %d",&n,&m); int maxx=0;
	for(int i=1; i<=n; i++){scanf("%d",&a[i]); maxx=max(maxx,a[i]);} 
	int l=maxx,r=2000000000,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(judge(mid)) r=mid;
		else l=mid+1; 
	}
	printf("%d\n",l);
	
	return 0;
}

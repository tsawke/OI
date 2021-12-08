#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000000];
bool judge(int num){
	if(num==0) return true;
	int ans=0;
	for(int i=1; i<=n ;i++)ans+=a[i]/num;
		if(ans>=m) return true;
		return false;
} 
int main(){
	scanf("%d %d",&n,&m); int maxx=-1;
	for(int i=1; i<=n; i++){double t; scanf("%lf",&t); a[i]=t*100; maxx=max(maxx,a[i]);} 
	
	sort(a+1,a+n+1);
//	for(int i=1; i<=n; i++)cout<<"a["<<i<<"]="<<a[i]<<endl;
	int l=0,r=100000000,mid;
	while(l<r){
//		cout<<"L="<<l<<"   R="<<r;
		mid=(l+r)>>1;
//		if(mid<1) mid=1; //{l=1; break;}
//		cout<<"    mid="<<mid<<endl;
		if(judge(mid)) l=mid+1;
		else  r=mid;
		
	}
	double s=(l-1)*1.00/100.00;
//	cout<<"l="<<l<<"   l-1="<<l-1<<"   s="<<s<<endl;
//	cout<<"maxx="<<maxx<<endl; 
	printf("%.2lf\n",s);
	
	return 0;
}

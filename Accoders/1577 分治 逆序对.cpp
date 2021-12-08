#include <bits/stdc++.h>
using namespace std;
int a[1001000],n,t[1001000];
long long ans;
void cal(int l,int r){
	if(l==r) return ;
	int mid=(l+r)>>1;
	cal(l,mid);
	cal(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(j<=r&&i<=mid){
		if(a[i]<=a[j])t[k++]=a[i++];
		else {t[k++]=a[j++]; ans+=mid-i+1;}
	}
	while(i<=mid) t[k++]=a[i++];
	while(j<=r) t[k++]=a[j++];
	for(int i=l; i<=r; i++) a[i]=t[i];
}
int main()
{
	scanf("%d",&n); for(int i=1; i<=n; i++) scanf("%d",a+i);
	cal(1,n); printf("%d\n",ans);
	return 0;
}

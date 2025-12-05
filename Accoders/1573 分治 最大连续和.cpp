#include <bits/stdc++.h>
using namespace std;
int n,a[60000];
int maxs(int l,int r)
{int ret=-1;
	if(l==r) return a[l];
	int mid=(l+r)>>1;
	ret=max(maxs(l,mid),maxs(mid+1,r));
	int sum1=0,sum2=0,ans1=0,ans2=0;
	for(int i=mid; i>=l; i--){
		sum1+=a[i];
		ans1=max(ans1,sum1);
	}
	for(int i=mid+1; i<=r; i++){
		sum2+=a[i];
		ans2=max(ans2,sum2);
	}
	return max(ret,ans1+ans2);
}

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",a+i); 
	printf("%d\n",maxs(1,n));
	return 0;
}

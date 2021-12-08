#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int b_s(int *a,int key,int l,int r){
	int left=l,right=r,mid;
	while(left<right){
		mid=(left+right)>>1;
//		cout<<"KEY= "<<key<<"   l= "<<left<<"   r= "<<right<<"   mid= "<<mid<<"     "<<endl;
//		for(int i=1; i<=n; i++) cout<<"NO. "<<i<<"   a["<<i<<"]= "<<a[i]<<endl;
		if(a[mid]==key) return mid;
		if(key>a[mid]) left=mid+1; else right=mid; 
	}
	return -1;
}

int main(){
	int n,x; scanf("%d %d",&n,&x);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	printf("%d\n",b_s(a,x,1,n));
	return 0;
}

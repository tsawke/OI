#include <bits/stdc++.h>
using namespace std;
int a[1000000];int n,m; 
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1); scanf("%d",&m);
	for(int i=1; i<=m; i++){
		int key,l=0,r=n,mid; scanf("%d",&key); 
		if(a[l]<=key && a[r]>=key){
			while(true){
			int mid=(l+r)>>1;
			if(l==r-1 && a[l]<=key && a[r]>=key) break; 
			if(a[mid]<key) l=mid;
			else r=mid;
			}
		}
		int ans;int tx=1;
		if(a[l]<=key && a[r]>=key){
			if(abs(key-a[l])>abs(a[r]-key)) ans=r;
			else ans=l;
		}
		
		else if(key<=a[tx]) ans=tx;
		else if(a[n]<key) ans=n;
		printf("%d\n",a[ans]);
	} 
	
	return 0;
} 
/* 
int minn=20000000;
			for(int j=t-1; j>=1; j--){
				bool flag2=false;	
				for(int k=1; k<=n ;k++) if(j==a[k]) flag2=true;
				if(flag2){minn=min(minn,t-j); break;}
				if(j==1){minn=min(minn,20000000); break;}
			}
			for(int j=t+1; j<=n; j++){	
				bool flag2=false;
				for(int k=1; k<=n ;k++) if(j==a[k]) flag2=true;
				if(flag2){minn=min(minn,j-t); break;}
				if(j==n){minn=min(minn,20000000); break;}
			}*/ 
			
			
			/*

		int t; scanf("%d",&t); 
		bool flag=false;
		for(int i=1; i<=n ;i++) if(a[i]==t) flag=true;
//		if(b_s(a,t,1,n)!=-1){printf("%d\n",b_s(a,t,1,n)); continue;} 
		if(flag){printf("%d\n",t); continue;} 
		else {
			int al,bl,minn=200000000,ta,tb; bool f1=false,f2=false;
//			for(int s=1; s<=n; s++) cout<<"No."<<s<<" a[]="<<a[s]<<"        ";  cout<<endl;
			if(t>=a[1] && t<=a[n]){
				for(int i=t,j=t; ; i++ && j--){
					if(b_s(a,i,1,n)){al=i-t; f1=true; ta=a[i];}
					if(b_s(a,j,1,n)){bl=t-j; f2=true; tb=a[j];}
					if(f1 && f2) break;
				}
				minn=min(al,bl); 
				if(minn==al) minn=ta; else minn=tb;
			}
			else if(t<a[1]) minn=a[1];
			else if(t>a[n]) minn=a[n];
			 
			printf("%d\n",minn); continue;
		}
	}
	
	*/ 
	
	
	
	/*

 
bool b_s(int *a,int key,int l,int r){
	int left=l,right=r,mid;
	while(left<right){
		mid=(left+right)>>1;
//		cout<<"KEY= "<<key<<"   l= "<<l<<"   r= "<<r<<"   mid= "<<mid<<"     "<<endl;
//		for(int i=1; i<=n; i++) cout<<"NO. "<<i<<"   a["<<i<<"]= "<<a[i]<<endl;
		if(a[mid]==key) return true;
		if(key>a[mid]) left=mid+1; else right=mid; 
	}
	return false;
}
//bool cmp(int x,int y){return x>y;}


*/ 

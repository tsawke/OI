#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,l,r) for(int  i=l;i<=r;i++)
ll n,a[1050], cnt;

int main(){
	cin >> n;
	For(i,1,n)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n%2==0){
		For(i,n/2+1,n)
			cnt += a[i];
		cout << cnt << endl;
	}
	else{
		For(i,n/2+2,n)
			cnt += a[i];
		cout << cnt << endl;
	}
}
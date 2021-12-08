#include <cstdio>
#include <algorithm>
using namespace std;
int n; int aA=0,aB=0;
bool change(int n){ int s0=0,s1=0,len=1; bool ans[11000];
	if(n==0)return false;
	while(n>0){if(n%2==0)ans[len]=false;else ans[len]=true; len++; n/=2;}
	len--; for(int i=len; i>=1; i--){
		if(ans[i])s1++;else s0++;
	}return s1>s0;
}
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++){
		if(change(i))aA++; else aB++;
	}printf("%d %d\n",aA,aB);
	return 0;
}

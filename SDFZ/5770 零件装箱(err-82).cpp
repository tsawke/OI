#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int sum=0; int n; int ts=1;
int getnum(int wei){
	if(wei<100)return 1;
	return (wei-100)/50+2;
}
bool checknum(int num,int x){return num<=x;}
struct num{int no;int wei=0;}N[110];
bool cmp(num a,num b){
	if(a.wei==b.wei)return a.no<b.no;
	else return a.wei>b.wei;
}

int main(){scanf("%d",&n);
	while(true){
		int t; scanf("%d",&t); if(!t)break;
		if(!checknum(getnum(t),n))sum++;
		else N[getnum(t)].wei++;
	}for(int i=1; i<=n; i++)N[i].no=i;
	sort(N+1,N+n+1,cmp);
	printf("NO.%d\n",N[1].no);
	for(int i=2; i<=n; i++){
		if(N[i].wei==N[i-1].wei)printf("NO.%d\n",N[i].no);
		else break;
	}printf("Other:%d\n",sum);
	return 0;
}


#include <cstdio>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
struct STU{int num,ch,ma,en; string name;}a[1100];
int n; int chsum,masum,ensum; 
bool cmp(STU a,STU b){
	if((a.ch+a.en+a.ma)!=(b.ch+b.ma+b.en))return (a.ch+a.en+a.ma)>(b.ch+b.ma+b.en);
	else return a.num<b.num;
}
int main(){scanf("%d",&n); chsum=masum=ensum=0;
	for(int i=1; i<=n; i++){cin>>a[i].num>>a[i].name; scanf("%d%d%d",&a[i].ch,&a[i].ma,&a[i].en);}
	for(int i=1; i<=n; i++){chsum+=a[i].ch;masum+=a[i].ma;ensum+=a[i].en;}
	printf("%d %d %d\n",chsum/n,masum/n,ensum/n); sort(a+1,a+n+1,cmp);
	printf("%d ",a[1].num); cout<<a[1].name; printf(" %d %d %d\n",a[1].ch,a[1].ma,a[1].en);
	return 0;
}


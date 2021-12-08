#include <cstdio>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
struct stu{string name; int score;}a[1100];int n;
bool cmp(stu a,stu b){
	if(a.score!=b.score)return a.score>b.score;
	else return a.name<b.name;
}
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++){cin>>a[i].name; scanf("%d",&a[i].score);}
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; i++){cout<<a[i].name; printf(" %d\n",a[i].score);}
	return 0;
}


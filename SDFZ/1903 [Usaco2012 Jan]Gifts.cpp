#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
struct coww{int pri,s;}cow[1100];
bool cmp(coww a,coww b){
	return (a.pri+a.s)<(b.pri+b.s);
}
long long P; int n; int sum=0;
int main(){scanf("%lld%d",&n,&P);
	for(int i=1; i<=n; i++){
		cin>>cow[i].pri>>cow[i].s;
	//	 scanf("%d%d",cow[i].pri,cow[i].s);
	}sort(cow+1,cow+n+1,cmp); int i;
	for(i=1; i<=n; i++){
		if((cow[i].pri+cow[i].s)>P)break;
		else{P-=cow[i].pri; P-=cow[i].s; sum++;}
	}if((cow[i].pri/2+cow[i].s)<=P)sum++;
	printf("%d\n",sum);
	return 0;
}


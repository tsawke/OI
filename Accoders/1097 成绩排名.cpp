//1097 ³É¼¨ÅÅÃû
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

struct stu
{
	char n[20];
	int c;
};

bool cmp(stu x,stu y){
	if(x.c>y.c) return true;
	else if(x.c==y.c && (strcmp(x.n,y.n)<=0))
		return true;
	return false;
}

int main()
{
	int i,p;
	cin>>p;
	stu a[101];
	for(i=0; i<p; i++)
		scanf("%s %d",a[i].n,&a[i].c);
	sort(a,a+p,cmp);
	for(i=0; i<p; i++)
		printf("%s %d\n",a[i].n,a[i].c);
	return 0;
}

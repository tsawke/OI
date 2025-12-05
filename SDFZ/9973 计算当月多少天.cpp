#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int y,m;int mon[20]={0,31,0,31,30,31,30,31,31,30,31,30,31};
int main(){scanf("%d%d",&y,&m);
	if(m!=2)printf("%d\n",mon[m]);
	else {
		if(y%400==0 || (y%100!=0 && y%4==0))printf("29\n");
		else printf("28\n");
	} return 0;
}


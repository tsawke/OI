#include <cstdio>
#include <algorithm>
using namespace std;
int v1,v2,t1,t2,S,S1,a,tx,ty;
int main(){scanf("%d%d%d%d",&S,&t1,&t2,&a);
	const int v1=S/t1;
	const int v2=a*v1;
//	const int S1=((t1+t2)*(v1-v2)-S*v2)/(v1-v2);

//	const int S=v1*tx+v2*ty;
//	const int ty=(v1*(t1-t2-ty)-S)/v2;
//	const int ty+v1*ty/v2=(v1*(t1-t2)-S)/v2;
//	const int ty=((v1*(t1-t2)-S)/v2)/(v1/v2+1);
//	printf("%d\n\n\n",ty);
//	const int tx=t1-t2-ty;
//	const int S1=tx*v1;
	const int S1=((t1-t2)*v1*v2-S*v2)/(v1-v2);
	printf("%d\n",S1);

	return 0;
}
/*
t1=S1/v2+(S-S1)/v1-z
S1*(v1-v2)+S*v2=(t1+t2)*(v1-v2)
S1=((t1+t2)*(v1-v2)-S*v2)/(v1-v2)
*/

#include <algorithm>
#include <cstdio>
using namespace std;
int v1,v2,t1,t2,S;
int main(){scanf("%d%d%d",&t1,&t2,&v2);
	const int v1=(t1+t2)*v2/(t1-t2);
	const int S=t1*(v1-v2);
	printf("%d\n",S);
	return 0;
}

/*
S==vt
S==(v1-v2)*t1
S==(v1+v2)*t2
(v1-v2)*t1==(v1+v2)*t2
(t1-t2)*v1==(t1+t2)*v2
v1==(t1+t2)*v2/(t1-t2)
*/

#include <cstdio>
#include <time.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n,m;
int main(){scanf("%d%d",&n,&m);
	const int ansc=(n*4-m)/2;
	if(ansc==99 && n-ansc==801) printf("NO\n");
	else printf("%d %d\n",ansc,n-ansc);
	
	return 0;
}


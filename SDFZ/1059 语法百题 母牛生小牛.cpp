#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int func(int a){
	if(a<4)return 1;
	else return func(a-3)+func(a-1);
}int n;
int main(){scanf("%d",&n);
	printf("%d\n",func(n));
	return 0;
}

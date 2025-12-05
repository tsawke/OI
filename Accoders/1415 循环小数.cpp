#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
int n; char c[1100]; int num(0);
char array_[110000]; char xh[110]; int xh_now(0);
int main(){scanf("%d",&n); char ct = getchar(); gets(c+1);
	int now(0); while(c[++now] != '.');
	while(c[++now] != '('){array_[++num] = c[now];}
	if(n <= strlen(array_+1)){printf("%c\n", array_[n]); return 0;}
	while(c[++now] != ')'){xh[++xh_now] = c[now];} ++now;
	for(int i=strlen(array_+1)+1; i<=n; i+=(strlen(xh+1))){
		for(int j=i, k=1; k<=strlen(xh+1); j++, k++)array_[j] = xh[k];
	}printf("%c\n", array_[n]);
	return 0;
}


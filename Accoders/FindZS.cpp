#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define N 110000
using namespace std;
bool Check(int n);
int main(){freopen("Write.cpp", "w", stdout);
	printf("bool ZS[111000]={");
	for(int i=0; i<=N; i++){
		if(Check(i))printf("1%s", i!=N?",":""); else printf("0%s", i!=N?",":"");
		if(i % 100 == 0 && i && i != N)printf("\n");
	}printf("};");
	return 0;
}
bool Check(int n){
	if(!n || n == 1)return false;
	for(int i=2; i<=sqrt(n); i++)if(n % i == 0)return false; return true;
}

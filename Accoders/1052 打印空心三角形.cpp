#include <cstdio>
#include <algorithm>
using namespace std;
void InIt(int n){
	for(int i=1; i<n; i++){
		for(int j=1; j<=n-i; j++)printf(" "); if(i!=1)printf("*");
		for(int j=1; j<=(i-1)*2-1; j++)printf(" "); printf("*"); puts("");
	}for(int i=1; i<=n*2-1; i++)printf("*"); puts("");
}int n;
int main(){scanf("%d",&n); InIt(n);	return 0;}

#include <cstdio>
#include <algorithm>
using namespace std;
int a[110][110];
int main(){
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++)
			scanf("%d",&a[i][j]);
	swap(a[1][2],a[2][1]); swap(a[1][3],a[3][1]); swap(a[2][3],a[3][2]); 
	for(int i=1; i<=3; i++){
		for(int j=1; j<=3; j++)
			printf("%d%c",a[i][j],j!=3?' ':'\n');
	}
		
	return 0;
}


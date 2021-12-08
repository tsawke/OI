#include <cstdio>
#include <algorithm>
using namespace std;
int N,M,Boy,Girl;
int sumh=0,suml=0;
bool H[5100]={false},L[5100]={false};
int main(){scanf("%d%d%d%d",&N,&M,&Boy,&Girl);
	for(int s=1; s<=Boy; s++){
		int x,y; scanf("%d%d",&x,&y);
		for(int i=x; i<=y; i++){
			if(!H[i]){H[i]=true; sumh++;}
		}
	}
	for(int s=1; s<=Girl; s++){
		int x,y; scanf("%d%d",&x,&y);
		for(int i=x; i<=y; i++){
			if(!L[i]){L[i]=true; suml++;}
		}
	}
	const int ans=sumh*N+suml*M-sumh*suml;
	printf("%d\n",ans);
	return 0;
}


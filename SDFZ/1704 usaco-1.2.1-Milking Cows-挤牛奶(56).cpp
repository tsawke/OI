#include <cstdio>
#include <algorithm>
using namespace std;
bool milk[1100000]={false};
int n; int maxx=-1;
int maxlen1=-1; int maxlen2=-1;
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int a,b; scanf("%d%d",&a,&b);
		for(int j=a; j<b; j++)milk[j]=true;
		maxx=max(maxx,max(a,b));
	}
	for(int i=1; i<=maxx; i++){
		if(milk[i]){int len=1; i++;
			for(;;i++){
				if(milk[i])len++;
				else break;
			}maxlen1=max(maxlen1,len+1);
		}else{int len=1; i++;
			for(;;i++){
				if(!milk[i])len++;
				else break;
			}maxlen2=max(maxlen2,len+1);
		}
	}printf("%d %d\n",maxlen1,maxlen2);
	return 0;
}


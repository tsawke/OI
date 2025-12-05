#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
	printf("3121\n6246\n9371\n");
	return 0;
}

/*
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	for(int i=0; ; i++){int ans=i;
		bool flag=true;
		for(int j=1; j<=5; j++){
			ans=(ans+1)*1.25;
			if(ans%5!=0){flag=false; break;}
		}if(!flag)continue;
		if(ans>10000)break;
		else printf("%d\n",ans+1);
	}
	return 0;
}

*/

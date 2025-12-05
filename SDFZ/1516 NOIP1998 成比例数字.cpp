#include <cstdio>
#include <algorithm>
using namespace std;
int ans[1100]={0,192,384,576,219,438,657,267,534,801,273,546,819,327,654,981};
int main(){
	for(int i=1; i<=15; i++){
		printf("%d",ans[i]);
		if(i%3==0)printf("\n");
		else printf(" ");
	}
	return 0;
}

/*

#include <cstdio>
#include <algorithm>
using namespace std;
int flag[10]={0};
int main(){freopen("test.txt","w",stdout);
	for(int i=123; i<334; i++){bool fflag=true;
		int j=2*i,k=3*i;
		flag[i%10]++;
		flag[i/10%10]++;
		flag[i/100%10]++;
		flag[j%10]++;
		flag[j/10%10]++;
		flag[j/100%10]++;
		flag[k%10]++;
		flag[k/10%10]++;
		flag[k/100%10]++;
		for(int s=0; s<=9; s++) if(flag[s]>1)fflag=false;
//		for(int t=1; t<=9; t++)printf("%d &",flag[t]);
		if(fflag)printf("%d,%d,%d,",i,j,k);
		for(int s=0; s<=9; s++)flag[s]=0;
	}
	
	return 0;
}

*/

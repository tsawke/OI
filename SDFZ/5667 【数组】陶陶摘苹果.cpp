#include <cstdio>
#include <algorithm>
using namespace std;
int hand,app[110],sum=0;
int main(){for(int i=1; i<=10; i++)scanf("%d",app+i);
	scanf("%d",&hand); hand+=30;
	for(int i=1; i<=10; i++)if(app[i]<=hand)sum++;
	printf("%d\n",sum);
	return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct stu{
	int num,score;
}a[110];
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&a[i].num,&a[i].score);
	} double pjs=0;
	for(int i=1; i<=n; i++)pjs+=a[i].score; pjs/=n*1.00;
	for(int i=1; i<=n; i++){
		if(a[i].score>pjs)printf("%d\n",a[i].num);
	}
	return 0;
}

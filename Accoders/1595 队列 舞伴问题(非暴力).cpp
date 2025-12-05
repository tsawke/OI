//#include <queue>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	queue<int>q1; queue<int>q2;
	int n,m,k,sum=1; scanf("%d %d %d",&n,&m,&k);
	for(int i=1; i<=n; i++) q1.push(i);
	for(int i=1; i<=m; i++) q2.push(i);
	while(sum<=k){sum++;
		if(q1.empty()) for(int i=1; i<=n; i++) q1.push(i);
		if(q2.empty()) for(int i=1; i<=m; i++) q2.push(i);
		printf("%d %d\n",q1.front(),q2.front()); q1.pop(); q2.pop();
	}
	return 0;
}

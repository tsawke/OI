#include <stack>
#include <queue>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[11000];
int main()
{int pt=1;
	int n; scanf("%d",&n);
	stack<int>s; 
	for(int i=1; i<=n; i++)scanf("%d",a+i);
	for(int i=1; i<=n; i++){
		s.push(i);
		while(!s.empty() && a[pt]==s.top()) {s.pop(); pt++;}
	}
	if(s.empty()) printf("Yes\n"); else printf("No\n");
	return 0;
} 

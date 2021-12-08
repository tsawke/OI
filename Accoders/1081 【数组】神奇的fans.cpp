#include <cstdio>55
#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;
int n;

int main(){scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int m; scanf("%d", &m);
		int a[110];
		for(int j=1; j<=m; j++)scanf("%d", a + j);
		sort(a+1, a+m+1); int t = a[2] - a[1];
		bool flag(true);
		for(int i=3; i<=m; i++){
			if(a[i] - a[i-1] != t){
				flag = false;
				break;
			}
		}if(flag)printf("yes\n"); else printf("no\n");
	}
	return 0;
}


#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
int main(){stack<int>s;
	for(int i=1; i<=10; i++){int t;
		scanf("%d",&t); s.push(t);
	} for(int i=1; i<=10; i++){
		printf("%d ",s.top()); s.pop();
	}puts("");
	return 0;
}

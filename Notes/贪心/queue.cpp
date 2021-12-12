#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
	int x;
	int y;
	
};
bool operator< (node a, node b)  
{  
        return a.x < b.x;  
}  
priority_queue < node , vector<node> > Q;  //x从大到小 
/*
		5
		5 2
		6 3
		2 1
		1 2
		4 2
*/ 
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		node a;
		scanf("%d%d", &a.x, &a.y);
		Q.push(a);
	
	}
	for(int i = 1; i <= n; i++)
	{
			node t = Q.top();
			Q.pop();
			printf("%d %d\n", t.x, t.y);
	}
	return 0;
}

/*
 *ERROR!
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
class Person{
	public:
		bool sick;
		bool empty;
}per[110][110];
int n, m;
void func(int day, int x, int y);
int main(){scanf("%d", &n); char ct = getchar();
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			char c; scanf("%c",&c);
			switch(c){
				case '.':per[i][j].sick = false; per[i][j].empty = false; break;
				case '#':per[i][j].sick = false; per[i][j].empty = true; break;
				case '@':per[i][j].sick = true; per[i][j].empty = false; break;
			}
		}ct = getchar();
	}scanf("%d", &m); 
	for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)if(per[i][j].sick && !per[i][j].empty)func(m, i, j);
	int ans(0);
	for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)if(per[i][j].sick && !per[i][j].empty)++ans;
	printf("%d\n",ans);
	return 0;
}
void func(int day, int x, int y){
	if(day == 1)return;
	if(!per[x][y].empty)per[x][y].sick = true;
	if(!per[x+1][y].empty)func(day - 1, x+1, y);
	if(!per[x-1][y].empty)func(day - 1, x-1, y);
	if(!per[x][y+1].empty)func(day - 1, x, y+1);
	if(!per[x][y-1].empty)func(day - 1, x, y-1);
}

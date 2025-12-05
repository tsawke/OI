#include <cstdio>
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
typedef unsigned long long unll;
class Index_{
	private:
		int height;
		int width;
		int Snow[110][11000];
		int ans[110][11000];
		int moveX[10] = {0,  1,-1,0,0};
		int moveY[10] = {0,  0,0,1,-1};
	protected:
	public:
		void InIt();
		void make(int, int);
		void show();
}index_;

int main(){
	index_.InIt();
	index_.show();
	return 0;
}
void Index_ ::InIt(){
	memset(this -> ans, -1, sizeof(this -> ans));
	scanf("%d%d", &this -> height, &this -> width);
	for(int i=1; i<=this -> height; ++i)
		for(int j=1; j<=this -> width; ++j)
			scanf("%d", &this -> Snow[i][j]);	
}
void Index_ ::make(int sx, int sy){
	int temp(1); int Tox, Toy;
	for(int i=1; i<=4; ++i){
		Tox = sx + this -> moveX[i];
		Toy = sy + this -> moveY[i];
		if(Tox < 1 || Tox > this -> height || Toy < 1 || Toy > this -> width || this -> Snow[Tox][Toy] >= this -> Snow[sx][sy])continue;
		if(this -> ans[Tox][Toy] == -1)this -> make(Tox, Toy);
		temp = max(temp, this -> ans[Tox][Toy] + 1);
	}this -> ans[sx][sy] = temp;
}
void Index_ ::show(){
	int maxx(1);
	for(int i=1; i<=this -> height; ++i)
		for(int j=1; j<=this -> width; ++j){
			if(this -> ans[i][j] == -1)this -> make(i, j);
			maxx = max(maxx, this -> ans[i][j]);
		}
	printf("%d\n", maxx);
}

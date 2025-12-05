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
class Index_{
	private:
		int movex[10]={0, 1,-1,0,0};
		int movey[10]={0, 0,0,1,-1};
		bool used[110][110];
		int height, width;
		bool cell[110][110]; 
	protected:
	public:
		void InIt();
		void make();
		void del(int, int);
		void show();
}index_;

int main(){
	index_.InIt();
	index_.make();
	index_.show();
	return 0;
}
void Index_ ::InIt(){
	scanf("%d%d", &this -> height, &this -> width); char ct = getchar();
	for(int i=1; i<=this -> height; ++i){
		for(int j=1; j<=this -> width; ++j){
			char c = getchar();
			switch(c){
				case '0':cell[i][j] = false; break;
				default: cell[i][j] = true;  break;
			}
		}char ct = getchar();
	}
}
void Index_ ::make(){
	for(int i=1; i<=this -> height; ++i){
		for(int j=1; j<=this -> width; ++j){
			if(cell[i][j] && !used[i][j]){
				used[i][j] = true;
				del(i, j);
			}
		}
	}
}
void Index_ ::del(int x, int y){
	for(int i=1; i<=4; i++){
		int moveToX = x + this -> movex[i];
		int moveToY = y + this -> movey[i];
		if(moveToX >= 1 && moveToX <=this -> height && moveToY >= 1 && moveToY <= this -> width && !used[moveToX][moveToY] && cell[moveToX][moveToY]){
			cell[moveToX][moveToY] = false;
			used[moveToX][moveToY] = true;
			del(moveToX, moveToY);
			used[moveToX][moveToY] = false;
		}
	}
}
void Index_ ::show(){int ans(0);
	for(int i=1; i<=this -> height; ++i)
		for(int j=1; j<=this -> width; ++j)
			if(cell[i][j])++ans;
	printf("%d\n", ans);
}

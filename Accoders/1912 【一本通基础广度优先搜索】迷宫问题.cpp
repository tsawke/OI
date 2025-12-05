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

//ERROR 

class coord{
	public:
		int x;
		int y;
};
class Index_{
	private:
		int movex[10]={1,-1,0,0};
		int movey[10]={0,0,1,-1};
		int MAP[11][11];
		int n;
		deque< coord > dq;
		coord start, end;
		int final[20][20];
	protected:
	public:
		void InIt();
		void make();
}index_;

int main(){
	index_.InIt();
	index_.make();
	return 0;
}
void Index_ ::InIt(){
	//scanf("%d", &this -> n); char ct = getchar();
	this -> n = 5;
	memset(this -> moveTimes, -1, sizeof(this -> moveTimes));
	for(int i=0; i<this -> n; i++)
		for(int j=0; j<this -> n; j++)
			scanf("%d", &this -> MAP[i][j]);
	//scanf("%d%d%d%d", &this -> start.x, &this -> start.y, &this -> end.x, &this -> end.y);
	//this -> start.x--; this -> start.y--; this -> end.x--; this -> end.y--;
	this -> start.x = 0; this -> start.y = 0; this -> end.x = 4; this -> end.y = 4;
	this -> moveTimes[this -> start.x][this -> start.y] = 0;
	this -> dq.push_back(this -> start);
}
void Index_ ::make(){
	while(!this -> dq.empty()){
		coord moveFrom = this -> dq.front();
		this -> dq.pop_front();
		for(int i=0; i<=4 - 1; ++i){
			coord moveTo;
			moveTo.x = moveFrom.x + this -> movex[i];
			moveTo.y = moveFrom.y + this -> movey[i];
			if(moveTo.x >= 0 && moveTo.x < this -> n && moveTo.y >= 0 && moveTo.y < this -> n && !this -> MAP[moveTo.x][moveTo.y]){
				this -> MAP[moveTo.x][moveTo.y] = true;
				this -> dq.push_back(moveTo);
				
			}
		}
	}
}

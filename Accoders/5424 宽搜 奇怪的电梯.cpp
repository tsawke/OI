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
		int moveTimes[210];
		int moveDistance[210];
		deque< int >dq;
		int N;
		int start, end;
	protected:
	public:
		void InIt();
		void bfs();
}index_;

int main(){
	index_.InIt();
	index_.bfs();
	return 0;
}
void Index_ ::InIt(){
	memset(this -> moveTimes, -1, sizeof(this -> moveTimes));
	scanf("%d%d%d", &this -> N, &this -> start, &this -> end);
	this -> dq.push_back(this -> start);
	this -> moveTimes[start] = 0;
	for(int i=1; i<=this -> N; i++)
		scanf("%d", this -> moveDistance + i);
}
void Index_ ::bfs(){
	while(!this -> dq.empty()){
		int moveFrom = *this -> dq.begin();
		this -> dq.pop_front();
		for(int i=-1; i<=1; i+=2){
			int moveTo = moveFrom + this -> moveDistance[moveFrom] * i;
			if(moveTo >= 0 && moveTo <= 119000 && this -> moveTimes[moveTo] == -1){
				this -> dq.push_back(moveTo);
				this -> moveTimes[moveTo] = this -> moveTimes[moveFrom] + 1;
			}
		}if(this -> moveTimes[this -> end] != -1)break;
	}printf("%d\n", this -> moveTimes[this -> end]);
}

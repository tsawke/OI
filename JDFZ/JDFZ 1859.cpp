#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <map>
#include <unistd.h>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T>
inline T read(void);
void dfs(int, const int&);
vector<int>queenPos;
bool column[30];
bool slanting[3][30];
int ans(0);
int main(){
    int n = read<int>();
    dfs(1, n);
    printf("%d\n", ans);
    pause();
    return 0;
}
/*bool check(int x, int y){
    for(int i = 1; i <= queenPos.size(); ++i)
        if(y == queenPos.at(i - 1) || abs(x - i) == abs(y - queenPos.at(i - 1)))return false;
    return true;
}*/
void dfs(int deep, const int& depth){
    if(deep > depth){
        ++ans;
        for(vector<int>::iterator itea = queenPos.begin(); itea != queenPos.end(); ++itea)printf("%d%c", *itea, itea == queenPos.end() - 1);
        return;
    }
    for(int i = 1; i <= depth; ++i){
        if(!column[i] && !slanting[1][deep + i] && !slanting[2][deep - i + depth]){
            column[i] = slanting[1][deep + i] = slanting[2][deep - i + depth] = true;
            queenPos.push_back(i);
            dfs(deep + 1, depth);
            queenPos.pop_back();
            column[i] = slanting[1][deep + i] = slanting[2][deep - i + depth] = false;
        }
    }
}
template <typename T>
inline T read(void){
	T ret(0);
	short flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10, ret += (c - '0');
		c = getchar();
    }
    ret *= flag;
	return ret;
}
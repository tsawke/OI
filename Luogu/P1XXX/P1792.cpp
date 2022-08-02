//C++11 - Template
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
#include <queue>
#include <stack>
#include <functional>
#include <unistd.h>

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);

int N, M;
int beauty[210000];
int _left[210000], _right[210000];
bool used[210000];
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>beauties;
int main(){
	N = read(), M = read();
    if(M * 2 > N){printf("Error!\n"); return 0;}
    for(int i = 2; i <= N; ++i)_left[i] = i - 1;
    for(int i = 1; i <= N - 1; ++i)_right[i] = i + 1;
    _left[1] = N, _right[N] = 1;
    for(int i = 1; i <= N; ++i)beauty[i] = read(), beauties.push(make_pair(beauty[i], i));
    int ans(0);
    int cnt(0);
    while(cnt < M){
        int num, value;
        tie(value, num) = beauties.top();
        beauties.pop();
        if(used[num])continue;
        beauties.push(make_pair(beauty[_left[num]] + beauty[_right[num]] - beauty[num], num));
        beauty[num] = beauty[_left[num]] + beauty[_right[num]] - beauty[num];
        used[_left[num]] = used[_right[num]] = true;
        _left[num] = _left[_left[num]],
        _right[num] = _right[_right[num]];
        _right[_left[num]] = num;
        _left[_right[num]] = num;
        ans += value;
        ++cnt;
        // printf("Ans += Value(%d) = %d\n", value, ans);
    }
    printf("%d\n", ans);

    return 0;
}

template <typename T = int>
inline T read(void)
{
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
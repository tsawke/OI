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
template <typename T>
inline T read(void);
int N, M, tree[510000];
int lowbit(int x){return x & (-x);};
void add(int x, int k){
    int pos(x);
    while(pos <= N){
        tree[pos] += k;
        pos += lowbit(pos);
    }
    return;
}
int query(int lR, int rR){
    int rans(0), lans(0);
    int pos(rR);
    while(pos){
        rans += tree[pos];
        pos -= lowbit(pos);
    }
    pos = lR - 1;
    while(pos){
        lans += tree[pos];
        pos -= lowbit(pos);
    }
    return rans - lans;
}
int main(){
	N = read<int>(), M = read<int>();
    for(int i = 1; i <= N; ++i){
        // add(i, read());
        add(i, 0);
    }
    for(int i = 1; i <= M; ++i){
        char mode = getchar();
        // scanf("%d", &mode);
        switch(mode){
            case 'B':{
                int x = read<int>(), k = read<int>();
                add(x, k);
                break;
            }
            case 'C':{
                int x = read<int>(), k = read<int>();
                add(x, -k);
                break;
            }
            case 'A':{
                int rR = read<int>();
                printf("%d\n", query(1, rR));
            }
        }
    }

    return 0;
}

template <typename T>
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
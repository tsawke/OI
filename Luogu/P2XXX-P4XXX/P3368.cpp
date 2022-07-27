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
int query(int R){
    // int rans(0), lans(0);
    // int pos(rR);
    // while(pos){
    //     rans += tree[pos];
    //     pos -= lowbit(pos);
    // }
    // pos = lR - 1;
    // while(pos){
    //     lans += tree[pos];
    //     pos -= lowbit(pos);
    // }
    // return rans - lans;
    int ans(0);
    int pos(R);
    while(pos){
        ans += tree[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int main(){
	N = read(), M = read();
    int currentV(0), lastV(0);
    for(int i = 1; i <= N; ++i){
        currentV = read();
        add(i, currentV - lastV);
        lastV = currentV;
    }
    for(int i = 1; i <= M; ++i){
        int mode = read();
        switch(mode){
            case 1:{
                int x = read(), y = read(), k = read();
                add(x, k);
                add(y + 1, -k);
                break;
            }
            case 2:{
                int x = read();
                printf("%d\n", query(x));
                break;
            }
        }
    }

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
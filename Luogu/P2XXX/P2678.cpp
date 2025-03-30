#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long unll;

template < typename T = int >
inline T read(void);

int L, N, M;
int dis[51000];

int main(){
    L = read(), N = read(), M = read();
    for(int i = 1; i <= N; ++i)dis[i] = read();
    dis[N + 1] = L;

    auto check = [](int mnDis) -> bool{
        int cnt(0), lst(0);
        for(int i = 1; i <= N + 1; ++i)
            if(dis[i] - dis[lst] < mnDis)++cnt;
            else lst = i;
        return cnt <= M;
    };

    int l = 1, r = L, ans(1);
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid))l = mid + 1, ans = mid;
        else r = mid - 1;
    }printf("%d\n", ans);

    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c))c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }ret *= flag;
    return ret;
}
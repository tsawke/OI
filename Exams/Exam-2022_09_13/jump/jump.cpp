#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

// #define int ll

template<typename T = int>
inline T read(void);

int N;
int len[310], pri[310];
ll ans(LLONG_MAX);
void bfs(){
    queue < pair < int, int > >q;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        int cur, cpri;
        tie(cur, cpri) = q.front();
        q.pop();
        if(cur == 1){
            ans = min(ans, (ll)cpri);
        }
        for(int i = 1; i <= N; ++i){
            q.push(make_pair(cur + len[i], cpri + pri[i]));
            q.push(make_pair(cur - len[i], cpri + pri[i]));
        }
        if((double)clock() / CLOCKS_PER_SEC > 1.8){
            if(ans == LLONG_MAX)printf("-1\n");
            else printf("%lld\n", ans);
            exit(0);
        }
    }
}
int main(){
    // freopen("jump.in", "r", stdin);
    // freopen("jump.out", "w", stdout);
    printf("%d\n", sizeof(make_pair(1, 1)));
    N = read();
    for(int i = 1; i <= N; ++i)len[i] = read();
    for(int i = 1; i <= N; ++i)pri[i] = read();
    // int dep(0);
    bfs();
    // printf("%lld\n", ans);
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
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
    }
    ret *= flag;
    return ret;
}
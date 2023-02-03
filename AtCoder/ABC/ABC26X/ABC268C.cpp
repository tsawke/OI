#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define pre(i) (i ? i - 1 : N - 1)
#define nxt(i) (i == N - 1 ? 0 : i + 1)

template < typename T = int >
inline T read(void);

int N;
int cnt_dis[210000];
int ans(0);

int main(){
    N = read();
    for(int i = 0; i <= N - 1; ++i)cnt_dis[(i - read() + N) % N]++;
    for(int i = 0; i <= N - 1; ++i)ans = max(ans, cnt_dis[i] + cnt_dis[pre(i)] + cnt_dis[nxt(i)]);
    printf("%d\n", ans);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
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
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

template < typename T = int >
inline T read(void);

int N, M;
ll A[2100];
ll dp[2100][2100];
ll sum_mx[2100][2100];

int main(){
    memset(sum_mx, 0xc0, sizeof sum_mx);
    N = read(), M = read();
    for(int i = 0; i <= N; ++i)sum_mx[0][i] = 0;
    for(int i = 1; i <= N; ++i)A[i] = read();
    for(int i = 1; i <= M; ++i)
        for(int j = 1; j <= N; ++j)
            dp[i][j] = sum_mx[i - 1][j - 1] + A[j] * i,
            sum_mx[i][j] = max(sum_mx[i][j - 1], dp[i][j]);
    printf("%lld\n", sum_mx[M][N]);
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
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define INF (0x3f3f3f3f)

template < typename T = int >
inline T read(void);

int N;

namespace Sub_1_2{
    ll A[5100];
    ll dp[5100][5100];
    void Make(void){
        memset(dp, 0xc0, sizeof dp);
        for(int i = 1; i <= N; ++i)A[i] = read();
        A[0] = -INF;
        dp[1][0] = A[1], dp[1][1] = -1;
        for(int i = 2; i <= N; ++i){
            for(int j = 0; j <= i - 1; ++j)
                if(A[i] >= A[i - 1 - j])
                    dp[i][0] = max(dp[i][0], dp[i - 1][j] + A[i]);
            for(int j = 1; j <= i; ++j)
                dp[i][j] = dp[i - 1][j - 1] + (((j - 1) * j) >> 1) - ((j * (j + 1)) >> 1);
        }
        ll ans(-INF);
        for(int j = 0; j <= N; ++j)ans = max(ans, dp[N][j]);
        printf("%lld\n", ans);
    }
}
namespace Sub_3_4{
    ll A[1100000];
    void Make(void){
        for(int i = 1; i <= N; ++i)A[i] = read();

    }
}
int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    N = read();
    if(N <= 10000)Sub_1_2::Make();
    else exit(1);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

/*
7
1 3 2 7 3 2 4

7
-3 -4 -2 -2 -6 -8 -1
*/

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
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

#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

int N, K, C;
ll dp[1100000][2];
ll sum[1100000][2];

int main(){
    N = read(), K = read(), C = read();
    dp[1][0] = sum[1][0] = C;
    for(int i = 2; i <= N; ++i){
        dp[i][0] = (C + (C - 1) * (i - K + 1 >= 0 ? sum[i - K + 1][0] : 0) % MOD + (i - K + 1 >= 0 ? sum[i - K + 1][1] : 0)) % MOD;
        dp[i][1] = ((C - 1) * ((sum[i - 1][0] - (i - K + 1 >= 0 ? sum[i - K + 1][0] : 0) + MOD) % MOD) % MOD + ((sum[i - 1][1] - (i - K + 1 >= 0 ? sum[i - K + 1][1] : 0) + MOD) % MOD)) % MOD;
        sum[i][0] = (sum[i - 1][0] + dp[i][0]) % MOD, sum[i][1] = (sum[i - 1][1] + dp[i][1]) % MOD;
        // printf("i = %d, dp[0] = %lld, dp[1] = %lld\n", i, dp[i][0], dp[i][1]);
    }printf("%lld\n", (dp[N][0] + dp[N][1]) % MOD);
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
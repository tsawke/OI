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



template < typename T = int >
inline T read(void);

int N, M;
int A[3100];
int dp[3100][3100];
int mn[3100];

int main(){
    memset(dp, 0x3f, sizeof dp);
    memset(mn, 0x3f, sizeof mn);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    dp[0][0] = 0, mn[0] = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j <= M; ++j){
            if(j - A[i] >= 0)dp[i][j] = dp[i - 1][j - A[i]];
            dp[i][j] = min(dp[i][j], mn[j] + 1);
            mn[j] = min(mn[j], dp[i][j]);
        }
    }
    for(int j = 1; j <= M; ++j)printf("%d\n", dp[N][j] < 0x3f3f3f3f ? dp[N][j] : -1);
    // for(int i = 1; i <= N; ++i)
    //     for(int j = 1; j <= M; ++j)
    //         printf("%d%c", dp[i][j], j == M ? '\n' : ' ');
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
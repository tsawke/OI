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

#define INFLD (ld)(1e12)

template < typename T = int >
inline T read(void);

int N, M;
pair < ll, ll > town[15], sup[8];
ld dp[4500][40][18];
ld ans(INFLD);

ld CalDis(pair < ll, ll > A, pair < ll, ll > B){
    return sqrt((ld)((A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second)));
}

int main(){
    for(int i = 0; i <= 4400; ++i)for(int j = 0; j <= 38; ++j)for(int k = 0; k <= 17; ++k)dp[i][j][k] = INFLD;
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)town[i].first = read(), town[i].second = read();
    for(int i = 1; i <= M; ++i)sup[i].first = read(), sup[i].second = read();
    dp[0][0][0] = 0;
    int SmxN = (1 << N) - 1, SmxM = (1 << M) - 1;
    for(int i = 0; i <= SmxN; ++i)
        for(int j = 0; j <= SmxM; ++j){
            ll rate = 1 << __builtin_popcount(j);
            for(int k = 1; k <= N; ++k)
                if(!(i & (1 << (k - 1)))){
                    for(int pos = 0; pos <= N; ++pos)
                        if(dp[i][j][pos] < INFLD)
                            dp[i | (1 << (k - 1))][j][k] = min(dp[i | (1 << (k - 1))][j][k], dp[i][j][pos] + CalDis(town[pos], town[k]) / (ld)rate);
                    for(int pos = N + 1; pos <= N + M; ++pos)
                        if(dp[i][j][pos] < INFLD)
                            dp[i | (1 << (k - 1))][j][k] = min(dp[i | (1 << (k - 1))][j][k], dp[i][j][pos] + CalDis(sup[pos - N], town[k]) / (ld)rate);
                }
            for(int k = 1; k <= M; ++k)
                if(!(j & (1 << (k - 1)))){
                    for(int pos = 0; pos <= N; ++pos)
                        if(dp[i][j][pos] < INFLD)
                            dp[i][j | (1 << (k - 1))][N + k] = min(dp[i][j | (1 << (k - 1))][N + k], dp[i][j][pos] + CalDis(town[pos], sup[k]) / (ld)rate);
                    for(int pos = N + 1; pos <= N + M; ++pos)
                        if(dp[i][j][pos] < INFLD)
                            dp[i][j | (1 << (k - 1))][N + k] = min(dp[i][j | (1 << (k - 1))][N + k], dp[i][j][pos] + CalDis(sup[pos - N], sup[k]) / (ld)rate);
                }
        }
    for(int j = 0; j <= SmxM; ++j){
        ll rate = 1 << __builtin_popcount(j);
        for(int k = 1; k <= N + M; ++k)
            if(dp[SmxN][j][k] < INFLD)
                ans = min(ans, dp[SmxN][j][k] + CalDis(k <= N ? town[k] : sup[k - N], town[0]) / (ld)rate);
    }printf("%.8Lf\n", ans);
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
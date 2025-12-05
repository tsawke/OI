#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (int)(19940417)
#define LEN(a, b) (((ll)cor[b].first - cor[a].first - cor[b].second - cor[a].second));

template< typename T = int >
inline T read(void);

int N, K;
set < pair < int, int > > data;
pair < int, int > cor[1100000];
ll dp[1100000][2]; //0-up 1-down
ll mx(-1);

int qpow(int a, int b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
int main(){
    N = read(), K = read();
    // data.insert({0, 0}), data.insert({N, 0});
    // for(int i = 1; i <= k; ++i){int x = read(), y = read(); data.insert({x, y});}
    for(int i = 1; i <= K; ++i)cor[i].first = read(), cor[i].second = read();
    cor[++K] = {0, 0}; cor[++K] = {N, 0};
    // for(auto v : data)cor[++K] = v;
    sort(cor + 1, cor + K + 1);
    // K = distance(cor, unique(cor + 1, cor + K + 1)) - 1;
    K = distance(cor + 1, unique(cor + 1, cor + K + 1));
    // K = unique(cor + 1, cor + K + 1) - cor - 1;
    dp[1][1] = 1;
    for(int i = 1; i < K; ++i){
        int len = LEN(i, i + 1);
        if(cor[i + 1].first - cor[i].first == cor[i + 1].second - cor[i].second){
            dp[i + 1][0] = (dp[i + 1][0] + dp[i][0]) % MOD;
            if(cor[i].second == 0)dp[i + 1][0] = (dp[i + 1][0] + dp[i][1]) % MOD;
        }else if(cor[i + 1].first - cor[i].first == cor[i].second - cor[i + 1].second){
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][0] + dp[i][1]) % MOD;
        }else if(len < 0){
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % MOD;
            if(cor[i].second == 0)dp[i + 1][1] = (dp[i + 1][1] + dp[i][1]) % MOD;
        }else if(len == 0){
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % MOD;
            // if(cor[i].second == 0)dp[i + 1][1] = (dp[i + 1][1] + dp[i][1]) % MOD;
            dp[i + 1][0] = (dp[i + 1][0] + dp[i][0] + dp[i][1]) % MOD;
        }else{
            if(cor[i + 1].second > 0){
                dp[i + 1][0] = (dp[i + 1][0] + dp[i][0] * qpow(2, (int)(len >> 1) - 1 + 1) % MOD) % MOD;
                dp[i + 1][0] = (dp[i + 1][0] + dp[i][1] * qpow(2, (int)(len >> 1) - 1) % MOD) % MOD;
            }
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][0] * qpow(2, (int)(len >> 1) - 1 + 1) % MOD) % MOD;
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][1] * qpow(2, (int)(len >> 1) - 1) % MOD) % MOD;
        }
        if(dp[i + 1][1] > 0)mx = max(mx, ((ll)cor[i + 1].first - cor[i].first + cor[i].second + cor[i + 1].second) >> 1);
    }
    printf("%lld %lld\n", dp[K][1], mx);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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
    }
    ret *= flag;
    return ret;
}
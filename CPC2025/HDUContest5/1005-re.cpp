#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

struct TupleHash {
    size_t operator()(const tuple<int,int,int,int>& t) const noexcept {
        auto [a,b,c,d] = t;
        auto splitmix64 = [](uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        };
        uint64_t h1 = splitmix64((uint64_t)a + 0x9e3779b97f4a7c15);
        uint64_t h2 = splitmix64((uint64_t)b + 0x9e3779b97f4a7c15);
        uint64_t h3 = splitmix64((uint64_t)c + 0x9e3779b97f4a7c15);
        uint64_t h4 = splitmix64((uint64_t)d + 0x9e3779b97f4a7c15);
        return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (h4 << 3);
    }
};

unordered_map < tuple < int, int, int, int >, ll, TupleHash > dp[2];

int A, B, C, D;
int K[5];
ll val[5][1100];
ll sum[5][1100];

int main(){
    int T = read();
    while(T--){
        A = read(), B = read(), C = read(), D = read();
        dp[0].clear(), dp[1].clear();
        dp[0][{0, 0, 0, 0}] = 0;
        for(int i = 1; i <= 4; ++i){
            K[i] = read();
            for(int j = 1; j <= K[i]; ++j)val[i][j] = read();
        }
        for(int i = 1; i <= 4; ++i)sort(val[i] + 1, val[i] + K[i] + 1, greater < ll >());
        for(int i = 1; i <= 4; ++i){
            sum[i][0] = 0;
            for(int j = 1; j <= K[i]; ++j)
                sum[i][j] = sum[i][j - 1] + val[i][j];
        }
        for(int i = 1; i <= A + B + C + D; ++i){
            int cur = (i & 1) ^ 1;
            int nxt = (i & 1);
            dp[nxt].clear();
            bool is1x1 = (1 <= i && i <= A);
            bool is1x2 = (A + 1 <= i && i <= A + B);
            bool is1x3 = (A + B + 1 <= i && i <= A + B + C);
            bool is2x2 = (A + B + C + 1 <= i && i <= A + B + C + D);
            for (auto& p : dp[cur]) {
                auto state = p.first;
                ll v = p.second;
                auto [u1, u2, u3, u4] = state;
                dp[nxt][{u1, u2, u3, u4}] = max(dp[nxt][{u1, u2, u3, u4}], v);
                if(is1x1){
                    if(u1 + 1 <= K[1]) dp[nxt][{u1 + 1, u2, u3, u4}] = max(dp[nxt][{u1 + 1, u2, u3, u4}], v + (sum[1][u1 + 1] - sum[1][u1]));
                } else if(is1x2){
                    if(u2 + 1 <= K[2]) dp[nxt][{u1, u2 + 1, u3, u4}] = max(dp[nxt][{u1, u2 + 1, u3, u4}], v + (sum[2][u2 + 1] - sum[2][u2]));
                    if(u1 + 1 <= K[1]) dp[nxt][{u1 + 1, u2, u3, u4}] = max(dp[nxt][{u1 + 1, u2, u3, u4}], v + (sum[1][u1 + 1] - sum[1][u1]));
                    if(u1 + 2 <= K[1]) dp[nxt][{u1 + 2, u2, u3, u4}] = max(dp[nxt][{u1 + 2, u2, u3, u4}], v + (sum[1][u1 + 2] - sum[1][u1]));
                } else if(is1x3){
                    if(u3 + 1 <= K[3]) dp[nxt][{u1, u2, u3 + 1, u4}] = max(dp[nxt][{u1, u2, u3 + 1, u4}], v + (sum[3][u3 + 1] - sum[3][u3]));
                    if(u2 + 1 <= K[2]) dp[nxt][{u1, u2 + 1, u3, u4}] = max(dp[nxt][{u1, u2 + 1, u3, u4}], v + (sum[2][u2 + 1] - sum[2][u2]));
                    if(u1 + 1 <= K[1]) dp[nxt][{u1 + 1, u2, u3, u4}] = max(dp[nxt][{u1 + 1, u2, u3, u4}], v + (sum[1][u1 + 1] - sum[1][u1]));
                    if(u1 + 2 <= K[1]) dp[nxt][{u1 + 2, u2, u3, u4}] = max(dp[nxt][{u1 + 2, u2, u3, u4}], v + (sum[1][u1 + 2] - sum[1][u1]));
                    if(u1 + 3 <= K[1]) dp[nxt][{u1 + 3, u2, u3, u4}] = max(dp[nxt][{u1 + 3, u2, u3, u4}], v + (sum[1][u1 + 3] - sum[1][u1]));
                    if(u2 + 1 <= K[2] && u1 + 1 <= K[1]) dp[nxt][{u1 + 1, u2 + 1, u3, u4}] = max(dp[nxt][{u1 + 1, u2 + 1, u3, u4}], v + (sum[2][u2 + 1] - sum[2][u2]) + (sum[1][u1 + 1] - sum[1][u1]));
                } else if(is2x2){
                    if(u4 + 1 <= K[4]) dp[nxt][{u1, u2, u3, u4 + 1}] = max(dp[nxt][{u1, u2, u3, u4 + 1}], v + (sum[4][u4 + 1] - sum[4][u4]));
                    if(u2 + 1 <= K[2]) dp[nxt][{u1, u2 + 1, u3, u4}] = max(dp[nxt][{u1, u2 + 1, u3, u4}], v + (sum[2][u2 + 1] - sum[2][u2]));
                    if(u2 + 2 <= K[2]) dp[nxt][{u1, u2 + 2, u3, u4}] = max(dp[nxt][{u1, u2 + 2, u3, u4}], v + (sum[2][u2 + 2] - sum[2][u2]));
                    if(u2 + 1 <= K[2] && u1 + 1 <= K[1]) dp[nxt][{u1 + 1, u2 + 1, u3, u4}] = max(dp[nxt][{u1 + 1, u2 + 1, u3, u4}], v + (sum[2][u2 + 1] - sum[2][u2]) + (sum[1][u1 + 1] - sum[1][u1]));
                    if(u2 + 1 <= K[2] && u1 + 2 <= K[1]) dp[nxt][{u1 + 2, u2 + 1, u3, u4}] = max(dp[nxt][{u1 + 2, u2 + 1, u3, u4}], v + (sum[2][u2 + 1] - sum[2][u2]) + (sum[1][u1 + 2] - sum[1][u1]));
                    if(u1 + 1 <= K[1]) dp[nxt][{u1 + 1, u2, u3, u4}] = max(dp[nxt][{u1 + 1, u2, u3, u4}], v + (sum[1][u1 + 1] - sum[1][u1]));
                    if(u1 + 2 <= K[1]) dp[nxt][{u1 + 2, u2, u3, u4}] = max(dp[nxt][{u1 + 2, u2, u3, u4}], v + (sum[1][u1 + 2] - sum[1][u1]));
                    if(u1 + 3 <= K[1]) dp[nxt][{u1 + 3, u2, u3, u4}] = max(dp[nxt][{u1 + 3, u2, u3, u4}], v + (sum[1][u1 + 3] - sum[1][u1]));
                    if(u1 + 4 <= K[1]) dp[nxt][{u1 + 4, u2, u3, u4}] = max(dp[nxt][{u1 + 4, u2, u3, u4}], v + (sum[1][u1 + 4] - sum[1][u1]));
                }
            }
        }
        int lst = ((A + B + C + D ) & 1);
        ll ans = 0;
        for(auto& p : dp[lst])ans = max(ans, p.second);
        printf("%lld\n", ans);
    }

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
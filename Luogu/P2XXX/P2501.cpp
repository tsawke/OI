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

template< typename T = int >
inline T read(void);

int N;
int dif[36000];
int lis[36000];
ll pre[36000], suf[36000];
ll dp[36000];
vector < int > buc[36000];
vector < int > LIS;

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)dif[i] = read() - i;
    dif[++N] = INT_MAX; dif[0] = -INT_MAX;
    for(int i = 1; i <= N; ++i){
        if(LIS.empty() || LIS.back() <= dif[i])LIS.emplace_back(dif[i]), lis[i] = LIS.size();
        else{
            auto it = upper_bound(LIS.begin(), LIS.end(), dif[i]);
            lis[i] = distance(LIS.begin(), it + 1);
            *it = dif[i];
        }
        buc[lis[i]].emplace_back(i);
        // mx = max(mx, lis[i]);
    }buc[0].emplace_back(0);
    // printf("LIS:  ");
    // for(int i = 1; i <= N; ++i)printf("%d ", lis[i]);
    // printf("\n");
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int tl = 1; tl <= N; ++tl){
        for(auto pr : buc[lis[tl] - 1]){
            // printf("pr = %d, tl = %d, dif[pr] = %d, dif[tl] = %d\n", pr, tl, dif[pr], dif[tl]);
            if(pr >= tl || dif[pr] > dif[tl])continue;
            int l = pr + 1, r = tl - 1;
            // if(l > r)continue;
            pre[pr] = suf[tl] = 0;
            for(int i = l; i <= r; ++i)pre[i] = pre[i - 1] + abs(dif[i] - dif[pr]);
            for(int i = r; i >= l; --i)suf[i] = suf[i + 1] + abs(dif[i] - dif[tl]);
            // for(int i = l; i <= r; ++i)printf("tail = %d, pre%d = %lld, suf%d = %lld\n", tl, i, pre[i], i, suf[i]);
            for(int sp = l - 1; sp + 1 <= r + 1; ++sp){
                dp[tl] = min(dp[tl], dp[pr] + pre[sp] + suf[sp + 1]);
            }
        }
    }
    // printf("DP: "); for(int i = 1; i <= N; ++i)printf("%lld%c", dp[i], i == N ? '\n' : ' ');
    printf("%d\n%lld\n", N - lis[N], dp[N]);



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
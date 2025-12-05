#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define int ll

template<typename T = int>
inline T read(void);

#define MAXARR 11000000
#define MAXR 10100000

bool vis[MAXARR];
int mu[MAXARR];
int val[MAXARR];
int sum[MAXARR];
vector < int > prime;

void Sieve(void){
    mu[1] = 1;
    for(int i = 2; i <= MAXR; ++i){
        if(!vis[i])prime.emplace_back(i), mu[i] = -1;
        for(auto p : prime){
            if(i * p > MAXR)break;
            vis[i * p] = true;
            if(i % p == 0)mu[i * p] = 0;
            else mu[i * p] = -mu[i];
            if(i % p == 0)break;
        }
    }
    for(auto i : prime){
        for(int j = 1; i * j <= MAXR; ++j){
            val[i * j] += mu[j];
        }
    }
    for(int i = 1; i <= MAXR; ++i)sum[i] = sum[i - 1] + val[i];
}

signed main(){
    Sieve();
    int T = read();
    ll ans(0);
    while(T--){
        ans = 0;
        int N = read(), M = read();
        int rng = min(N, M);
        for(int l = 1; l <= rng;){
            // int r = (rng / (rng / l));
            int r = min(N / (N / l), M / (M / l));
            ans += (N / l) * (M / l) * (sum[r] - sum[l - 1]);
            l = r + 1;
        }
        printf("%lld\n", ans);
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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
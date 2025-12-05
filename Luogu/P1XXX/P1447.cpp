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

int N, M;
// int mu[110000];
int phi[110000];
bool vis[110000];
vector < int > prime;
ll sum[110000];

void Sieve(void){
    // mu[1] = 1;
    // for(int i = 2; i <= 101000; ++i){
    //     if(!vis[i])prime.emplace_back(i), mu[i] = -1;
    //     for(auto p : prime){
    //         if(p * i > 101000)break;
    //         vis[p * i] = true;
    //         if(i % p == 0)mu[i * p] = 0;
    //         else mu[i * p] = -mu[i];
    //     }
    // }
    // int mn = min(N, M);
    // for(auto p : prime){
    //     for(int i = 1; i * p <= 101000; ++i){
    //         f[i * p] += mu[]
    //     }
    // }
    phi[1] = 1;
    for(int i = 2; i <= 101000; ++i){
        if(!vis[i])prime.emplace_back(i), phi[i] = i - 1;
        for(auto p : prime){
            if(p * i > 101000)break;
            vis[i * p] = true;
            if(i % p == 0)phi[i * p] = phi[i] * p;
            else phi[i * p] = phi[i] * (p - 1);
            if(i % p == 0)break;
        }
    }
    for(int i = 1; i <= 101000; ++i)sum[i] = sum[i - 1] + phi[i];
}

signed main(){
    Sieve();
    N = read(), M = read();
    ll ans(0);
    int X(min(N, M));
    for(int l = 1; l <= X;){
        int r = min(N / (N / l), M / (M / l));
        ans += (sum[r] - sum[l - 1]) * (N / l) * (M / l);
        l = r + 1;
    }
    printf("%lld\n", 2 * ans - N * M);

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
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

// #define int ll

template<typename T = int>
inline T read(void);

int mu[51000];
int sum[51000];
bool vis[51000];
vector < int > prime;

void Sieve(void){
    mu[1] = 1;
    for(int i = 2; i <= 50100; ++i){
        if(!vis[i])prime.emplace_back(i), mu[i] = -1;
        for(auto p : prime){
            if(i * p > 50100)break;
            vis[i * p] = true;
            if(i % p == 0)mu[i * p] = 0;
            else mu[i * p] = -mu[i];
            if(i % p == 0)break;
        }
    }
    for(int i = 1; i <= 50100; ++i)sum[i] = sum[i - 1] + mu[i];
}

int cal(int a, int b, int k){
    int ans(0);
    int rng = min(a, b);
    for(int l = 1; l <= rng;){
        // int r = rng / (rng / l);
        int r = min(a / (a / l), b / (b / l));
        ans += (a / (k * l)) * (b / (k * l)) * (sum[r] - sum[l - 1]);
        l = r + 1;
    }
    return ans;
}

signed main(){
    Sieve();
    int T = read();
    while(T--){
        // ll ans(0);
        int a = read(), b = read(), c = read(), d = read(), k = read();
        printf("%d\n", cal(b, d, k) - cal(b, c - 1, k) - cal(a - 1, d, k) + cal(a - 1, c - 1, k));
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
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

#define MOD 998244353

template<typename T = int>
inline T read(void);

int N, L;
int str[20];
int readStr(void){
    int ret(0);
    char c = getchar();
    while(!islower(c))c = getchar();
    vector < int > val;
    while(islower(c)){
        ret |= 1 << (c - 'a');
        c = getchar();
    }return ret;
}
ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

int main(){
    N = read(), L = read();
    ll ans(0);
    for(int i = 1; i <= N; ++i)str[i] = readStr();
    // for(int i = 1; i <= N; ++i)
    //     cout << bitset < 32 > (str[i]) << endl;
    int Smx = (1 << N) - 1;
    // cout << "Smx" << bitset < 32 > (Smx) << endl;
    for(int S = Smx; S; S = (S - 1) & Smx){
        // cout << "S:" << bitset < 32 > (S) << endl;
        int cnt = __builtin_popcount(S);
        int tot((1 << 26) - 1);
        // cout << "tot_pre:" << bitset < 32 > (S) << endl;
        for(int i = 0; i <= N - 1; ++i)
            if((1 << i) & S)tot &= str[i + 1];
        // cout << "tot:" << bitset < 32 > (tot) << endl;
        ans = (ans + qpow(__builtin_popcount(tot), L) * ((cnt & 1) ? 1 : -1) + MOD) % MOD;
    }
    printf("%lld\n", ans);
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
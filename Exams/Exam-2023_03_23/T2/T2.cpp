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

ll N, X, Y, Z;
namespace Sub1{
    ll ans(0);
    ll pow3[30];
    ll powY[210], powZ[210];
    int s[11000000];
    void Make(void){
        pow3[0] = 1;
        for(int i = 1; i <= 25; ++i)pow3[i] = pow3[i - 1] * 3;
        auto dfs_3 = [](auto&& self, ll cur = 0, int dep = 0, int sum = 0){
            if(cur > N)return;
            s[cur] = sum;
            if(pow3[dep] > N)return;
            for(int i = 0; i <= 2; ++i)
                self(self, cur + pow3[dep] * i, dep + 1, sum + i);
        }; dfs_3(dfs_3);
        powY[0] = powZ[0] = 1;
        for(int i = 1; i <= 205; ++i)powY[i] = powY[i - 1] * Y % MOD, powZ[i] = powZ[i - 1] * Z % MOD;
        for(ll i = 1, base(X); i <= N; ++i, (base *= X) %= MOD)
            (ans += base * powY[__builtin_popcount(i)] % MOD * powZ[s[i]] % MOD) %= MOD;
        printf("%lld\n", ans);
    }
}
namespace Sub2{

}


int main(){
    freopen("T2.in", "r", stdin);
    freopen("T2.out", "w", stdout);
    N = read < ll >(), X = read(), Y = read(), Z = read();
    // if(N <= (ll)(1e7))
    Sub1::Make();
    // else while(true);
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
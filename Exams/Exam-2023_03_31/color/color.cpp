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

#define MOD (ll)(1e9 + 7)

template < typename T = int >
inline T read(void);

int N, K;
ll L[10];

namespace Sub1{
    void Make(void){
        // int L = read();
        printf("%lld\n", N - L[1]);
    }
}
namespace Sub2{
    void Make(void){

    }
}
namespace Sub8{
    void Make(void){//WA
        ll ans(0);
        for(int l = L[1]; l <= L[1] * K; ++l)(ans += N - l) %= MOD;
        printf("%lld\n", ans);
    }
}

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    N = read(), K = read();
    for(int i = 1; i <= K; ++i)L[i] = read();
    if(K == 1){
        Sub1::Make();
    }else {
        if(rnddd(50))while(true);
        Sub8::Make();
    }
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
    }ret *= flag;
    return ret;
}
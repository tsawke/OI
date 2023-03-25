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

template < typename T = int >
inline T read(void);

int fact[50];
int A, B, C, N;

int main(){
    auto qpow = [](ll a, ll b)->ll{
        ll ret(1), mul(a);
        while(b){
            if(b & 1)ret = ret * mul;
            b >>= 1;
            mul = mul * mul;
        }return ret;
    };
    auto Phi = [](ll val){
        ll ret(val);
        for(ll i = 2; i * i <= val; ++i){
            if(val % i == 0){
                (ret /= i) *= i - 1;
                while(val % i == 0)val /= i;
            }
        }if(val != 1)(ret /= val) *= val - 1;
        return ret;
    };
    auto Resolve = [](ll val, int d)->void{
        for(ll i = 2; i * i <= val; ++i)
            while(val % i == 0)fact[i] += d, val /= i;
        if(val != 1)fact[val] += d;
    };
    auto MakeRotate = [Resolve, qpow](ll base)->ll{
        ll ret(1);
        if(A < 0 || B < 0 || C < 0 || A % (N / base) || B % (N / base) || C % (N / base))return 0;
        memset(fact, 0, sizeof fact);
        int a = A / (N / base), b = B / (N / base), c = C / (N / base);
        for(ll i = 2; i <= base; ++i)Resolve(i, 1);
        for(ll i = 2; i <= a; ++i)Resolve(i, -1);
        for(ll i = 2; i <= b; ++i)Resolve(i, -1);
        for(ll i = 2; i <= c; ++i)Resolve(i, -1);
        for(int i = 2; i <= 40; ++i)ret *= qpow(i, fact[i]);
        return ret;
    };
    auto MakeFlip = [Resolve, qpow](ll base, int A, int B, int C)->ll{
        ll ret(1);
        if(A < 0 || B < 0 || C < 0 || A & 1 || B & 1 || C & 1)return 0;
        memset(fact, 0, sizeof fact);
        int a = A >> 1, b = B >> 1, c = C >> 1;
        for(ll i = 2; i <= base; ++i)Resolve(i, 1);
        for(ll i = 2; i <= a; ++i)Resolve(i, -1);
        for(ll i = 2; i <= b; ++i)Resolve(i, -1);
        for(ll i = 2; i <= c; ++i)Resolve(i, -1);
        for(int i = 2; i <= 40; ++i)ret *= qpow(i, fact[i]);
        return ret;
    };
    int T = read();
    while(T--){
        ll ans(0);
        A = read(), B = read(), C = read(); N = A + B + C;
        for(ll i = 1; i * i <= N; ++i)
            if(N % i == 0){
                ans += MakeRotate(i) * Phi(N / i);
                if(i * i != N)ans += MakeRotate(N / i) * Phi(i);
            }
        if(N & 1){
            ans += N * MakeFlip(N >> 1, A - 1, B, C);
            ans += N * MakeFlip(N >> 1, A, B - 1, C);
            ans += N * MakeFlip(N >> 1, A, B, C - 1);
        }else{
            ans += (N >> 1) * MakeFlip(N >> 1, A, B, C);
            ans += (N >> 1) * MakeFlip((N >> 1) - 1, A - 2, B, C);
            ans += (N >> 1) * MakeFlip((N >> 1) - 1, A, B - 2, C);
            ans += (N >> 1) * MakeFlip((N >> 1) - 1, A, B, C - 2);
            ans += N * MakeFlip((N >> 1) - 1, A - 1, B - 1, C);
            ans += N * MakeFlip((N >> 1) - 1, A - 1, B, C - 1);
            ans += N * MakeFlip((N >> 1) - 1, A, B - 1, C - 1);
        }printf("%lld\n", ans / (N << 1));
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
    }
    ret *= flag;
    return ret;
}
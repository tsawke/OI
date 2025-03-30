#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define EPS (1e-6)

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

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul;
        b >>= 1;
        mul = mul * mul;
    }return ret;
}

__int128_t qpow128(__int128_t a, ll b){
    __int128_t ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul;
        b >>= 1;
        mul = mul * mul;
    }return ret;
}

unordered_map < ll, int > ans; 

namespace MillerRabin{
    int radix[10] = {0, 2, 3, 5, 7, 11, 13, 19, 17};
    ll qpow(ll a, ll b, ll MOD){
        ll ret(1), mul(a);
        while(b){
            if(b & 1)ret = (__int128_t)ret * mul % MOD;
            b >>= 1;
            mul = (__int128_t)mul * mul % MOD;
        }return ret;
    }
    bool Check(ll N){
        if(N <= 2 || !(N & 1))return N == 2;
        ll base(N - 1); int cpow(0);
        while(base % 2 == 0)base >>= 1, ++cpow;
        for(int t = 1; t <= 8; ++t){
            if(radix[t] % N == 0)continue;
            ll cur = qpow(radix[t] % N, base, N);
            if(cur == 1)continue;
            for(int i = 1; i <= cpow; ++i){
                if(cur == N - 1)break;
                cur = (__int128_t)cur * cur % N;
                if(i == cpow)return false;
            }
        }return true;
    }
}

int main(){

    ll val = read < ll >();

    // if(ans.find(val) != ans.end()){
    //     printf("%d\n", ans[val]);
    //     return 0;
    // }

    ll div = (ll)(sqrtl((long double)val) + EPS);
    if(((ll)div * (ll)div) == val){
        if(MillerRabin::Check(div)){printf("%lld\n", div);
        // else printf("-1\n");
        return 0;}
    }

    div = (ll)(powl((long double)val, 1.0 / 3.0) + EPS);
    if(div * div * div == val){
        ll div2 = (ll)(sqrtl((long double)div) + EPS);
        if(div2 * div2 == div){
            if(MillerRabin::Check(div2)){printf("%lld\n", div);
            // else printf("-1\n");
            return 0;}
        }
    }

    for(ll n = 1; n <= 33000; ++n){
        ll cnt(0);
        for(ll i = 1; i <= (ll)(sqrt(n) + EPS); ++i)
            if(n % i == 0)
                cnt += i * i == n ? 1 : 2;
        auto v = n;
        while(--cnt){
            v *= n;
            if(v > qpow128(10, 18)){
                v = -1;
                break;
            }
        }

        // if(n % 100 == 0)fprintf(stderr, "cur n = %lld\n", (ll)n);
        if(v == -1 || v > qpow128(10, 18))continue;

        if(val == v){
            printf("%lld\n", n);
            return 0;
        }

        // if(n <= 30)printf("n = %lld, v = %lld\n", n, v);
    }

    printf("-1\n");
    


    // printf("%d\n", ans.find(val) != ans.end() ? ans[val] : -1);



    // freopen("data.txt", "w", stdout);
    
    // __int128_t n = 0;
    // while(true) {
    //     ++n;
    //     __int128_t cnt(0);
    //     for(__int128_t i = 1; i <= n; ++i)
    //         cnt += (n % i == 0);
    //     // if((__int128_t)n * cnt > (__int128_t)1e18)break;
    //     // if((double)clock() / CLOCKS_PER_SEC > 1.0)break;
    //     if(n > 35000)break;
    //     // if(qpow128(n, cnt) > qpow128(10, 18))continue;
    //     auto val = n;
    //     while(--cnt){
    //         val *= n;
    //         if(val > qpow128(10, 18)){
    //             val = -1;
    //             break;
    //         }
    //     }

    //     if(n % 100 == 0)fprintf(stderr, "cur n = %lld\n", (ll)n);
    //     if(val == -1 || val > qpow128(10, 18))continue;


    //     printf("ans.insert({%lldll, %lld});\n", (ll)val, (ll)n);
        
    // }




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
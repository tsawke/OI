// #define _USE_MATH_DEFINES
// #include <bits/stdc++.h>

// #define PI M_PI
// #define E M_E

// using namespace std;

// mt19937 rnd(random_device{}());
// int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

// typedef unsigned int uint;
// typedef unsigned long long unll;
// typedef long long ll;

// using ull = unsigned long long;

// template<typename T = int>
// inline T read(void);

// const ll MOD = 998244353ll;

// /*
// *
// * Template Of Pollard Rho
// *
// */

// int t;
// ll max_factor, n;

// ll gcd(ll a, ll b) {
//   if (b == 0) return a;
//   return gcd(b, a % b);
// }

// ll bmul(ll a, ll b, ll m) {  // 快速乘
// //   ull c = (ull)a * (ull)b - (ull)((long double)a / m * b + 0.5L) * (ull)m;
// //   if (c < (ull)m) return c;
// //   return c + m;
//     return (ll)((__int128_t)a * b % m);
// }

// ll qpow(ll x, ll p, ll mod = MOD) {  // 快速幂
//   ll ans = 1;
//   while (p) {
//     if (p & 1) ans = bmul(ans, x, mod);
//     x = bmul(x, x, mod);
//     p >>= 1;
//   }
//   return ans;
// }

// // bool Miller_Rabin(ll p) {  // 判断素数
// //   if (p < 2) return false;
// //   if (p == 2) return true;
// //   if (p == 3) return true;
// //   ll d = p - 1, r = 0;
// //   while (!(d & 1)) ++r, d >>= 1;  // 将d处理为奇数
// //   for (ll k = 0; k < 10; ++k) {
// //     ll a = rnd() % (p - 2) + 2;
// //     ll x = qpow(a, d, p);
// //     if (x == 1 || x == p - 1) continue;
// //     for (int i = 0; i < r - 1; ++i) {
// //       x = bmul(x, x, p);
// //       if (x == p - 1) break;
// //     }
// //     if (x != p - 1) return false;
// //   }
// //   return true;
// // }
// namespace MillerRabin{
//     int radix[10] = {0,  2, 3, 5, 7, 11, 13, 19, 17};
//     // ll qpow(ll a, ll b, ll MOD){
//     //     ll ret(1), mul(a);
//     //     while(b){
//     //         if(b & 1)ret = (__int128_t)ret * mul % MOD;
//     //         b >>= 1;
//     //         mul = (__int128_t)mul * mul % MOD;
//     //     }return ret;
//     // }
//     ll qpow(ll x, ll p, ll mod = MOD) {  // 快速幂
//   ll ans = 1;
//   while (p) {
//     if (p & 1) ans = bmul(ans, x, mod);
//     x = bmul(x, x, mod);
//     p >>= 1;
//   }
//   return ans;
// }
//     bool Check(ll N){
//         if(N <= 2 || !(N & 1))return N == 2;
//         ll base(N - 1); int cpow(0);
//         while(base % 2 == 0)base >>= 1, ++cpow;
//         for(int t = 1; t <= 8; ++t){
//             if(radix[t] % N == 0)continue;
//             ll cur = qpow(radix[t] % N, base, N);
//             if(cur == 1)continue;
//             for(int i = 1; i <= cpow; ++i){
//                 if(cur == N - 1)break;
//                 cur = (__int128_t)cur * cur % N;
//                 if(i == cpow)return false;
//             }
//         }return true;
//     }
// };

// ll Pollard_Rho(ll x) {
//   ll s = 0, t = 0;
//   ll c = (ll)rnd() % (x - 1) + 1;
//   int step = 0, goal = 1;
//   ll val = 1;
//   for (goal = 1;; goal *= 2, s = t, val = 1) {  // 倍增优化
//     for (step = 1; step <= goal; ++step) {
//       t = (bmul(t, t, x) + c) % x;
//       val = bmul(val, abs(t - s), x);
//       if ((step % 127) == 0) {
//         ll d = gcd(val, x);
//         if (d > 1) return d;
//       }
//     }
//     ll d = gcd(val, x);
//     if (d > 1) return d;
//   }
// }

// vector < ll > cnt;//cnt[2];

// const int SIEVE = 1000000;
// vector < int > primes;
// vector < char > is_comp ( SIEVE + 1, 0 );
// void init_primes(){
//     for ( int i = 2; i <= SIEVE; ++i )
//         if ( !is_comp[i] ){
//             primes.push_back( i );
//             if ( 1LL * i * i <= SIEVE )
//                 for ( int j = i*i; j <= SIEVE; j += i ) is_comp[j] = 1;
//         }
// }


// void fac(ll x) {

//   if ( x == 1 ) return;
//     for ( int p : primes ){
//         if ( 1LL * p * p > x ) break;
//         if ( x % p == 0 ){
//             cnt.emplace_back(p);
//             while ( x % p == 0 ) x /= p;
//         }
//     }

//     if ( x == 1 ) return;
// //   if (x <= max_factor || x < 2) return;
//   if (MillerRabin::Check(x)) {              // 如果x为质数
//     // max_factor = max(max_factor, x);  // 更新答案
//     // cnt[x] += tims;
//     cnt.emplace_back(x);
//     return;
//   }
//   ll p = x;
//   while (p >= x) p = Pollard_Rho(x);  // 使用该算法
// //   int curt(0);
//   while ((x % p) == 0)x /= p;//, ++curt;//, ++cnt[idx][p];
//   fac(x), fac(p);  // 继续向下分解x和p


//     // i
//     // if ( MillerRabin::Check( n ) ){ fac.push_back( n ); return; }
//     // ll d = Pollard_Rho( n );
//     // factor( d, fac );
//     // factor( n / d, fac );
// }







// int main(){
//     init_primes();
//     // printf("%lld\n", qpow(2, ll(floorl(log2l((long double)1000000000000000000ll))), 1000000000000000000ll));
//     int T = read();
//     while(T--){
//         // srand((unsigned)time(NULL));
//         // max_factor = 0;
//         cnt.clear();
//         ll A = read < ll >(), B = read < ll >(), C = read < ll >(), D = read < ll >();
//         // fac(__gcd(A, C), 1);

//         ll g = __gcd( A, C );
//         if ( g == 1 ){
//             puts( "1" );
//             continue;
//         }
//         fac(g);
//         ll ans(1);
//         for(auto fact : cnt){
//             int cntA(0), cntC(0);
//             while(!(A % fact))A /= fact, ++cntA;
//             while(!(C % fact))C /= fact, ++cntC;
//             ans = (ans * qpow(fact, min((__int128_t)cntA * B, (__int128_t)cntC * D) % (MOD - 1))) % MOD;
//         }
//             // if(cnt[1].find(fact) != cnt[1].end())
//                 // ans = (ans * qpow(fact, min((__int128_t)(log2l((long double)A) / log2l((long double)fact)) * B, (__int128_t)(log2l((long double)C) / log2l((long double)fact)) * D) % (MOD - 1))) % MOD;
//         printf("%lld\n", ans);
//     }

//     // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
//     return 0;
// }



// template<typename T>
// inline T read(void){
//     T ret(0);
//     short flag(1);
//     char c = getchar();
//     while(c != '-' && !isdigit(c))c = getchar();
//     if(c == '-')flag = -1, c = getchar();
//     while(isdigit(c)){
//         ret *= 10;
//         ret += int(c - '0');
//         c = getchar();
//     }
//     ret *= flag;
//     return ret;
// }

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E  M_E

using namespace std;

mt19937_64 rnd(random_device{}());
int rndd(int l, int r){ return rnd() % (r - l + 1) + l; }

typedef unsigned int        uint;
typedef unsigned long long  unll;
typedef long long           ll;
using ull = unsigned long long;

template<typename T = int>
inline T read(void);

const ll MOD = 998244353ll;

const ll PHI = MOD - 1;

inline ll gcd(ll a, ll b){ return b ? gcd(b, a % b) : a; }

inline ll bmul(ll a, ll b, ll m){ return (unsigned __int128)a * b % m; }

ll qpow(ll x, ll p, ll mod = MOD){
    ll ans = 1;
    while(p){
        if(p & 1) ans = bmul(ans, x, mod);
        x = bmul(x, x, mod);
        p >>= 1;
    }
    return ans;
}

/* ---------------- Miller–Rabin 64-bit ---------------- */
namespace MillerRabin{
    bool Check(ull n){
        if(n < 2) return false;
        for(ull p:{2,3,5,7,11,13,17,19,23,29,31,37})
            if(n % p == 0) return n == p;
        ull d = n - 1, s = 0;
        while(!(d & 1)) d >>= 1, ++s;
        auto mod_pow = [&](ull a, ull e){
            ull r = 1;
            while(e){
                if(e & 1) r = bmul(r, a, n);
                a = bmul(a, a, n);
                e >>= 1;
            }
            return r;
        };
        for(ull a : {2ULL, 325ULL, 9375ULL, 28178ULL,
                     450775ULL, 9780504ULL, 1795265022ULL}){
            if(a % n == 0) continue;
            ull x = mod_pow(a, d);
            if(x == 1 || x == n - 1) continue;
            bool comp = true;
            for(ull r = 1; r < s; ++r){
                x = bmul(x, x, n);
                if(x == n - 1){ comp = false; break; }
            }
            if(comp) return false;
        }
        return true;
    }
}

/* ---------------- Brent 版 Pollard–Rho ---------------- */
ull Pollard_Rho(ull n){
    if(!(n & 1)) return 2;
    uniform_int_distribution<ull> dist(2, n - 2);
    while(true){
        ull c = dist(rnd);
        ull x = dist(rnd), y = x, d = 1, q = 1;
        const int M = 128;
        while(d == 1){
            for(int i = 0; i < M; ++i){
                x = (bmul(x, x, n) + c) % n;
                y = (bmul(y, y, n) + c) % n;
                y = (bmul(y, y, n) + c) % n;
                ull diff = x > y ? x - y : y - x;
                q = bmul(q, diff, n);
            }
            d = std::gcd(q, n);
        }
        if(d != n) return d;
    }
}


static const int SMALL_P[] = {
     2,  3,  5,  7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97
};

unordered_map<ull, vector<ull>> fac_cache;
vector<ull> cnt;

void fac(ull x){
    if(x == 1) return;
    if(fac_cache.count(x)){
        cnt.insert(cnt.end(), fac_cache[x].begin(), fac_cache[x].end());
        return;
    }

    vector<ull> tmp;

    for(int p : SMALL_P){
        if(1ULL * p * p > x) break;
        if(x % p == 0){
            tmp.push_back(p);
            while(x % p == 0) x /= p;
        }
    }

    if(x > 1){
        if(MillerRabin::Check(x)) tmp.push_back(x);
        else{
            ull d = Pollard_Rho(x);
            fac(d);
            fac(x / d);
            return;                     
        }
    }

    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    fac_cache[x] = tmp;
    cnt.insert(cnt.end(), tmp.begin(), tmp.end());
}


inline int count_pow(ull x, ull p){
    int c = 0; while(x % p == 0){ x /= p; ++c; } return c;
}


int main(){
    int T = read();
    while(T--){
        cnt.clear();

        ull A = read<ull>(), B = read<ull>(),
            C = read<ull>(), D = read<ull>();

        ull g = std::gcd(A, C);
        if(g == 1){
            puts("1");
            continue;
        }

        fac(g);


        sort(cnt.begin(), cnt.end());
        cnt.erase(unique(cnt.begin(), cnt.end()), cnt.end());

        ull ans = 1;
        for(ull p : cnt){
            int cntA = count_pow(A, p);
            int cntC = count_pow(C, p);
            ull exp = min((__int128)cntA * B, (__int128)cntC * D) % PHI;
            ans = ans * qpow(p % MOD, exp) % MOD;
        }
        printf("%llu\n", ans);
    }
    return 0;
}


template<typename T>
inline T read(void){
    T ret(0); short flag(1); char c = getchar();
    while(c != '-' && !isdigit(c)) c = getchar();
    if(c == '-') flag = -1, c = getchar();
    while(isdigit(c)){ ret = ret * 10 + (c - '0'); c = getchar(); }
    return ret * flag;
}

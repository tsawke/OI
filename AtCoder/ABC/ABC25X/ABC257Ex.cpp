#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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

ll inv36;
int N, K;
ll C[1100];
ll A[1100][10];
ll X[1100], Y[1100];
struct Node{
    int l, r;
    friend const bool operator < (const Node &a, const Node &b){
        return (Y[a.r] - Y[a.l]) * (X[b.l] - X[b.r]) < (Y[b.r] - Y[b.l]) * (X[a.l] - X[a.r]);
    }
};
basic_string < Node > mdfs;
bitset < 1100 > inAns;
ll ansX(0), ansY(0);
ll ans(LONG_LONG_MIN);
int idx[1100];

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

int main(){
    // freopen("in.txt", "r", stdin);
    inv36 = qpow(36ll, MOD - 2);
    N = read(), K = read();
    for(int i = 1; i <= N; ++i)C[i] = read(), idx[i] = i;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= 6; ++j)
            A[i][j] = read(),
            X[i] += A[i][j], //6Xi
            Y[i] += 6 * A[i][j] * A[i][j]; //36Yi
        Y[i] -= X[i] * X[i] + 36 * C[i];
    }
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)if(X[i] < X[j])mdfs += Node{i, j};
    sort(mdfs.begin(), mdfs.end());
    sort(idx + 1, idx + N + 1, [](const int &a, const int &b)->bool{return X[a] < X[b];});
    for(int i = 1; i <= K; ++i)
        ansX += X[idx[i]], ansY += Y[idx[i]], inAns[idx[i]] = true;
    ans = max(ans, ansX * ansX + ansY);
    for(auto mdf : mdfs)
        if(inAns[mdf.l] && !inAns[mdf.r])
            inAns[mdf.l] = false, inAns[mdf.r] = true,
            ansX += -X[mdf.l] + X[mdf.r], ansY += -Y[mdf.l] + Y[mdf.r],
            ans = max(ans, ansX * ansX + ansY);
    printf("%lld\n", (ans % MOD * inv36 % MOD + MOD) % MOD);
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
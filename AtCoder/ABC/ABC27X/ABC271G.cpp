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

ll N;
ll Taka, Aoki;
ll p[30];
ll P(1);
ll ansv(0);
ll inv100;
ll dp[30][30];
bitset < 30 > belong;

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

class Matrix{
private:
    int siz;
    ll v[30][30];
public:
    Matrix(int len = 24, int pat = 0){
        siz = len;
        for(int i = 0; i < siz; ++i)
            for(int j = 0; j < siz; ++j)
                v[i][j] = 0;
        switch(pat){
            case 1:{
                for(int i = 0; i < siz; ++i)v[i][i] = 1;
                break;
            }
            case 2:{
                v[0][siz - 1] = 1;
                break;
            }
            case 3:{
                for(int i = 1; i <= siz; ++i)
                    for(int j = 1; j <= siz; ++j)
                        v[i - 1][j - 1] = dp[i][j];
                break;
            }
            default: break;
        }
    }
    friend Matrix operator * (const Matrix &a, const Matrix &b){
        Matrix ret(24);
        for(int i = 0; i < 24; ++i)
            for(int j = 0; j < 24; ++j)
                for(int k = 0; k < 24; ++k)
                    (ret.v[i][j] += a.v[i][k] * b.v[k][j] % MOD) %= MOD;
        return ret;
    }
    void SetAns(void){
        for(int i = 0; i < 24; ++i)
            if(belong[i + 1])(ansv += v[0][i]) %= MOD;
    }
    void Print(void){
        printf("##########\n");
        for(int i = 0; i < siz; ++i)
            for(int j = 0; j < siz; ++j)
                printf("%lld%c", v[i][j], j == siz - 1 ? '\n' : ' ');
        printf("##########\n");
    }
}ans(24, 2);

Matrix qpow(Matrix a, ll b){
    Matrix ret(24, 1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul;
        b >>= 1;
        mul = mul * mul;
    }return ret;
}

int main(){
    inv100 = qpow(100, MOD - 2);
    N = read < ll >(), Taka = read(), Aoki = read();
    for(int i = 1; i <= 24; ++i){
        char c = getchar(); while(!isalpha(c))c = getchar();
        p[i] = c == 'T' ? Taka : Aoki, belong[i] = c == 'T' ? false : true;
        (P *= (100 - p[i]) * inv100 % MOD) %= MOD;
    }
    for(int i = 1; i <= 24; ++i){
        for(int j = 1; j <= 24; ++j){
            ll R(1);
            if(i < j)for(int k = i + 1; k <= j - 1; ++k)(R *= (100 - p[k]) * inv100 % MOD) %= MOD;
            else{
                for(int k = i + 1; k <= 24; ++k)(R *= (100 - p[k]) * inv100 % MOD) %= MOD;
                for(int k = 1; k <= j - 1; ++k)(R *= (100 - p[k]) * inv100 % MOD) %= MOD;
            }
            dp[i][j] = R * (p[j] * inv100 % MOD) % MOD * qpow((1 - P + MOD) % MOD, MOD - 2) % MOD;
        }
    }
    Matrix base(24, 3);
    (ans * qpow(base, N)).SetAns();
    printf("%lld\n", ansv);
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
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

#define S(i) (S.at(i - 1))
#define MOD (K)

template < typename T = int >
inline T read(void);

int N, M, K;
string S;
int nxt[30];
int G[30][30];

class Matrix{
private:
public:
    int v[20][20];
    Matrix(void){memset(v, 0, sizeof v);}
    friend Matrix operator * (const Matrix &a, const Matrix &b){
        Matrix ret;
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < M; ++j)
                for(int k = 0; k < M; ++k)
                    (ret.v[i][j] += a.v[i][k] * b.v[k][j] % MOD) %= MOD;
        return ret;
    }
    void Print(void){
        printf("Matrix:\n");
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < M; ++j)
                printf("%d%c", v[i][j], j == M - 1 ? '\n' : ' ');
    }
}base, ans;

Matrix qpow(Matrix a, ll b){
    Matrix ret, mul(a);
    for(int i = 0; i < M; ++i)ret.v[i][i] = 1;
    while(b){
        if(b & 1)ret = ret * mul;
        b >>= 1;
        mul = mul * mul;
    }return ret;
}

int main(){
    N = read(), M = read(), K = read();
    cin >> S;
    int lst(0);
    for(int i = 2; i <= M; ++i){
        while(lst && S(lst + 1) != S(i))lst = nxt[lst];
        if(S(lst + 1) == S(i))++lst;
        nxt[i] = lst;
    }
    for(int i = 0; i < M; ++i)
        for(int j = '0'; j <= '9'; ++j){
            int lst = i;
            while(lst && S(lst + 1) != j)lst = nxt[lst];
            if(S(lst + 1) == j)++lst;
            ++G[i][lst];
        }
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < M; ++j)
            base.v[i][j] = G[i][j] % MOD;
    ans.v[0][0] = 1;
    ans = ans * qpow(base, N);
    int rans(0);
    for(int i = 0; i < M; ++i)(rans += ans.v[0][i]) %= MOD;
    printf("%d\n", rans);
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
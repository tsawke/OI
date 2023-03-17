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

int N, M;
ll F[3100][3100], G[3100][3100];

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)F[0][i] = 1;
    G[0][0] = 1;
    for(int i = 1; i <= M; ++i)
        for(int j = 0; j <= N; ++j){
            if(j - 1 >= 0){
                (F[i][j] += F[i - 1][j - 1]) %= MOD;
                (G[i][j] += G[i - 1][j - 1] + G[i - 1][j]) %= MOD;
                ((j == 1 ? G[i][j] : F[i][j]) += F[i - 1][j]) %= MOD;
            }
            if(j + 1 <= N){
                (G[i][j] += G[i - 1][j + 1] + G[i - 1][j]) %= MOD;
                j == 0 ? (G[i][j] += F[i - 1][j + 1]) %= MOD : (F[i][j] += F[i - 1][j + 1] + F[i - 1][j]) %= MOD;
            }
        }
    ll ans(0);
    for(int i = 0; i <= N; ++i)(ans += G[M][i]) %= MOD;
    printf("%lld\n", ans);
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
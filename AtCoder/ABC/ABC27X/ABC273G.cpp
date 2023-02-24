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

int N;
ll sumC(0);
ll dp[5100][5100];
int R[5100], C[5100];
int cnt1(0);

int main(){
    // freopen("in.txt", "r", stdin);
    N = read();
    for(int i = 1; i <= N; ++i)R[i] = read();
    for(int i = 1; i <= N; ++i)sumC += (C[i] = read());
    for(int i = 1; i <= N; ++i)if(C[i] == 1)++cnt1;
    dp[0][cnt1] = 1;
    for(int i = 1; i <= N; ++i){
        sumC -= R[i];
        for(int j = 0; j <= N; ++j){
            if((sumC - j) & 1)continue;
            int k = (sumC - j) >> 1;
            switch(R[i]){
                case 0:{
                    dp[i][j] = dp[i - 1][j];
                    break;
                }
                case 1:{
                    (dp[i][j] += dp[i - 1][j + 1] * (j + 1) % MOD) %= MOD;
                    if(j - 1 >= 0)(dp[i][j] += dp[i - 1][j - 1] * (k + 1) % MOD) %= MOD;
                    break;
                }
                case 2:{
                    (dp[i][j] += dp[i - 1][j + 2] * ((j + 2) * (j + 1) / 2 % MOD) % MOD) %= MOD;
                    (dp[i][j] += dp[i - 1][j] * (k + 1) % MOD) %= MOD;
                    if(j - 2 >= 0)(dp[i][j] += dp[i - 1][j - 2] * ((k + 2) * (k + 1) / 2 % MOD) % MOD) %= MOD;
                    (dp[i][j] += dp[i - 1][j] * (k + 1) % MOD * j % MOD) %= MOD;
                    break;
                }
            }
        }
    }
    printf("%lld\n", sumC ? 0 : dp[N][0]);
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
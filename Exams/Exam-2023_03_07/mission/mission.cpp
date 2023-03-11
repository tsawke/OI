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

#define EPS (1e-5)

template < typename T = int >
inline T read(void);

int N, M;
double Px[110];
double dp[2][2100];
// class SegTree{
// private:
//     double tr[5100000 << 2];
// }

// class BIT{
// private:
//     double tr[5100000];
// public:
//     int lowbit(int x, )
// }

bool eq(double a, double b){return fabs(a - b) < EPS;}

int main(){
    freopen("mission.in", "r", stdin);
    freopen("mission.out", "w", stdout);
    // ll sum(0), cur(1);
    // for(; cur < 5000000; cur <<= 1)sum += cur;
    // sum += cur;
    // printf("%lld\n", sum);
    // // 16777215 => 127.99999MiB

    // double P = 0.23456;
    // double cur(P), sum(0.0);
    // for(int i = 1; i <= (int)1e7; ++i){
    //     sum += cur * i, cur *= P;
    // }printf("%.5lf\n", sum);
    // printf("%.5lf\n", P / (1 - P) / (1 - P));

    N = read(), M = read();
    bool flag(true);
    for(int i = 0; i <= N; ++i){
        int a = read(), b = read();
        Px[i] = (double)a / b;
        if(!eq(Px[i], 1.0 / (N + 1)))flag = false;
    }
    if(true){
        double ans(0.0);
        dp[0][0] = 1.0;
        int step(1);
        for(bool cur = 0; true; cur ^= 1, ++step){
            memset(dp[cur ^ 1], 0, sizeof dp[cur ^ 1]);
            for(int j = 0; j < M; ++j){
                for(int k = 0; k <= N; ++k)
                dp[cur ^ 1][j + k > M ? M : j + k] += dp[cur][j] * Px[k];
            }ans += step * dp[cur ^ 1][M];
            // if(step <= 10)printf("dp[m] = %.5lf\n", dp[cur ^ 1][M]);
            if((double)clock() / CLOCKS_PER_SEC > 0.80 || step > (int)1e8)break;
        }printf("%.5lf\n", ans);
    }else{

    }
    


    // if(flag){
    //     double P = Px[0];
    //     double K = P / (1 - P);
    //     double xi = P / (1 - P) / (1 - P);
    // }
    // if(equal(Px[0], 0.0)){

    // }


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
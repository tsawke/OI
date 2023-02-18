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

int N;
int G[1100][1100];

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    N = read();
    for(int i = 1; i <= N; ++i)
        for(int j = i + 1; j <= N; ++j)
            G[i][j] = G[j][i] = read();
    int opt = read();
    switch(opt){
        case 0:{
            int s = read(), t = read();
            printf("%.5Lf\n", (ld)G[s][t] * 2.0 / (ld)N);
            break;
        }
        case 1:{
            int s = read(), t = read();
            // printf("%d\n", G[s][t]);
            ld ans(0.0);
            // ans += (ld)G[s][t] * 2.0 / (ld)N;
            for(int i = 1; i <= N; ++i)
                if(i != s)ans += G[s][i] * (1.0 - 2.0 / (ld)N) / (ld)(N - 2);
            for(int i = 1; i <= N; ++i)
                if(i != t)ans += G[t][i] * (1.0 - 2.0 / (ld)N) / (ld)(N - 2);
            // for(int i = 1; i <= N; ++i)
            //     if(i != s && i != t)
            //         ans += (ld)(G[s][i] + G[i][t]) * 2.0 / (ld)N * 2.0 / (ld)N;
            // ld base(0.0);
            // for(int i = 1; i <= N - 4; ++i){
            //     ld val(1.0);
            //     int lim = (2 * N - 1) - (N - 2) * (i - 1);
            //     int lfti(i), lftN(2 * N - 1 - i), powN(i + 2), pow2(i + 2);
            //     int cur(2 * N - 1);
            //     for(int j = i - 1; j; --j){
            //         val *= cur;
            //         // if(lfti)val /= lfti, --lfti;
            //         // if(lftN)val /= lftN, --lftN;
            //         if(pow2)val *= 2.0, --pow2;
            //         if(powN)val /= N, --powN;
            //         cur -= N - 2;
            //     }
            //     while(powN)val /= N, --powN;
            //     while(pow2)val *= 2.0, --pow2;
            //     base += val;
            // }printf("%.12Lf\n", base);
            // for(int i = 1; i <= N; ++i){
            //     if(i == s || i == t)continue;
            //     for(int j = 1; j <= N; ++j){
            //         if(j == i || j == s || j == t)continue;
            //         ans += (ld)(G[s][i] + G[j][t]) * base;
            //     }
            // }
            printf("%.5Lf\n", ans);
            break;
        }
        case 2:{
            puts("qwq");
        }
        default: break;
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
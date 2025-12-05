#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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



int main(){
    freopen("pairs.in", "r", stdin);
    freopen("pairs.out", "w", stdout);
    puts("qwq");

    // freopen("in.txt", "w", stdout);
    // int N = 100000;
    // printf("%d\n", N);
    // for(int i = 2; i <= N; ++i)
    //     printf("%d %d\n", i, rndd(1, i - 1));
    // for(int i = 1; i <= N; ++i)printf("%d%c", 1000000000, i == N ? '\n' : ' ');
    // int Q = 100000;
    // printf("%d\n", Q);
    // for(int i = 1; i <= Q; ++i){
    //     printf("%d %d %d\n", rndd(0, 1), rndd(1, N), rndd(900, 1000));
    // }
    // printf("%d %d\n", N, K);
    // for(int i = 1; i <= K; ++i)for(int j = 1; j <= K; ++j)printf("1%c", j == K ? '\n' : ' ');
    // for(int i = 1; i <= N - 1; ++i)printf("%d%c", 1, i == N - 1 ? '\n' : ' ');

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
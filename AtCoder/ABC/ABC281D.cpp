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

template < typename T = int >
inline T read(void);

ll buc[110][110];
int N, K, D;

int main(){
    // freopen("in.txt", "r", stdin);
    memset(buc, -1, sizeof buc);
    N = read(), K = read(), D = read();
    for(int n = 1; n <= N; ++n){
        ll nbuc[110][110];
        memset(nbuc, -1, sizeof nbuc);
        int val = read();
        int idx = val % D;
        for(int i = 0; i <= D - 1; ++i)
            for(int j = 1; j < K; ++j)
                if(~buc[i][j])
                    nbuc[(i + idx) % D][j + 1] = max(nbuc[(i + idx) % D][j + 1], buc[i][j] + val);
        nbuc[idx][1] = max(nbuc[idx][1], (ll)val);
        for(int i = 0; i <= D - 1; ++i)
            for(int j = 1; j <= K; ++j)
                buc[i][j] = max(buc[i][j], nbuc[i][j]);
    }
    // for(int i = 0; i <= D - 1; ++i){
    //     for(int j = 1; j <= K; ++j)
    //         printf("dp[%d][%d] = %lld  ", i, j, buc[i][j]);
    //     printf("\n");
    // }
    printf("%lld\n", buc[0][K]);
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

/*
checker:

while(true){
    FILE *in = fopen("in.txt", "w");
    int N = rndd(5, 10), K = rndd(2, N), D = rndd(2, 10);
    fprintf(in, "%d %d %d\n", N, K, D);
    for(int i = 1; i <= N; ++i)fprintf(in, "%d\n", rndd(1, 10));
    fclose(in);
    system("./bl < in.txt > bl.out");
    system("./std < in.txt > std.out");
    if(system("diff bl.out std.out"))fprintf(stderr, "Error\n"), exit(0);
    static int cnt(0);
    fprintf(stderr, "Accept at %d\n", ++cnt);
}

*/
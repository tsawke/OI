#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);



int main(){
    // while(true){
        

    // }
    // FILE* f = fopen("./in.txt", "w");
    freopen("in.txt", "w", stdout);
    int N = 1000000, M = 999999, K = 1000000, Q = 1000000;
    printf("%d %d %d %d\n", N, M, K, Q);
    for(int i = 1; i <= N; ++i)printf("%d%c", 200, i == N ? '\n' : ' ');
    for(int i = 0; i <= M; ++i)printf("%d%c", 200, i == M ? '\n' : ' ');
    while(Q--){
        // if(rndd(1, 100) >= 33)
        printf("q %d %d\n", rndd(1, N + M));
        // else if(rndd(1, 100) >= 50)printf("c %d\n", rndd(1, N));
        // else printf("x %d\n", rndd(N, N + M));
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
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
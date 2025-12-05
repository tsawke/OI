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
    freopen("out.txt", "w", stdout);
    int N = read();
    int tot = 1 << N;
    for(int i = 1; i <= tot / (N << 1); ++i){
        // printf("i = %d\n", i);
        for(int j = 0; j <= N; ++j){
            for(int k = 1; k <= j; ++k)printf("1");
            for(int k = j + 1; k <= N; ++k)printf("0");
            printf("\n");
        }
        for(int j = N - 1; j >= 1; --j){
            for(int k = 1; k <= j; ++k)printf("1");
            for(int k = j + 1; k <= N; ++k)printf("0");
            printf("\n");
        }
    }
    int left = tot % (N << 1);
    // for(int c = 1; c <= (left >> 1); ++c){
        for(int k = 2; k <= 2 + (left >> 1) - 1; ++k){
            printf("1");
            for(int i = 2; i < k; ++i)printf("0");
            printf("1");
            for(int i = k + 1; i <= N; ++i)printf("0");
            printf("\n");

            printf("1");
            for(int i = 2; i <= N; ++i)printf("0");
            printf("\n");
        }
    // }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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
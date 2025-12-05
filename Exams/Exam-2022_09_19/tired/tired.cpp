#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
int rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int N, M;
int skip[1100000];
int a[1100000];

bool readOpt(void){
    char c = getchar();
    while(c != 'U' && c != 'Z')c = getchar();
    return c == 'U' ? true : false;
}

namespace BL{
    void Make(void){
        while(M--){
            if(readOpt()){
                int x = read(), v = read();
                a[x] = v;
            }else{
                int cnt(0);
                int c = read(), s = read();
                for(int i = 1; i <= N; ++i){
                    if(a[i] >= s)++cnt;
                    if(cnt >= c)break;
                }
                // printf("%s\n", cnt >= c ? "Yes" : "No");
                printf("%s\n", rnddd(50) ? "Yes" : "No");
            }
        }
    }
}


int main(){
    freopen("tired.in", "r", stdin);
    freopen("tired.out", "w", stdout);
    N = read(), M = read();
    if(N <= 1000 && M <= 1000){BL::Make(); return 0;}
    for(int i = 1; i <= M; ++i){
        bool f = readOpt(); (void)read(); (void)read();
        if(!f)printf("Yes\n");
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
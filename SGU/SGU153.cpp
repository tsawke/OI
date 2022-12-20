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

int N, M;
int P[10];
bitset < 1300 > SG;

int main(){
    int T = read();
    while(T--){
        SG.reset();
        N = read(), M = read();
        P[0] = 1;
        for(int i = 1; i <= M; ++i)P[i] = read();
        SG[0] = true;
        for(int i = 1; i <= 1200; ++i)
            for(int p = 0; p <= M; ++p)
                if(i - P[p] >= 0)
                    SG[i] = SG[i] | (SG[i - P[p]] ^ 1);
        int rlen(-1);
        for(int len = 1; len <= 520; ++len){
            bool flag(true);
            for(int s = 0; s <= 1100 - len * 2 + 10; s += len)
                for(int i = s; i <= s + len - 1; ++i)
                    if(SG[i] != SG[i + len]){flag = false; break;}
            if(flag){rlen = len; break;}
        }//printf("rlen = %d\n", rlen);
        // for(int i = 0; i <= 20; ++i)printf("SG[%d] = %d\n", i, SG[i] ? 1 : 0);
        printf("%s\n", SG[N % rlen] ? "FIRST PLAYER MUST WIN" : "SECOND PLAYER MUST WIN");
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
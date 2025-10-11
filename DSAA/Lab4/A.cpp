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

template < typename T = int >
inline T read(void);



int main(){
    int T = read();
    while(T--){
        int N = read();
        vector < int > val(N + 10, 0), P(N + 10, 0);
        for(int i = 1; i <= N; ++i)val[i] = read();
        for(int i = 1; i <= N; ++i)P[i] = read();
        vector < bool > B(N + 10, false);
        vector < int > cur = val;
        for(int i = N; i >= 1; --i){
            bool poss1(true), poss0(true);
            int p(i);
            int mx(-1), mn(-1);
            
            while(p > 1){
                if(cur[p] >= val[i])poss0 = false;
                if(cur[p] <= val[i])poss1 = false;
                p >>= 1;
                if(poss1 && cur[p] == val[i])mx = p;
                if(poss0 && cur[p] == val[i])mn = p;
            }
            if(poss1)
        }
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
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
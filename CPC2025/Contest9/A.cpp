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

int N;
int D[110], cur[110];
int ans(0);


int main(){
    N = read();
    for(int i = 1; i <= N; ++i)D[i] = read();
    while(true){

        // for(int i = 1; i <= N; ++i)printf("%d%c", cur[i], i == N ? '\n' : ' ');
        // _sleep(1);
        bool flag(true);
        for(int i = 1; i <= N; ++i)
            if(cur[i] != D[i]){flag = false; break;}
        if(flag){printf("%d\n", ans); exit(0);}

        int mn(INT_MAX), mnp(-1);
        for(int i = 1; i <= N; ++i)
            if(cur[i] != D[i] && cur[i] < mn)mn = cur[i], mnp = i;
        
        int d(D[mnp] - cur[mnp]);
        int L(mnp), R(mnp);
        
        for(int i = mnp + 1; i <= N && cur[i] != D[i]; ++i)
            d = min(d, D[i] - cur[i]), R = i;

        for(int i = mnp - 1; i >= 1 && cur[i] != D[i]; --i)
            d = min(d, D[i] - cur[i]), L = i;

        ++ans;
        for(int i = L; i <= R; ++i)cur[i] += d;
    }

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
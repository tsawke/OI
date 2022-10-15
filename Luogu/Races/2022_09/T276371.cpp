#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);

int N;
bitset < 310000 > sec;
int buc[310000];
int sz[310000];
int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        int l = read(), r = read();
        sz[l]++, sz[r + 1]--;
        // if(l == r){
        //     sec[l] = true;
        //     buc[l] = buc[l] ? buc[l] : -1;
        //     continue;
        // }

        sec[l] = sec[r] = true;
        //1-l, 2-r, 3-lr
        buc[l] = buc[l] ? (buc[l] == 2 ? 3 : buc[l]) : 1;
        buc[r] = buc[r] ? (buc[r] == 1 ? 3 : buc[r]) : 2;
    }
    for(int i = 1; i <= 301000; ++i)sz[i] += sz[i - 1];
    // int p = 1;
    // int ans(-1), szz(-1);
    // while(p <= 300100){
    //     int nxt(p);
    //     do{++nxt;}while(!buc[nxt] && nxt <= 300100);
    //     int cur = nxt - p - 1 + (buc[p] == 1 || buc[p] == -1 ? 1 : 0) + (buc[nxt] == 2 || buc[nxt] == -1 ? 1 : 0);
    //     if(cur > ans){
    //         ans = cur;
    //         szz = sz[p];
    //     }
    //     p = nxt;
    // }
    // printf("%d\n", ans);
    int p = sec._Find_first();
    int ans(-1), szz(-1);
    while(true){
        int nxt = sec._Find_next(p);
        if(nxt == (int)sec.size())break;
        int cur = nxt - p - 1 + ((buc[p] == 1 || buc[p] == -1) ? 1 : 0) + ((buc[nxt] == 2 || buc[nxt] == -1) ? 1 : 0) - 1;
        if(cur > ans){
            ans = cur;
            szz = sz[p];
            // printf("%d-%d => %d\n", p, nxt, cur);
        }
        p = nxt;
    }
    printf("%d\n", ans * szz);
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
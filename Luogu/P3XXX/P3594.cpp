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
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);

int N, D;
ll P;
int a[2100000];
ll sum[2100000];
ll sumd[2100000];
int main(){
    N = read(), P = read<ll>(), D = read();
    for(int i = 1; i <= N; ++i)a[i] = read(), sum[i] = sum[i - 1] + a[i];
    for(int i = D; i <= N; ++i)sumd[i] = sum[i] - sum[i - D];
    deque < ll > mxv; mxv.push_back(D); //section-D
    int ans(D); //len-D
    int lst(1);
    for(int i = D + 1; i <= N; ++i){
        while(!mxv.empty() && sumd[i] > sumd[mxv.back()])mxv.pop_back();
        mxv.push_back(i);
        while(!mxv.empty() && mxv.front() - D + 1 < lst)mxv.pop_front();
        while(sum[i] - sum[lst - 1] - sumd[mxv.front()] > P){
            ++lst;
            while(!mxv.empty() && mxv.front() - D + 1 < lst)mxv.pop_front();
        }
        ans = max(ans, i - lst + 1);
    }
    printf("%d\n", ans);
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
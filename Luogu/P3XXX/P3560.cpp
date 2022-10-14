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
stms => sum_times
ctms => current_times
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

int N, M;
unordered_map < int, int > seq;
int tms[1100000];
int ctms(0);
int stms(0);
int a[1100000];
int ans(0);
int main(){
    N = read(), M = read();
    int tmp[1100000];
    for(int i = 1; i <= M; ++i)tmp[i] = read(), stms += tmp[i];
    for(int i = 1; i <= M; ++i)tms[read()] = tmp[i];
    for(int i = 1; i <= N; ++i)a[i] = read();
    for(int i = 1; i <= stms; ++i){
        if(seq.find(a[i]) != seq.end())seq[a[i]]++;
        else seq.insert({a[i], 1});
        if(seq[a[i]] <= tms[a[i]])++ctms;
    }
    if(ctms == stms)++ans;
    for(int i = stms + 1; i <= N; ++i){
        int tail = i - stms;
        if(seq[a[tail]] <= tms[a[tail]])--ctms;
        seq[a[tail]]--;
        if(seq.find(a[i]) != seq.end()){
            if(seq[a[i]] < tms[a[i]])++ctms;
            seq[a[i]]++;
        }else{
            if(tms[a[i]])++ctms;
            seq.insert({a[i], 1});
        }
        if(ctms == stms)++ans;
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
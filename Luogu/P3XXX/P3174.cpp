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
tm/tim => time
lt/lft => left
bg => begin
ed => end
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

#define MAXNM 110000
#define CLEAR(arr) memset(arr, 0, sizeof(arr))

template<typename T = int>
inline T read(void);

int N, M;
tuple < int, int, int > in[MAXNM];
struct Worker{int l, r;}wk[MAXNM];
int bg[MAXNM], ed[MAXNM];
int note[MAXNM];
void clear(void){
    CLEAR(wk);
    CLEAR(note);
    CLEAR(bg), CLEAR(ed);
}
bool check(int lim){
    clear();
    for(int i = 1; i <= lim; ++i){
        int tm, n, lt;
        tie(tm, n, lt) = in[i];
        if(note[tm] && note[tm] != lt)return false;
        note[tm] = lt,
        wk[n].l = min(wk[n].l ? wk[n].l : INT_MAX, tm),
        wk[n].r = max(wk[n].r, tm);
    }
    for(int i = 1; i <= N; ++i)if(wk[i].r)++bg[wk[i].l], ++ed[wk[i].r];
    int cur(0), fre(N), extl(0), extr(0);
    for(int i = 1; i <= M; ++i){
        if(!note[i])continue;
        cur += bg[i];
        if(cur > note[i])return false;
        while(bg[i]--)extl ? --extl : --fre;
        while(cur + extl + extr < note[i])--fre, ++extl;
        if(fre < 0)return false;
        while(cur + extl + extr > note[i])extr ? --extr : --extl;
        extr += ed[i], cur -= ed[i];
    }
    return true;
}

int main(){
    int T = read();
    while(T--){
        // in.clear(), in.shrink_to_fit();
        N = read(), M = read();
        for(int i = 1; i <= M; ++i){
            int tm = read(), num = read(), lft = read(); ++lft;
            in[i] = {tm, num, lft};
        }
        int l = 1, r = M;
        int ans(-1);
        while(l <= r){
            int mid = (l + r) >> 1;
            check(mid) ? l = mid + 1, ans = mid : r = mid - 1;
        }
        printf("%d\n", ans);
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
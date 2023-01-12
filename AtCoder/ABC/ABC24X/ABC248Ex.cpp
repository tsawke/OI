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

#define MAXN (150000)

template < typename T = int >
inline T read(void);

int N, K;
int a[MAXN];
ll ans(0);
int mx[MAXN], mn[MAXN];
int buc[MAXN << 1];

void Divide(int gl = 1, int gr = N){
    if(gl == gr)return ++ans, void();
    int MID = (gl + gr) >> 1;
    mx[MID] = mn[MID] = a[MID], mx[MID + 1] = mn[MID + 1] = a[MID + 1];
    for(int i = MID - 1; i >= gl; --i)mx[i] = max(mx[i + 1], a[i]), mn[i] = min(mn[i + 1], a[i]);
    for(int i = MID + 2; i <= gr; ++i)mx[i] = max(mx[i - 1], a[i]), mn[i] = min(mn[i - 1], a[i]);
    int sp1(MID), sp2(MID);
    for(int l = MID; l >= gl; --l){
        while(sp1 + 1 <= gr && mx[sp1 + 1] <= mx[l])++sp1, buc[sp1 + mn[sp1]]++;
        while(sp2 + 1 <= gr && mn[sp2 + 1] >= mn[l])++sp2, buc[sp2 + mn[sp2]]--;
        for(int k = 0; k <= K; ++k){
            int r = l + mx[l] - mn[l] - k;
            int idx = l + mx[l] - k;
            if(MID + 1 <= r && r <= min(sp1, sp2))++ans;
            if(sp2 < sp1 && idx > 0)ans += buc[idx];
        }
    }for(int i = MID + 1; i <= gr; ++i)buc[i + mn[i]] = 0;
    sp1 = MID + 1, sp2 = MID + 1;
    for(int r = MID + 1; r <= gr; ++r){
        while(sp1 - 1 >= gl && mx[sp1 - 1] <= mx[r])--sp1, buc[sp1 - mn[sp1] + N]++;
        while(sp2 - 1 >= gl && mn[sp2 - 1] >= mn[r])--sp2, buc[sp2 - mn[sp2] + N]--;
        for(int k = 0; k <= K; ++k){
            int l = r - mx[r] + mn[r] + k;
            int idx = r - mx[r] + k + N;
            if(max(sp1, sp2) <= l  && l <= MID)++ans;
            if(sp1 < sp2 && idx > 0)ans += buc[idx];
        }
    }for(int i = gl; i <= MID; ++i)buc[i - mn[i] + N] = 0;
    Divide(gl, MID), Divide(MID + 1, gr);
}

int main(){
    N = read(), K = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    Divide();
    printf("%lld\n", ans);
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
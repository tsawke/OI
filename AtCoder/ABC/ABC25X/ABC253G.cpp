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

int N;
ll L, R;
ll spl[210000];
int a[210000];
int ans[210000];

int main(){
    N = read(), L = read < ll >(), R = read < ll >();
    for(int i = 1; i <= N; ++i)a[i] = i;
    for(int i = 1; i <= N; ++i)spl[i] = spl[i - 1] + N - i;
    int lp = distance(spl, lower_bound(spl + 1, spl + N + 1, L));
    int rp = distance(spl, upper_bound(spl + 1, spl + N + 1, R));
    if(lp == rp){
        for(ll cur = L; cur <= R; ++cur){
            int pos = cur - spl[lp - 1];
            swap(a[lp], a[lp + pos]);
        }
        for(int i = 1; i <= N; ++i)printf("%d%c", a[i], i == N ? '\n' : ' ');
        exit(0);
    }
    for(ll cur = L; cur <= spl[lp]; ++cur){
        int pos = cur - spl[lp - 1];
        swap(a[lp], a[lp + pos]);
    }
    for(int i = 1; i <= lp; ++i)ans[i] = a[i];
    if(lp + 1 < rp){
        int s = lp + 1, siz = rp - lp - 1;
        for(int cnt = 0; s + siz + cnt <= N; ++cnt)ans[s + siz + cnt] = a[s + cnt];
        for(int cnt = 0; cnt <= siz - 1; ++cnt)ans[s + cnt] = a[N - cnt];
    }else
        for(int i = 1; i <= N; ++i)ans[i] = a[i];
    for(ll cur = spl[rp - 1] + 1; cur <= R; ++cur){
        int pos = cur - spl[rp - 1];
        swap(ans[rp], ans[rp + pos]);
    }
    for(int i = 1; i <= N; ++i)printf("%d%c", ans[i], i == N ? '\n' : ' ');
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
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

#define int ll

template<typename T = int>
inline T read(void);

int M, D, N;
vector < int > dis;

signed main(){
    // freopen("in.txt", "r", stdin);
    M = read(), D = read(), N = read();
    for(int i = 1; i <= N; ++i)dis.push_back(read());
    sort(dis.begin(), dis.end(), greater < int >());
    auto ptr = lower_bound(dis.rbegin(), dis.rend(), M - D);
    if(ptr == dis.rend()){printf("0\n"); return 0;}
    int val = *ptr;
    dis.erase((++ptr).base());
    int cur(0), ans(0);
    for(auto i : dis){
        cur += i - (D - cur);
        ++ans;
        if(cur <= 0){--ans; break;}
        if(cur >= M){printf("%lld\n", ans); return 0;}
        if(cur >= D - (val - (M - D)) / 2){printf("%lld\n", ans + 1); return 0;}
        // printf("cur:%d, ans:%d\n", cur, ans);
    }
    if((D - cur) * 2 + (M - D) <= val)printf("%lld\n", ans + 1);
    else printf("0\n");
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
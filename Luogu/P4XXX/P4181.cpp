#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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

template< typename T = int >
inline T read(void);

int N, M, R;
int c[110000];
struct Milk{
    int pri, siz;
    friend const bool operator < (const Milk &a, const Milk &b){
        if(a.pri == b.pri)return a.siz > b.siz;
        return a.pri > b.pri;
    }
}mlk[110000];
int buy[110000];
int cur(0);

signed main(){
    N = read(), M = read(), R = read();
    for(int i = 1; i <= N; ++i)c[i] = read();
    for(int i = 1; i <= M; ++i)mlk[i].siz = read(), mlk[i].pri = read();
    for(int i = 1; i <= R; ++i)buy[i] = read();
    sort(c + 1, c + N + 1, greater < int >());
    sort(mlk + 1, mlk + M + 1);
    sort(buy + 1, buy + R + 1, greater < int >());
    int unsel(0), sel(N);
    int curus(0);
    int curs(N);
    int lftmlk(0);
    int curmlkn(0);
    int mx(-1);
    for(int i = 1; i <= min(N, R); ++i)cur += buy[i];
    do{
        while(curus < unsel)lftmlk += c[++curus];
        while(lftmlk && curmlkn < M){
            ++curmlkn;
            if(lftmlk >= mlk[curmlkn].siz)
                cur += mlk[curmlkn].siz * mlk[curmlkn].pri,
                lftmlk -= mlk[curmlkn].siz;
            else
                cur += lftmlk * mlk[curmlkn].pri,
                mlk[curmlkn].siz -= lftmlk,
                lftmlk = 0,
                --curmlkn;
        }
        while(curs > sel){
            if(curs <= R)cur -= buy[curs];
            --curs;
        }
        mx = max(mx, cur);
        // printf("sel:%lld, unsel:%lld, cur=%lld\n", sel, unsel, cur);
        --sel, ++unsel;
    }while(unsel <= N || sel >= 0);
    printf("%lld\n", mx);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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
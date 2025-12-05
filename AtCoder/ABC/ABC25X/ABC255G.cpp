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

int N, M;
ll A[210000];
ll oplus(0);
map < ll, basic_string < ll > > rest;
map < ll, ll > SG, repeat;

ll CalSG(ll x){
    auto sp = *prev(SG.upper_bound(x));
    return sp.second + (x - sp.first);
}

int main(){
    N = read(), M = read(); SG.insert({0, 0});
    for(int i = 1; i <= N; ++i)A[i] = read < ll >();
    for(int i = 1; i <= M; ++i){
        ll p = read < ll >(), v = read < ll >();
        rest[p] += p - v;
    }
    ll preMx(-1);
    for(auto &mp : rest){
        preMx = max(preMx, CalSG(mp.first - 1));
        map < ll, ll > tmp;
        for(auto val : mp.second)tmp[CalSG(val)]++;
        for(auto cur : tmp){
            if(cur.second >= repeat[cur.first] + 1){
                repeat[cur.first]++;
                SG[mp.first] = cur.first;
                break;
            }
        }preMx = max(preMx, CalSG(mp.first));
        SG[mp.first + 1] = preMx + 1;
    }
    for(int i = 1; i <= N; ++i)oplus ^= CalSG(A[i]);
    printf("%s\n", oplus ? "Takahashi" : "Aoki");
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
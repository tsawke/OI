#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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
int P[210000];
ll d[210000];
ll ans(LONG_LONG_MAX);

int main(){
    N = read();
    for(int i = 0; i <= N - 1; ++i)P[i] = read();
    for(int i = 0; i <= N - 1; ++i)d[0] += min((i - P[i] + N) % N, (P[i] - i + N) % N);
    d[1] = -d[0];
    for(int i = 0; i <= N - 1; ++i)
        if((P[i] - i + N) % N <= (i - P[i] + N) % N){
            int dis = (P[i] - i + N) % N;
            d[1]--, d[dis + 1]++;
            d[dis + 1]++, d[dis + (N >> 1) + 1]--;
            d[dis + (N >> 1) + 1 + (N & 1 ? 1 : 0)]--;
        }else{
            int dis = (i - P[i] + N) % N;
            d[1]++, d[(N >> 1) - dis + 1]--;
            d[(N >> 1) - dis + 1 + (N & 1 ? 1 : 0)]--;
            d[N - dis + 1]++, d[N - dis + 1]++;
        }
    for(int i = 1; i <= N - 1; ++i)d[i] = d[i - 1] + d[i];
    for(int i = 1; i <= N - 1; ++i)d[i] = d[i - 1] + d[i];
    for(int i = 0; i <= N - 1; ++i)ans = min(ans, d[i]);
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
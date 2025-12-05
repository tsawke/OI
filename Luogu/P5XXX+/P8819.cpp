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



template< typename T = int >
inline T read(void);

int N, M, Q;
int val[510000];
ll sum[510000];
ll origin[510000];
ll sumall(0);
ll stdall(0);
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[510000];
ROPNEW(ed);
Edge* head[510000];

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)val[i] = rndd(1, INT_MAX), stdall += val[i];
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        // sum[s] += val[t];
        sum[t] += val[s];
        origin[t] += val[s];
        sumall += val[s];
    }Q = read();
    while(Q--){
        int opt = read();
        switch(opt){
            case 1:{
                int s = read(), t = read();
                sum[t] -= val[s];
                sumall -= val[s];
                // sum[s] -= val[t];
                // sumall -= val[t];
                break;
            }
            case 2:{
                int p = read();
                sumall -= sum[p];
                sum[p] = 0;
                break;
            }
            case 3:{
                int s = read(), t = read();
                sum[t] += val[s];
                sumall += val[s];
                break;
            }
            case 4:{
                int p = read();
                sumall += origin[p] - sum[p];
                sum[p] = origin[p];
                break;
            }
        }
        printf("%s\n", sumall == stdall ? "YES" : "NO");
    }

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
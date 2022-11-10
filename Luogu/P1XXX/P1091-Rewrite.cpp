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

int N;
int a[110];
int dp1[110], dp2[110];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    for(int i = 1; i <= N; ++i){
        dp1[i] = 1;
        for(int j = 1; j < i; ++j)if(a[j] < a[i])dp1[i] = max(dp1[i], dp1[j] + 1);
    }
    for(int i = N; i >= 1; --i){
        dp2[2] = 1;
        for(int j = N; j > i; --j)if(a[j] < a[i])dp2[i] = max(dp2[i], dp2[j] + 1);
    }
    int mn(INT_MAX);
    for(int i = 1; i <= N; ++i)mn = min(mn, N - dp1[i] - dp2[i]);
    printf("%d\n", mn);
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
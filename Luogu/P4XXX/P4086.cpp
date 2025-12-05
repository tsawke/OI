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

#define EPS (double)(1e-8)

template< typename T = int >
inline T read(void);

int N;
int a[110000];
int sum[110000];
int smin[110000];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    smin[N + 1] = INT_MAX;
    for(int i = N; i >= 1; --i)
        sum[i] = sum[i + 1] + a[i], smin[i] = min(smin[i + 1], a[i]);
    double mx(-1.0);
    vector < int > mxk;
    for(int k = 1; k <= N - 2; ++k){
        double val = double(sum[k + 1] - smin[k + 1]) / double(N - k - 1);
        if(abs(val - mx) <= EPS)mxk.emplace_back(k);
        else if(val > mx){mx = val, mxk.clear(), mxk.emplace_back(k);}
    }for(auto K : mxk)printf("%d\n", K);
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
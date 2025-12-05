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
int a[110000];
vector < int > data;
int tim[110000];
int cnt[110000];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)data.emplace_back(a[i] = read());
    sort(data.begin(), data.end()); //data.erase(unique(data.begin(), data.end()), data.end());
    for(int i = 1; i <= N; ++i)a[i] = distance(data.begin(), lower_bound(data.begin(), data.end(), a[i]) + 1), a[i] += cnt[a[i]]++;
    int lst(N);
    for(int i = N; i >= 1; --i){
        while(a[lst] > i)--lst;
        tim[i] = max(lst - i, 1);
    }ll ans(0);
    for(int i = 1; i <= N; ++i)ans += max(tim[i - 1], tim[i]);
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
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
#define MOD (int)(1e8 - 3)

template<typename T = int>
inline T read(void);

class TreeArray{
    private:
        int lim;
        int t[1100000];
    public:
        void init(int lim){this->lim = lim;}
        int lowbit(int x){return x & -x;}
        void add(int x, int v = 1){while(x <= lim)t[x] += v, x += lowbit(x);}
        int query(int x){int ret(0); while(x)ret += t[x], x -= lowbit(x); return ret;}
}t;
int N;
int A[110000], B[110000];
int pos[110000];
int ans(0);
vector < int > p;

signed main(){
    N = read(); t.init(N);
    for(int i = 1; i <= N; ++i)A[i] = read();
    for(int i = 1; i <= N; ++i)B[i] = read(), pos[B[i]] = i;
    for(int i = 1; i <= N; ++i)p.push_back(pos[A[i]]);
    for(auto i : p)ans += t.query(N) - t.query(i - 1), t.add(i);
    printf("%lld\n", ans % MOD);
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
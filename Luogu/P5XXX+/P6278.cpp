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

int N;
// struct Node{int idx, val;} a[110000];
int a[110000];
int d[110000];

class BIT{
private:
    int tr[110000];
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x, int v = 1){while(x <= N)tr[x] += v, x += lowbit(x);}
    int Query(int x){int ret(0); while(x)ret += tr[x], x -= lowbit(x); return ret;}
}bit;

signed main(){
    N = read();
    for(int i = 1; i <= N; ++i)a[i] = read() + 1;//Node{N - i + 1, read()};
    for(int i = 1; i <= N; ++i){
        d[a[i]] += bit.Query(N - a[i] + 1 + 1 - 1);
        bit.Modify(N - a[i] + 1 + 1);
    }
    // sort(a + 1, a + N + 1, [](const Node &a, const Node &b)->bool{return a.val < b.val;});
    // for(int i = 1; i <= N; ++i){
    //     d[a[i].val] += bit.Query(a[i].idx);
    //     bit.Modify(a[i].idx);
    // }
    for(int i = 0; i <= N - 1; ++i)d[i] += i ? d[i - 1] : 0, printf("%lld\n", d[i]);
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
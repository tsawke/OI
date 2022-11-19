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
pair < int, int > a[110000];

class BIT{
private:
    int tr[110000];
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x, int v = 1){while(x <= N)tr[x] += v, x += lowbit(x);}
    int Query(int x){int ret(0); while(x)ret += tr[x], x -= lowbit(x); return ret;}
}bit;

int main(){
    N = read();
    int ans(1);
    for(int i = 1; i <= N; ++i)a[i] = {read(), i};
    sort(a + 1, a + N + 1);
    for(int i = 1; i <= N; ++i)
        bit.Modify(a[i].second),
        ans = max(ans, i - bit.Query(i));
    printf("%d\n", ans);

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
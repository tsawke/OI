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
string A, B;
int c2d(char c){return int(c) - int('A') + 1;}
vector < int > head[30];
int tp[30];
int ans(0);
vector < int > p;

signed main(){
    memset(tp, -1, sizeof(tp));
    N = read(); t.init(N);
    cin >> A >> B;
    #define IDX(arr) c2d(arr.at(i - 1))
    for(int i = 1; i <= (int)A.length(); ++i)head[IDX(A)].emplace_back(i);
    for(int i = 1; i <= (int)B.length(); ++i)p.emplace_back(head[IDX(B)].at(++tp[IDX(B)]));
    for(auto i : p)ans += t.query(N) - t.query(i - 1), t.add(i);
    printf("%lld\n", ans);
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
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



template<typename T = int>
inline T read(void);

class TreeArray{
private:
    int lim;
    int tr[11000000];
public:
    void set(int lim){this->lim = lim;}
    int lowbit(int x){return x & -x;}
    void add(int x, int v = 1){while(x <= lim)tr[x] += v, x += lowbit(x);}
    int query(int x){int ret(0); while(x)ret += tr[x], x -= lowbit(x); return ret;}
}tr;

int N, M;
struct Coord{
    int x, y;
    int idx;
    int flag;
    friend const bool operator < (const Coord &x, const Coord &y){
        return x.x < y.x;
    }
};
vector < Coord > tre, qre;
int ans[510000];

int main(){tr.set(10100000);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i){
        int x = read() + 1, y = read() + 1;
        tre.emplace_back(Coord{x, y});
    }
    for(int i = 1; i <= M; ++i){
        int a = read() + 1, b = read() + 1, c = read() + 1, d = read() + 1;
        qre.emplace_back(Coord{c, d, i, 1});
        qre.emplace_back(Coord{a - 1, b - 1, i, 1});
        qre.emplace_back(Coord{a - 1, d, i, -1});
        qre.emplace_back(Coord{c, b - 1, i, -1});
    }sort(tre.begin(), tre.end()), sort(qre.begin(), qre.end());
    // printf("test\n");
    // qre.erase(unique(qre.begin(), qre.end()), qre.end());
    auto it = tre.begin();
    for(auto q : qre){
        while(it != tre.end() && it->x <= q.x)tr.add(it->y), ++it;
        ans[q.idx] += q.flag * tr.query(q.y);
    }
    for(int i = 1; i <= M; ++i)printf("%d\n", ans[i]);


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
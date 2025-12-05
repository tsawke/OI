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

// struct List{
//     List *pre, *nxt;
//     int dep;
// };
// List* lst[110000];
struct List{
    int pre, nxt;
    int dep;
}lst[110000];
int N, B;
struct Snow{
    int idx, dep;
    friend const bool operator < (const Snow &a, const Snow &b){return a.dep > b.dep;}
}snow[110000];
struct Boot{
    int idx, dis, dep;
    friend const bool operator < (const Boot &a, const Boot &b){return a.dep > b.dep;}
}boot[110000];
bool ans[110000];

int main(){
    N = read(), B = read();
    for(int i = 1; i <= N; ++i){
        // lst[i]->dep = read();
        // if(i != 1)lst[i]->pre = lst[i - 1];
        // if(i != N)lst[i]->nxt = lst[i + 1];
        snow[i] = Snow{i, read()};
        lst[i] = List{i - 1, i + 1, snow[i].dep};
    }
    for(int i = 1; i <= B; ++i){int s = read(), d = read(); boot[i] = Boot{i, d, s};}
    sort(snow + 1, snow + N + 1), sort(boot + 1, boot + B + 1);
    int cur(0), mx(0);
    for(int i = 1; i <= B; ++i){
        while(cur <= N - 1 && snow[cur + 1].dep > boot[i].dep){
            ++cur;
            lst[lst[snow[cur].idx].nxt].pre = lst[snow[cur].idx].pre;
            lst[lst[snow[cur].idx].pre].nxt = lst[snow[cur].idx].nxt;
            mx = max(mx, lst[snow[cur].idx].nxt - lst[snow[cur].idx].pre);
        }if(mx <= boot[i].dis)ans[boot[i].idx] = true;
    }
    for(int i = 1; i <= B; ++i)printf("%d\n", ans[i] ? 1 : 0);
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
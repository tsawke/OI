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

int N, M1, M2, lim;
int S, T;
vector < pair < int, int > > jg1;
vector < tuple < int, int, int > > jg2;
vector < int > pos;
int dis[1 << 16];
int cnt[1 << 16];

bool Check(int st){
    cout << "Checking:  " << bitset < 16 > (st) << endl;
    for(auto jg : jg1){
        int a, b; tie(a, b) = jg;
        if((st & (1 << a)) != (st & (1 << b)))return false;
    }
    for(auto jg : jg2){
        int a, b, c; tie(a, b, c) = jg;
        if((st & (1 << a)) != (st & (1 << c)) && (st & (1 << b)) != (st & (1 << a)))return false;
    }return true;
}
void bfs(void){
    queue < int > q;
    q.push(S); dis[S] = 1; cnt[S] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        // if(dis[T] && dis[T] <= dis[cur])continue;
        for(auto p : pos){
            if(__builtin_popcount(cur ^ p) > lim)continue;
            if(dis[p] == dis[cur] + 1){cnt[p] += cnt[cur]; continue;}
            // if(dis[p] < dis[cur] + 1)continue;
            // if(dis[p])continue;
            dis[p] = dis[cur] + 1, cnt[p] = cnt[cur], q.push(p);
        }
    }
}

int main(){
    N = read(), M1 = read(), M2 = read(), lim = read();
    S = 0, T = (1 << N) - 1;
    for(int i = 1; i <= M1; ++i){
        int a = read() - 1, b = read() - 1;
        printf("JG1 %d %d\n", a, b);
        jg1.emplace_back(a, b);
    }
    for(int i = 1; i <= M2; ++i){
        int a = read() - 1, b = read() - 1, c = read() - 1;
        printf("JG2 %d %d %d\n", a, b, c);
        jg2.emplace_back(a, b, c);
    }
    for(int st = S; st <= T; ++st)if(Check(st))pos.emplace_back(st);
    for(auto p : pos)cout << bitset < 16 > (p) << endl;
    bfs();
    if(!dis[T])printf("-1 0\n"), exit(0);
    printf("%d %d\n", dis[T] - 1, cnt[T]);
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
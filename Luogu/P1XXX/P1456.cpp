#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template < typename T = int >
inline T read(void);

bool flag(true);

int N, M;
// bitset < 110000 > killed;
// unordered_map < int, int > rmp;
__gnu_pbds::priority_queue < int, less < int >, pairing_heap_tag > sol[1100000];

class UnionFind{
private:
    int fa[110000];
public:
    UnionFind(void){for(int i = 1; i <= 101000; ++i)fa[i] = i;}
    void Clear(void){for(int i = 1; i <= N; ++i)fa[i] = i;}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int s, int t){if(Find(s) != Find(t))fa[Find(s)] = Find(t);}
}uf;

char __getchar(void){
    char c = getchar();
    if(c == EOF)flag = false;
    return c;
}

int main(){
    while(~scanf("%d", &N)){
        // N = read();
        uf.Clear();
        for(int i = 1; i <= N; ++i){
            sol[i].clear();
            int val = read();
            sol[i].push(val);
            // rmp[val] = i;
        }M = read();
        while(M--){
            // char c = __getchar(); while(!isalpha(c))c = __getchar();
            // if(c == 'M'){
                int x = read(), y = read();
                if(uf.Find(x) == uf.Find(y)){printf("-1\n"); continue;}
                int vx = sol[uf.Find(x)].top(), vy = sol[uf.Find(y)].top();
                sol[uf.Find(x)].pop(), sol[uf.Find(y)].pop();
                sol[uf.Find(x)].push(vx >> 1), sol[uf.Find(y)].push(vy >> 1);
                sol[uf.Find(x)].join(sol[uf.Find(y)]);
                uf.Union(uf.Find(y), uf.Find(x));
                printf("%d\n", sol[uf.Find(x)].top());
            // }else{
            //     int p = read();
            //     if(killed[p]){printf("0\n"); continue;}
            //     killed[rmp[sol[uf.Find(p)].top()]] = true;
            //     printf("%d\n", sol[uf.Find(p)].top());
            //     sol[uf.Find(p)].pop();
            // }
        }
    }
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
    char c = __getchar();
    if(c == EOF)exit(0);
    while(c != '-' && !isdigit(c))c = __getchar();
    if(c == '-')flag = -1, c = __getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = __getchar();
    }
    ret *= flag;
    return ret;
}
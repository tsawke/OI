#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    void* operator new(size_t);
    Edge(Edge* nxt, int to):nxt(nxt), to(to){;}
    Edge(void) = default;
}eData[1010000];
void* Edge::operator new(size_t){static Edge* P = eData; return P++;}
Edge* head[510000];

int N, Q;
int deg[510000];

vector < tuple < int, int, int > > q;

namespace chain{
    
}



int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    N = read(), Q = read();
    for(int i = 1; i <= N - 1; ++i){
        int f = read(), t = read();
        head[f] = new Edge(head[f], t);
        head[t] = new Edge(head[t], f);
        deg[f]++, deg[t]++;
    }
    while(Q--){
        int a = read(), b = read(), c = read();
        q.push_back({a, b, c});
        
    }
    // }[i] == 1)++c
    // int cnt1, cnt2;
    // for(int i = 1; i <= N; ++i){
    //     if(degnt1;
    //     if(deg[i] == 2)++cnt2;
    // }
    // if(cnt1 == 2 && cnt2 == N - 2){
        
    // }

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
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define EPS (1e-12)

template<typename T = int>
inline T read(void);

class Test{
public:
    int c;
    long double p;
    long double val;
    int idx;
    int ind = 0;
}t[1100000];

struct Edge{
    Edge* nxt;
    int to;
    void* operator new(size_t);
}ed[1100000];
void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
Edge* head[1100000];

int main(){
    int N = read();
    for(int i = 1; i <= N; ++i){
        t[i].idx = i;
        t[i].c = read();
        double p; cin >> p;
        t[i].p = (long double)p;
        // scanf("%lf", &t[i].p);
        t[i].val = (long double)t[i].c / (1.0 - t[i].p);
        int d = read();
        if(d)
            head[d] = new Edge{head[d], i},
            ++t[i].ind;
            // t[d].val *= (1.0 - t[i].p);
            // t[d].val -= rndd(100, 200);
    }
    auto cmp = [&](Test a, Test b)->bool{
        if(fabs(a.val - b.val) < EPS)return a.idx > b.idx;
        return a.val > b.val;
    };
    priority_queue <Test, vector < Test >, decltype(cmp)> cur(cmp);
    for(int i = 1; i <= N; ++i)
        if(!t[i].ind)cur.push(t[i]);
    while(!cur.empty()){
        auto tp = cur.top(); cur.pop();
        printf("%d\n", tp.idx);
        for(auto p = head[tp.idx]; p; p = p->nxt)
            if(!--t[p->to].ind)cur.push(t[p->to]);
    }
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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
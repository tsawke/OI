#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template < typename T = int >
inline T read(void);

int N, M;
int A[1100000];
int lst[1100000];
int ans[1100000];

class BIT{
private:
    int tr[1100000];
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x, int v){while(x <= N)tr[x] += v, x += lowbit(x);}
    int Query(int x){int ret(0); while(x)ret += tr[x], x -= lowbit(x); return ret;}
}bit;

struct Query{int l, idx;};
basic_string < Query > r[1100000];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    M = read();
    for(int i = 1; i <= M; ++i){
        int l = read();
        r[read()] += Query{l, i};
    }
    for(int i = 1; i <= N; ++i){
        if(lst[A[i]])bit.Modify(lst[A[i]], -1);
        bit.Modify(i, 1), lst[A[i]] = i;
        for(auto q : r[i])ans[q.idx] = bit.Query(i) - bit.Query(q.l - 1);
    }
    for(int i = 1; i <= M; ++i)printf("%d\n", ans[i]);
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
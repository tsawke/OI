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

#define LIM (31)

template < typename T = int >
inline T read(void);

class Trie{
private:
    struct Node{Node* son[2];};
    Node* root;
public:
    Trie(void){root = new Node{{npt, npt}};}
    void Insert(int val){
        auto cur = root;
        for(int i = LIM; i >= 0; --i){
            bool bit = val & (1 << i);
            if(!cur->son[bit])cur->son[bit] = new Node{{npt, npt}};
            cur = cur->son[bit];
        }
    }
    int QueryMax(int val){
        auto cur = root; int ans(0);
        for(int i = LIM; i >= 0; --i){
            bool bit = val & (1 << i);
            ans |= (((bool)cur->son[bit ^ 1] ^ bit) << i);
            cur = cur->son[bit ^ 1] ? cur->son[bit ^ 1] : cur->son[bit];
        }return ans ^ val;
    }
}trie;

int N;
int ans(0);
basic_string < int > vals;

struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[210000];
ROPNEW;
Edge* head[110000];

void dfs(int p = 1, int fa = 0, int cur = 0){
    trie.Insert(cur), vals += cur;
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs(SON, p, cur ^ i->val);
}

int main(){
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v};
        head[t] = new Edge{head[t], s, v};
    }dfs();
    for(auto v : vals)ans = max(ans, trie.QueryMax(v));
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
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; P->idx = P - nd + 1; printf("idxxx  %d\n", P->idx);nod[P->idx] = P; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define d(c) (c - 'a')

template < typename T = int >
inline T read(void);

struct Node{
    Node* son[26];
    Node* fa;
    int len;
    int idx;
    int siz;
    OPNEW;
}nd[2100000];
Node* nod[2100000];
ROPNEW_NODE;
Node* root;

void Insert(int c){
    static Node* lst = root;
    Node* p = lst; Node* cp = lst = new Node;
    printf("lst idx = %d\n", lst->idx);
    cp->len = p->len + 1;
    while(p && !p->son[c])p->son[c] = cp, p = p->fa;
    if(!p)cp->fa = root;
    else if(p->son[c]->len == p->len + 1)cp->fa = p->son[c];
    else{
        auto q = p->son[c], sq = new Node(*q);
        sq->len = p->len + 1;
        cp->fa = q->fa = sq;
        while(p && p->son[c] == q)p->son[c] = sq, p = p->fa;
    }
}

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[4100000];
ROPNEW;
Edge* head[2100000];

ll ans(0);

void Link(Node* p = root){
    if(p->fa)
        head[p->idx] = new Edge{head[p->idx], p->fa->idx},
        head[p->fa->idx] = new Edge{head[p->fa->idx], p->idx},
        printf("Connect %d ~ %d\n", p->idx, p->fa->idx);
    for(int i = 0; i < 26; ++i)if(p->son[i])Link(p->son[i]);
}
void dfs(int p = 1, int fa = 0){
    nod[p]->siz = 1;
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs(SON, p), nod[p]->siz += nod[SON]->siz;
    printf("In dfs p = %d, siz = %d, len = %d\n", p, nod[p]->siz, nod[p]->len);
    ans = max(ans, (ll)nod[p]->siz * nod[p]->len);
}

string S;

int main(){
    root = new Node();
    cin >> S;
    for(auto c : S)Insert(d(c));
    Link(), dfs();
    for(int i = 1; i <= 5; ++i)printf("idx[%d] = %d\n", i, nd[i].idx);
    for(int i = 1; i <= 5; ++i)printf("idx[%d] = %d\n", i, nod[i]->idx);
    printf("%lld\n", ans);
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
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

#define d(c) (c - 'a')

template < typename T = int >
inline T read(void);

struct Edge;
struct Node{
    unordered_map < int, Node* > trans;
    Node* link;
    int len;
    int idx;
    bool flag;
    Edge* head;
    int val;
    OPNEW;
}nd[2100000];
ROPNEW_NODE;
Node* root;

struct Edge{
    Edge* nxt;
    Node* to;
    int val;
    OPNEW;
}ed[4100000];
ROPNEW;

int N;
string S, T;
string base;
basic_string < bool > sorted;
basic_string < int > ret;

void Insert(int c, int idx){
    static Node* lst = root;
    Node* p = lst; Node* cp = lst = new Node; cp->idx = idx; cp->flag = true;
    cp->len = p->len + 1;
    while(p && !p->trans[c])p->trans[c] = cp, p = p->link;
    if(!p)cp->link = root;
    else if(p->trans[c]->len == p->len + 1)cp->link = p->trans[c];
    else{
        auto q = p->trans[c], sq = new Node(*q); sq->idx = idx; sq->flag = false;
        sq->len = p->len + 1;
        cp->link = q->link = sq;
        while(p && p->trans[c] == q)p->trans[c] = sq, p = p->link;
    }
}
void Link(void){
    auto endp = new Node();
    for(auto p = nd; p != endp;++p)
        if(p->link)
            p->link->head = new Edge{p->link->head, p, base.at(p->idx + p->link->len)};
}
void dfs_subt(Node* p){
    if(p->flag && ((1 <= p->idx && p->idx <= N) || (N * 2 + 1 <= p->idx && p->idx <= N * 3)))ret += p->idx;
    for(auto i = p->head; i; i = i->nxt)dfs_subt(SON);
}
void dfs(Node* p = root){
    if(N <= p->len){
        ret.clear();
        dfs_subt(p);
        int cnt1(0);
        for(auto pos : ret)
            if(N * 2 + 1 <= pos && pos <= N * 3)++cnt1;
            else if(1 <= pos && pos <= N)sorted += false;
        while(cnt1--)sorted += true;
        return;
    }
    basic_string < Edge* > sons;
    for(auto i = p->head; i; i = i->nxt)sons += i;
    sort(sons.begin(), sons.end(), [](Edge* a, Edge* b)->bool{return a->val < b->val;});
    for(auto son : sons)dfs(son->to);
}

int main(){
    // freopen("in.txt", "r", stdin);
    root = new Node(); root->idx = -1; root->len = 0;
    N = read();
    cin >> S >> T;
    base = '#' + S + S + T + T;
    for(int i = N * 4; i >= 1; --i)Insert(d(base.at(i)), i);
    Link(), dfs();
    ll ans(0), sumS(0);
    for(auto v : sorted)if(v)ans += sumS; else ++sumS;
    printf("%lld\n", ans);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int idx(1);
    char c = getchar();
    while(c != '-' && !isdigit(c))c = getchar();
    if(c == '-')idx = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= idx;
    return ret;
}
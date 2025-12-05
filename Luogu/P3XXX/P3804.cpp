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
    unordered_map < char, Node* > trans;
    Node* link;
    int len;
    int siz;
    Edge* head;
    OPNEW;
}nd[2100000];
ROPNEW_NODE;
Node* root;

struct Edge{
    Edge* nxt;
    Node* to;
    OPNEW;
}ed[4100000];
ROPNEW;

void Insert(int c){
    static Node* lst = root;
    Node* p = lst; Node* cp = lst = new Node; cp->siz = 1;
    cp->len = p->len + 1;
    while(p && !p->trans[c])p->trans[c] = cp, p = p->link;
    if(!p)cp->link = root;
    else if(p->trans[c]->len == p->len + 1)cp->link = p->trans[c];
    else{
        auto q = p->trans[c], sq = new Node(*q); sq->siz = 0;
        sq->len = p->len + 1;
        cp->link = q->link = sq;
        while(p && p->trans[c] == q)p->trans[c] = sq, p = p->link;
    }
}

ll ans(0);

void Link(void){
    auto endp = new Node();
    for(auto p = nd; p != endp;++p)
        if(p->link)
            p->head = new Edge{p->head, p->link},
            p->link->head = new Edge{p->link->head, p};
}
void DFS(Node* p = root, Node* fa = npt){
    for(auto i = p->head; i; i = i->nxt)
        if(SON != fa)DFS(SON, p), p->siz += SON->siz;
    if(p->siz > 1)ans = max(ans, (ll)p->siz * p->len);
}

string S;

int main(){
    root = new Node();
    cin >> S;
    for(auto c : S)Insert(d(c));
    Link(), DFS();
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
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define siz(p) (p ? p->siz : 0)
#define son(p, dir) (dir ? p->rson : p->lson)

template < typename T = int >
inline T read(void);

struct Node{
    Node* lson;
    Node* rson;
    int val;
    int pri;
    int cnt, siz;
    bool lz;
};
Node* root;
int N, M;

void Pushup(Node* p){if(p)p->siz = p->cnt + siz(p->lson) + siz(p->rson);}
void Pushdown(Node* p){
    if(!p || !p->lz)return;
    p->lz = false;
    if(p->lson){
        p->lson->lz ^= true;
        swap(p->lson->lson, p->lson->rson);
    }
    if(p->rson){
        p->rson->lz ^= true;
        swap(p->rson->lson, p->rson->rson);
    }
}
pair < Node*, Node* > Split(Node* p, int rnk){
    if(!p)return {npt, npt};
    Pushdown(p);
    if(siz(p->lson) + p->cnt <= rnk){
        auto spl = Split(p->rson, rnk - siz(p->lson) - p->cnt);
        p->rson = spl.first;
        Pushup(p);
        return {p, spl.second};
    }else{
        auto spl = Split(p->lson, rnk);
        p->lson = spl.second;
        Pushup(p);
        return {spl.first, p};
    }
}
Node* Merge(Node* l, Node* r){
    if(!l || !r)return l ? l : r;
    Pushdown(l), Pushdown(r);
    if(l->pri < r->pri){
        l->rson = Merge(l->rson, r);
        Pushup(l);
        return l;
    }else{
        r->lson = Merge(l, r->lson);
        Pushup(r);
        return r;
    }
}
void Insert(int val){
    auto spl = Split(root, val);
    auto spll = Split(spl.first, val - 1/*cnt is 1*/);
    if(!spll.second)spll.second = new Node{npt, npt, val, rndd(1, 0x3f3f3f3f), 1, 1, false};
    else ++spll.second->cnt, ++spll.second->siz;
    root = Merge(Merge(spll.first, spll.second), spl.second);
}
void Reverse(int l, int r){
    auto spl = Split(root, r);
    auto spll = Split(spl.first, l - 1);
    swap(spll.second->lson, spll.second->rson);
    spll.second->lz ^= true;
    root = Merge(Merge(spll.first, spll.second), spl.second);
}
void PrintNode(Node* p){
    Pushdown(p);
    if(p->lson)PrintNode(p->lson);
    printf("%d ", p->val);
    if(p->rson)PrintNode(p->rson);
}
void Print(int l, int r){
    auto spl = Split(root, r);
    auto spll = Split(spl.first, l - 1);
    PrintNode(spll.second);
    root = Merge(Merge(spll.first, spll.second), spl.second);
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)Insert(i);
    while(M--){int l = read(), r = read(); Reverse(l, r);}
    Print(1, N);
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
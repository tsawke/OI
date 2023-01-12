#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define siz(p) (p ? p->siz : 0)
#define sum(p) (p ? p->sum : 0)

template < typename T = int >
inline T read(void);

struct Node{
    Node* lson;
    Node* rson;
    int val;
    int rval;
    int pri;
    int siz;
    ll sum;
    bool lz;
    OPNEW;
}nd[210000 * 100];
ROPNEW;
Node* root[210000];

class Treap{
private:
public:
    void Pushup(Node* p){
        p->siz = siz(p->lson) + siz(p->rson);
        p->sum = sum(p->lson) + sum(p->rson);
    }
    void Pushdown(Node* p){
        if(!p || !p->lz)return;
        p->lz = false;
        swap(p->lson, p->rson);
        if(p->lson){
            Node* cur = new Node(*p);
            cur->lson->lz ^= 1;
            p->lson = cur->lson;
        }
        if(p->rson){
            Node* cur = new Node(*p);
            cur->rson->lz ^= 1;
            p->rson = cur->rson;
        }
    }
    pair < Node*, Node* > Split(Node* p, int rnk){
        if(!p)return {npt, npt};
        if(rnk > siz(p->lson) + 1){
            Node* cur = new Node(*p);
            auto spl = Split(p->rson, rnk - siz(p->lson) + 1);
            cur->rson = spl.first;
            return {cur, spl.second};
        }else{
            Node* cur = new Node(*p);
            auto spl = Split(p->lson, rnk);
            cur->lson = spl.second;
            return {cur, spl.first};
        }
    }
}

int main(){


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
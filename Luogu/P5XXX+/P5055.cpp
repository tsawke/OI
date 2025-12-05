#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(114514);
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
    int pri;
    int siz;
    ll sum;
    bool lz;
    OPNEW;
}nd[210000 * 100];
ROPNEW;
Node* root[210000];
ll lst(0);

class Treap{
private:
public:
    void Pushup(Node* p){
        p->siz = siz(p->lson) + siz(p->rson) + 1;
        p->sum = sum(p->lson) + sum(p->rson) + p->val;
    }
    void Pushdown(Node* p){
        if(!p || !p->lz)return;
        p->lz = false;
        if(p->lson){
            Node* cur = new Node(*p->lson);
            cur->lz ^= 1;
            p->lson = cur;
        }
        if(p->rson){
            Node* cur = new Node(*p->rson);
            cur->lz ^= 1;
            p->rson = cur;
        }
        swap(p->lson, p->rson);
    }
    pair < Node*, Node* > Split(Node* p, int rnk){
        if(!p)return {npt, npt};
        Pushdown(p);
        if(rnk >= siz(p->lson) + 1){
            Node* cur = new Node(*p);
            auto spl = Split(cur->rson, rnk - siz(cur->lson) - 1);
            cur->rson = spl.first;
            Pushup(cur);
            return {cur, spl.second};
        }else{
            Node* cur = new Node(*p);
            auto spl = Split(cur->lson, rnk);
            cur->lson = spl.second;
            Pushup(cur);
            return {spl.first, cur};
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
    void Insert(Node* p, int cnt, int val, int idx){
        auto spl = Split(p, cnt);
        root[idx] = Merge(Merge(spl.first, new Node{npt, npt, val, rndd(1, 0x3f3f3f3f), 1, val, false}), spl.second);
    }
    void Delete(Node* p, int cnt, int idx){
        auto spl = Split(p, cnt);
        auto spll = Split(spl.first, cnt - 1);
        root[idx] = Merge(spll.first, spl.second);
    }
    void Reverse(Node* p, int l, int r, int idx){
        auto spl = Split(p, r);
        auto spll = Split(spl.first, l - 1);
        spll.second->lz ^= true;
        root[idx] = Merge(Merge(spll.first, spll.second), spl.second);
    }
    ll Query(Node* p, int l, int r, int idx){
        auto spl = Split(p, r);
        auto spll = Split(spl.first, l - 1);
        ll ret = spll.second->sum;
        root[idx] = Merge(Merge(spll.first, spll.second), spl.second);
        return ret;
    }
}treap;

int main(){
    int N = read();
    for(int i = 1; i <= N; ++i){
        int ver = read(), opt = read();
        switch(opt){
            case 1:{int p = read() ^ lst, x = read() ^ lst; treap.Insert(root[ver], p, x, i); break;}
            case 2:{int p = read() ^ lst; treap.Delete(root[ver], p, i); break;}
            case 3:{int l = read() ^ lst, r = read() ^ lst; treap.Reverse(root[ver], l, r, i); break;}
            case 4:{
                int l = read() ^ lst, r = read() ^ lst;
                ll ret = treap.Query(root[ver], l, r, i);
                printf("%lld\n", lst = ret);
                break;
            }
            default: break;
        }
    }
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
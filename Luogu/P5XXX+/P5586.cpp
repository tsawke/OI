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

#define MOD (ll)(1e9 + 7)
#define siz(p) (p ? p->siz : 0)
#define sum(p) (p ? p->sum : 0)

template < typename T = int >
inline T read(void);

struct Node{
    Node* lson;
    Node* rson;
    ll val;
    ll siz;
    ll sum;
    ll lz_add;
    ll lz_assign;
    bool lz_rev;
    OPNEW;
}nd[4100000];
Node* P = nd;
void* Node::operator new(size_t){return P++;}
void Clear(void){memset(nd, 0, sizeof nd); P = nd;}

Node* root;
ll lst(0);
int N, M;
int cnt(0);
ll A[310000];

class Treap{
private:
    #define MID ((l + r) >> 1)
public:
    void Pushup(Node* p){
        p->siz = siz(p->lson) + siz(p->rson) + 1;
        p->sum = ((sum(p->lson) + sum(p->rson)) % MOD + p->val) % MOD;
    }
    void SetRev(Node* p){
        p->lz_rev ^= true;
        swap(p->lson, p->rson);
    }
    void SetAdd(Node* p, ll v){
        (p->lz_add += v) %= MOD;
        (p->val += v) %= MOD;
        (p->sum += p->siz * v % MOD) %= MOD;
    }
    void SetAssign(Node* p, ll v){
        p->lz_rev = false, p->lz_add = 0;
        p->lz_assign = v;
        p->sum = p->siz * v % MOD;
        p->val = v;
    }
    void ClearLz(Node* p){
        p->lz_rev = false, p->lz_add = 0, p->lz_assign = -1;
    }
    void Pushdown(Node* p){
        if(!p || (!p->lz_rev && !p->lz_add && !~p->lz_assign))return;
        if(p->lson){
            Node* cur = new Node(*p->lson);
            if(~p->lz_assign)SetAssign(cur, p->lz_assign);
            if(p->lz_rev)SetRev(cur);
            if(p->lz_add)SetAdd(cur, p->lz_add);
            p->lson = cur;
        }
        if(p->rson){
            Node* cur = new Node(*p->rson);
            if(~p->lz_assign)SetAssign(cur, p->lz_assign);
            if(p->lz_rev)SetRev(cur);
            if(p->lz_add)SetAdd(cur, p->lz_add);
            p->rson = cur;
        }
        ClearLz(p);
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
        if(rndd(1, 0x7f7f7f7f) % (l->siz + r->siz) < l->siz){
            Node* cur = new Node(*l);
            cur->rson = Merge(cur->rson, r);
            Pushup(cur);
            return cur;
        }else{
            Node* cur = new Node(*r);
            cur->lson = Merge(l, cur->lson);
            Pushup(cur);
            return cur;
        }
    }
    void Reverse(Node* p, int l, int r){
        auto spl = Split(p, r);
        auto spll = Split(spl.first, l - 1);
        Node* cur = new Node(*spll.second);
        SetRev(cur);
        root = Merge(Merge(spll.first, cur), spl.second);
    }
    void Assign(Node* p, int l, int r, ll v){
        auto spl = Split(p, r);
        auto spll = Split(spl.first, l - 1);
        Node* cur = new Node(*spll.second);
        SetAssign(cur, v);
        root = Merge(Merge(spll.first, cur), spl.second);
    }
    void Modify(Node* p, int l, int r, ll v){
        auto spl = Split(p, r);
        auto spll = Split(spl.first, l - 1);
        Node* cur = new Node(*spll.second);
        SetAdd(cur, v);
        root = Merge(Merge(spll.first, cur), spl.second);
    }
    void Swap(Node* p, int l1, int r1, int l2, int r2){
        if(l1 > l2)swap(l1, l2), swap(r1, r2);
        auto s1 = Split(p, r2), s2 = Split(s1.first, l2 - 1), s3 = Split(s2.first, r1), s4 = Split(s3.first, l1 - 1);
        root = Merge(Merge(Merge(Merge(s4.first, s2.second), s3.second), s4.second), s1.second);
    }
    void Copy(Node* p, int l1, int r1, int l2, int r2){
        bool dir(false);
        if(l1 > l2)swap(l1, l2), swap(r1, r2), dir = true;
        auto s1 = Split(p, r2), s2 = Split(s1.first, l2 - 1), s3 = Split(s2.first, r1), s4 = Split(s3.first, l1 - 1);
        dir ? s4.second = new Node(*s2.second) : s2.second = new Node(*s4.second);
        root = Merge(Merge(Merge(Merge(s4.first, s4.second), s3.second), s2.second), s1.second);
    }
    ll Query(Node* p, int l, int r){
        auto spl = Split(p, r);
        auto spll = Split(spl.first, l - 1);
        ll ret = spll.second->sum;
        root = Merge(Merge(spll.first, spll.second), spl.second);
        return ret;
    }
    Node* Build(int l, int r){
        if(l > r)return npt;
        Node* ret = new Node{Build(l, MID - 1), Build(MID + 1, r), A[(int)MID], 0, 0, 0, -1, 0};
        Pushup(ret);
        return ret;
    }
    void SetArray(Node* p){
        Pushdown(p);
        if(p->lson)SetArray(p->lson);
        A[++cnt] = p->val;
        if(p->rson)SetArray(p->rson);
    }
    void Print(Node* p = root){
        Pushdown(p);
        if(p->lson)Print(p->lson);
        printf("%lld ", p->val);
        if(p->rson)Print(p->rson);
        if(p == root)printf("\n");
    }
}treap;

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    root = treap.Build(1, N);
    for(int i = 1; i <= M; ++i){
        int opt = read();
        switch(opt){
            case 1:{int l = read() ^ lst, r = read() ^ lst; printf("%lld\n", lst = treap.Query(root, l, r)); break;}
            case 2:{int l = read() ^ lst, r = read() ^ lst, v = read() ^ lst; treap.Assign(root, l, r, v); break;}
            case 3:{int l = read() ^ lst, r = read() ^ lst, v = read() ^ lst;treap.Modify(root, l, r, v); break;}
            case 4:{int l1 = read() ^ lst, r1 = read() ^ lst, l2 = read() ^ lst, r2 = read() ^ lst; treap.Copy(root, l1, r1, l2, r2); break;}
            case 5:{int l1 = read() ^ lst, r1 = read() ^ lst, l2 = read() ^ lst, r2 = read() ^ lst; treap.Swap(root, l1, r1, l2, r2); break;}
            case 6:{int l = read() ^ lst, r = read() ^ lst; treap.Reverse(root, l, r); break;}
            default: break;
        }
        if(distance(nd, P) > 3500000){
            cnt = 0;
            treap.SetArray(root);
            Clear();
            root = treap.Build(1, N);
        }
    }treap.Print();
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
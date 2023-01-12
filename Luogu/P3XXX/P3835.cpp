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
#define son(p, dir) (dir ? p->rson : p->lson)

template < typename T = int >
inline T read(void);

struct Node{
    Node* lson;
    Node* rson;
    int val;
    int pri;
    int cnt, siz;
    OPNEW;
}nd[510000 * 100];
ROPNEW;
Node* root[510000];

class Treap{
private:
public:
    void Pushup(Node* p){
        p->siz = p->cnt + siz(p->lson) + siz(p->rson);
    }
    pair < Node*, Node* > Split(Node* p, int val){
        if(!p)return {npt, npt};
        if(p->val <= val){
            Node* cur = new Node(*p);
            auto spl = Split(cur->rson, val);
            cur->rson = spl.first;
            Pushup(cur);
            return {cur, spl.second};
        }else{
            Node* cur = new Node(*p);
            auto spl = Split(cur->lson, val);
            cur->lson = spl.second;
            Pushup(cur);
            return {spl.first, cur};
        }
    }
    Node* Merge(Node* l, Node* r){
        if(!l || !r)return l ? l : r;
        if(l->pri < r->pri){
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
    void Insert(Node* p, int val, int idx){
        auto spl = Split(p, val);
        auto spll = Split(spl.first, val - 1);
        if(!spll.second)spll.second = new Node{npt, npt, val, rndd(1, 0x3f3f3f3f), 1, 1};
        else ++spll.second->cnt, ++spll.second->siz;
        root[idx] = Merge(Merge(spll.first, spll.second), spl.second);
    }
    void Delete(Node* p, int val, int idx){
        auto spl = Split(p, val);
        auto spll = Split(spl.first, val - 1);
        if(spll.second){
            if(spll.second->cnt > 1)--spll.second->cnt, --spll.second->siz;
            else spll.second = npt;
        }root[idx] = Merge(Merge(spll.first, spll.second), spl.second);
    }
    int FindRankByVal(Node* p, int val, int idx){
        auto spl = Split(p, val - 1);
        int ret = siz(spl.first) + 1;
        root[idx] = Merge(spl.first, spl.second);
        return ret;
    }
    int FindValByRank(Node* p, int rnk, int idx){
        if(!p)return -1;
        if(siz(p->lson) + 1 <= rnk && rnk <= siz(p->lson) + p->cnt)return p->val;
        if(rnk <= siz(p->lson))return FindValByRank(p->lson, rnk, idx);
        else return FindValByRank(p->rson, rnk - siz(p->lson) - p->cnt, idx);
    }
    int FindPre(Node* p, int val, int idx){
        auto spl = Split(p, val - 1);
        int ret = FindValByRank(spl.first, siz(spl.first), idx);
        root[idx] = Merge(spl.first, spl.second);
        return ret;
    }
    int FindNxt(Node* p, int val, int idx){
        auto spl = Split(p, val);
        int ret = FindValByRank(spl.second, 1, idx);
        root[idx] = Merge(spl.first, spl.second);
        return ret;
    }
}treap;

int main(){
    treap.Insert(root[0], INT_MAX, 0), treap.Insert(root[0], -INT_MAX, 0);
    int N = read();
    for(int i = 1; i <= N; ++i){
        int ver = read(), opt = read(), v = read();
        switch(opt){
            case 1:{treap.Insert(root[ver], v, i); break;}
            case 2:{treap.Delete(root[ver], v, i); break;}
            case 3:{printf("%d\n", treap.FindRankByVal(root[ver], v, i) - 1); break;}
            case 4:{printf("%d\n", treap.FindValByRank(root[ver], v + 1, i)); root[i] = root[ver]; break;}
            case 5:{printf("%d\n", treap.FindPre(root[ver], v, i)); break;}
            case 6:{printf("%d\n", treap.FindNxt(root[ver], v, i)); break;}
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
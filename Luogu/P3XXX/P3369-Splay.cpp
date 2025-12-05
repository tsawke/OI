#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Node::operator new(size_t){static Node* P = arr; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define siz(p) (p ? p->siz : 0)
#define son(p, dir) ((dir) ? p->rson : p->lson)

template < typename T = int >
inline T read(void);

struct Node{
    Node* lson;
    Node* rson;
    Node* fa;
    int cnt;
    int siz;
    int val;
    OPNEW;
}nd[110000];
ROPNEW(nd);
Node* root;

void Update(Node* p){
    p->siz = p->cnt + siz(p->lson) + siz(p->rson);
}
bool GetDir(Node* p){
    return p->fa ? p->fa->rson == p : false;
}
void Link(Node* p, Node* fa, bool dir){
    if(fa)son(fa, dir) = p, Update(fa);
    if(p)p->fa = fa;
}
void Rotate(Node* p){
    auto fa = p->fa, gfa = fa->fa;
    auto dir1 = GetDir(p), dir2 = GetDir(fa);
    Link(son(p, !dir1), fa, dir1), Link(fa, p, !dir1), Link(p, gfa, dir2);
}
void Splay(Node* p){
    if(!p)return;
    while(p->fa != npt){
        if(p->fa->fa != npt)
            Rotate(GetDir(p) == GetDir(p->fa) ? p->fa : p);
        Rotate(p);
    }root = p;
}
void Insert(int val, Node* cur = root, Node* fa = npt){
    if(cur && val != cur->val)return Insert(val, val > cur->val ? cur->rson : cur->lson, cur);
    if(!cur){
        cur = new Node{npt, npt, fa, 1, 1, val};
        if(fa)son(fa, val > fa->val ? true : false) = cur;
    }else ++cur->cnt;
    Splay(cur);
}
Node* Find(int val, Node* cur = root, Node* fa = npt){
    if(!cur)return Splay(fa), fa;
    if(cur->val != val)return Find(val, val > cur->val ? cur->rson : cur->lson, cur);
    return Splay(cur), cur;
}
void Delete(int val){
    auto cur = Find(val);
    if(!cur)return;
    if(cur->cnt > 1)return --cur->cnt, --cur->siz, void();
    if(!cur->lson && !cur->rson)return root = npt, void();
    if(!cur->lson)return root = cur->rson, cur->rson->fa = npt, void();
    auto mxp = cur->lson;
    while(mxp->rson)mxp = mxp->rson;
    Splay(mxp);
    Link(cur->rson, root, true), Link(root, npt, true);
}
int FindRankByVal(int val, Node* cur = root, int tot = siz(root->lson)){
    if(!cur || cur->val == val)return Splay(cur), tot + 1;
    return FindRankByVal(
        val,
        val < cur->val ? cur->lson : cur->rson,
        val < cur->val ? tot - siz(cur->lson) + (cur->lson ? siz(cur->lson->lson) : 0) : tot + cur->cnt + (cur->rson ? siz(cur->rson->lson) : 0)
    );
}
int FindValByRank(int rnk, Node* cur = root, int tot = siz(root->lson)){
    if(!cur)return -1;
    if(tot + 1 <= rnk && rnk <= tot + cur->cnt)return Splay(cur), cur->val;
    return FindValByRank(
        rnk,
        rnk < tot + 1 ? cur->lson : cur->rson,
        rnk < tot + 1 ? tot - siz(cur->lson) + (cur->lson ? siz(cur->lson->lson) : 0) : tot + cur->cnt + (cur->rson ? siz(cur->rson->lson) : 0)
    );
}
int FindPre(int val){
    auto cur = Find(val);
    if(cur->val < val)return Splay(cur), cur->val;
    cur = cur->lson;
    while(cur->rson)cur = cur->rson;
    return Splay(cur), cur->val;
}
int FindNxt(int val){
    auto cur = Find(val);
    if(cur->val > val)return Splay(cur), cur->val;
    cur = cur->rson;
    while(cur->lson)cur = cur->lson;
    return Splay(cur), cur->val;
}

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int N = read();
    while(N--){
        int opt = read();
        switch(opt){
            case 1:{Insert(read()); break;}
            case 2:{Delete(read()); break;}
            case 3:{printf("%d\n", FindRankByVal(read())); break;}
            case 4:{printf("%d\n", FindValByRank(read())); break;}
            case 5:{printf("%d\n", FindPre(read())); break;}
            case 6:{printf("%d\n", FindNxt(read())); break;}
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
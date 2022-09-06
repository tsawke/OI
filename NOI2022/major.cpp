#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define LS(p) (p->ls ? p->ls->val : 0)
#define RS(p) (p->rs ? p->rs->val : 0)
#define S(p) (p ? p->val : 0)


#define MAXN 510000
#define MAXQ 510000
#define MAXNQ (MAXN + MAXQ)
#define NQ (N + Q)

/******************************
abbr
ST => SegTree
******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

int N, Q;

struct ST{
    ST *ls, *rs;
    int val;
    void* operator new(size_t);
    ST(ST* ls, ST* rs, int val):ls(ls), rs(rs), val(val){;}
    ST(void) = default;
}sData[MAXNQ << 6];
void* ST::operator new(size_t){static ST* sP = sData; return ++sP;}
void Pushup(ST* p){if(!p)return; p->val = LS(p) + RS(p);}
void Upd(ST* &p, int idx, int val, int l = 1, int r = NQ){
    if(!p)p = new ST;
    if(l == r){p->val += val; return;}
    int mid = (l + r) >> 1;
    if(idx <= mid)Upd(p->ls, idx, val, l, mid);
    else Upd(p->rs, idx, val, mid + 1, r);
    Pushup(p);
}
void Merge(ST* &x, ST* y){
    if(!y)return;
    if(!x){x = y; return;}
    else x->val += y->val;
    Merge(x->ls, y->ls);
    Merge(x->rs, y->rs);
}
int Find(ll cmp, vector < ST* > &tree, int l = 1, int r = NQ){

    // for(auto i : tree)printf("%d ", i ? i->val : -1);
    // printf("\n");

    if(l == r){
        ll val(0);
        for(auto i : tree)val += S(i);
        if(val > cmp)return l;
        else return -1;
    }
    ll lval(0), rval(0);
    for(auto i : tree)
        lval += i ? LS(i) : 0,
        rval += i ? RS(i) : 0;
    int mid = (l + r) >> 1;
    if(lval > cmp){
        for(auto &i : tree)i = (i ? i->ls : npt);
        return Find(cmp, tree, l, mid);
    }else if(rval > cmp){
        for(auto &i : tree)i = (i ? i->rs : npt);
        return Find(cmp, tree, mid + 1, r);
    }else
        return -1;
}

struct List{
    List* nxt;
    int val;
    void* operator new(size_t);
    List(List* nxt, int val):nxt(nxt), val(val){;}
    List(void) = default;
}lData[MAXNQ];
void* List::operator new(size_t){static List* lP = lData; return ++lP;}
List* tail[MAXNQ];
List* head[MAXNQ];

ST* root[MAXNQ];

template<typename T = int>
inline T read(void);

int main(){
    freopen("major17.in", "r", stdin);
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i){
        int len = read();
        for(int j = 1; j <= len; ++j){
            int val = read();
            Upd(root[i], val, 1);
            if(!tail[i])head[i] = new List(tail[i], val), tail[i] = head[i];
            else tail[i] = new List(tail[i], val);
        }
    }
    for(int q = 1; q <= Q; ++q){
        // for(int i = 1; i <= 10; ++i)printf("%d%c", i, i == 10 ? '\n' : ' ');

    

        int ask = read();
        switch(ask){
            case 1:{
                int x = read(), y = read();
                Upd(root[x], y, 1);
                tail[x] = new List(tail[x], y);
                break;
            }
            case 2:{
                int x = read();
                Upd(root[x], tail[x] ? tail[x]->val : 0, 1);
                tail[x] = tail[x] ? tail[x]->nxt : npt;
                break;
            }
            case 3:{
                int M = read();
                vector < ST* > tree;
                ll siz(0);
                while(M--){
                    tree.push_back(root[read()]);
                    siz += tree.back()->val;
                }
                printf("%d\n", Find(siz >> 1, tree));
                // tree.clear();
                break;
            }
            case 4:{
                int x1 = read(), x2 = read(), x3 = read();
                Merge(root[x1], root[x2]);
                head[x2]->nxt = tail[x1];
                head[x2] = head[x1];
                tail[x1] = tail[x2];
                root[x3] = root[x1];
                head[x3] = head[x1];
                tail[x3] = tail[x1];
            }
        }
    }


    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
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
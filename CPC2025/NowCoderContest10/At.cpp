#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define lsiz(p) (p->ls ? p->ls->siz : 0)
#define rsiz(p) (p->rs ? p->rs->siz : 0)
#define size(p) (p ? p->siz : 0)

using namespace std;

mt19937 _rnd(random_device{}());
int rnd(void){return (int)(_rnd() & 0x7fffffff);}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

struct Treap{
    Treap *ls, *rs;
    int val, pri;
    int siz, cnt;
    void* operator new(size_t);
    Treap(Treap* _ls, Treap* _rs, int _val, int _pri):ls(_ls), rs(_rs), val(_val), pri(_pri), siz(1), cnt(1){;}
    Treap(void) = default;
}tData[400000 + 5];
void* Treap::operator new(size_t){static Treap* P = tData; return ++P;}

template<typename T = int>
inline T read(void){
    T ret(0); short flag(1); int c = getchar();
    while(c!='-' && !isdigit(c)) c = getchar();
    if(c=='-') flag=-1, c=getchar();
    while(isdigit(c)){ ret = ret*10 + (c - '0'); c = getchar(); }
    ret = (T)(ret * flag); return ret;
}

Treap* root = npt;

inline void Pushup(Treap* P){ if(P) P->siz = P->cnt + lsiz(P) + rsiz(P); }

pair < Treap*, Treap* > Split(Treap* P, int val){
    if(!P)return {npt, npt};
    if(val >= P->val){
        auto tmp = Split(P->rs, val);
        P->rs = tmp.first; Pushup(P);
        return {P, tmp.second};
    }else{
        auto tmp = Split(P->ls, val);
        P->ls = tmp.second; Pushup(P);
        return {tmp.first, P};
    }
}

Treap* Merge(Treap* l, Treap* r){
    if(!l && !r)return npt;
    if(!l || !r)return l ? l : r;
    if(l->pri < r->pri){
        l->rs = Merge(l->rs, r);
        Pushup(l); return l;
    }else{
        r->ls = Merge(l, r->ls);
        Pushup(r); return r;
    }
}

void Insert(Treap* &p, int val){
    auto spl = Split(p, val);
    auto spll = Split(spl.first, val - 1);
    if(!spll.second) spll.second = new Treap(npt, npt, val, rnd());
    else { spll.second->cnt++; Pushup(spll.second); }
    p = Merge(Merge(spll.first, spll.second), spl.second);
}

void Delete(Treap* &p, int val){
    auto spl = Split(p, val);
    auto spll = Split(spl.first, val - 1);
    if(spll.second){
        if(spll.second->cnt > 1){ spll.second->cnt--; Pushup(spll.second); }
        else spll.second = npt; // 该结点只存等值，左右为空，安全移除
    }
    p = Merge(Merge(spll.first, spll.second), spl.second);
}

// 第 k 小（1-indexed）
int Kth(Treap* p, int k){
    while(p){
        int L = lsiz(p);
        if(k <= L) p = p->ls;
        else if(k <= L + p->cnt) return p->val;
        else { k -= L + p->cnt; p = p->rs; }
    }
    return -1;
}

int main(){
    int n = read<int>(), m = read<int>(), q = read<int>();
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){ a[i] = read<int>(); Insert(root, a[i]); }

    unll x_, y_, z_; ll lans = 0;
    for(int _=0;_<q;_++){
        x_ = read<unll>(); y_ = read<unll>(); z_ = read<unll>();
        int x = 1 + (int)((x_ + (unll)lans) % (unll)n);
        int y = 1 + (int)((y_ + (unll)lans) % (unll)1000000000ULL);
        int z = 1 + (int)((z_ + (unll)lans) % (unll)n);

        // 永久点修改
        Delete(root, a[x]);
        a[x] = y;
        Insert(root, a[x]);

        // 答案：b_z + b_{z-m} + b_{z-2m} + ...
        long long ans = 0;
        for(int r = z; r >= 1; r -= m){
            ans += (long long)Kth(root, r);
        }
        printf("%lld\n", ans);
        lans = ans;
    }
    return 0;
}

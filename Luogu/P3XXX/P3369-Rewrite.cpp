#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define lsiz(p) p->ls ? p->ls->siz : 0;
#define rsiz(p) p->rs ? p->rs->siz : 0;

/******************************
abbr

******************************/

using namespace std;

mt19937 _rnd(random_device{}());
int rnd(void){return _rnd() % (uint)INT_MAX;}
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

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
}tData[110000];
void* Treap::operator new(size_t){static Treap* P = tData; return ++P;}

template<typename T = int>
inline T read(void);

int N;
Treap* root;
void Pushup(Treap* P){P->siz = lsiz(P) + rsiz(P);}
pair < Treap*, Treap* > Split(Treap* P, int val){
    if(!P)return {npt, npt};
    if(val <= P->val){
        auto tmp = Split(P->ls, val);
        P->ls = tmp.second;
        Pushup(P);
        return {tmp.first, P};
    }else{
        auto tmp = Split(P->rs, val);
        P->rs = tmp.first;
        Pushup(P);
        return {P, tmp.second};
    }
}
Treap* Merge(Treap* l, Treap* r){
    if()
}

int main(){
    N = read();
    (void)read();
    root = new Treap(npt, npt, read(), rnd());
    for(int i = 2; i <= N; ++i){
        int opt = read(), x = read();
        switch(opt){
            case 1:{Insert(root, x); break;}
            case 2:{Delete(root, x); break;}
            case 3:{printf("%d\n", QueryRank(root, x, 0)); break;}
            case 4:{printf("%d\n", QueryVal(root, x, 0)); break;}
            case 5:{printf("%d\n", CalPre(root, x)); break;}
            case 6:{printf("%d\n", CalSuf(root, x)); break;}
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
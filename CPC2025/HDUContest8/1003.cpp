#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define PI M_PI
#define E M_E

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template<typename T = int> T read(void);

struct Clamp {
    int L, R;
    int idL, idR;
};
static Clamp __identity(){return{INT_MIN >> 1, INT_MAX >> 1, -1, -1};}
static Clamp make_pair_clamp(int id1, int c1, int id2, int c2){
    if(c1 < c2)return {c1, c2, id1, id2};
    else return {c2, c1, id2, id1};
}
static Clamp compose(const Clamp& a, const Clamp& b){
    if(!(b.L > a.R || b.R < a.L)){
        Clamp res;
        if(a.L >= b.L)res.L = a.L, res.idL = a.idL; 
        else res.L = b.L, res.idL = b.idL; 
        if(a.R <= b.R)res.R = a.R, res.idR = a.idR; 
        else res.R = b.R, res.idR = b.idR; 
        return res;
    }
    if(b.L > a.R) return {b.L, b.L, b.idL, b.idL};
    else return {b.R, b.R, b.idR, b.idR};
}

struct Meta {
    int sz = 0;
    int fstID = -1, fstC = 0;
    int lstID = -1, lstC = 0;
    Clamp F[2] = {__identity(), __identity()};
};

const int LIM = 510000;
int c[LIM];
int pos[LIM];

static Meta GLOBAL_META;

struct Key {
    int pos, id;
    bool operator<(const Key& o)const{
        if(pos != o.pos)return pos < o.pos;
        return id < o.id;
    }
};

template < class Node_CItr, class Node_Itr, class Cmp_Fn, class _Alloc >
struct Update {
    typedef Meta metadata_type;

    void operator()(Node_Itr it, Node_CItr end_it) const {
        Meta res;
        Node_CItr L = it.get_l_child();
        Node_CItr R = it.get_r_child();

        const Meta *ML = (L == end_it ? nullptr : &L.get_metadata());
        const Meta *MR = (R == end_it ? nullptr : &R.get_metadata());

        const Key &k = **it;
        int id = k.id, c = ::c[id];

        res.sz = 1 + (ML ? ML->sz : 0) + (MR ? MR->sz : 0);

        if(ML)res.fstID = ML->fstID, res.fstC = ML->fstC;
        else res.fstID = id, res.fstC = c;
        if(MR)res.lstID = MR->lstID, res.lstC = MR->lstC;
        else res.lstID = id, res.lstC = c;
        
        for(int p = 0; p < 2; ++p){
            Clamp cur = __identity();
            if(ML){
                cur = compose(cur, ML->F[p]);
                int last_parity = (p ^ ((ML->sz - 1) & 1));
                if(!last_parity){
                    Clamp cross = make_pair_clamp(ML->lstID, ML->lstC, id, c);
                    cur = compose(cur, cross);
                }
            }
            if(MR){
                int node_parity = (p ^ ((ML ? ML->sz : 0) & 1));
                if(!node_parity){
                    Clamp cross2 = make_pair_clamp(id, c, MR->fstID, MR->fstC);
                    cur = compose(cur, cross2);
                }
                int pR = p ^ (((ML ? ML->sz : 0) + 1) & 1);
                cur = compose(cur, MR->F[pR]);
            }
            res.F[p] = cur;
        }

        const_cast < Meta& >(it.get_metadata()) = res;
        GLOBAL_META = res;
    }

    const Meta& get_root_meta()const{return GLOBAL_META;}
};


int main(){
    int T = read();
    while(T--){
        int N = read(), M = read();
        for(int i = 1; i <= N; ++i)pos[i] = read();
        for(int i = 1; i <= N; ++i)c[i] = read();

        tree < Key, null_type, less < Key >, splay_tree_tag, Update > tr;
        for(int i = 1; i <= N; i++)tr.insert({pos[i], i});

        auto QueryAns = [&]()->int{
            if(tr.empty())return -1;
            const Meta &M = GLOBAL_META;
            int c1 = M.fstC;
            const Clamp &all = M.F[1];
            if(c1 < all.L)return all.idL;
            if(c1 > all.R)return all.idR;
            return M.fstID;
        };
        while(M--){
            int opt = read();
            if(opt == 1){
                int s = read(), t = read();
                tr.erase({pos[s], s});
                pos[s] = t;
                tr.insert({pos[s], s});
            }else{
                printf("%d\n", QueryAns());
            }
        }
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T> T read(void){
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
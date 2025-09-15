#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

struct Clamp {
    int L, R;
    int idL, idR;
};
static inline Clamp identity(){ return {INT_MIN/2, INT_MAX/2, -1, -1}; }
static inline Clamp make_pair_clamp(int id1,int c1,int id2,int c2){
    if(c1 < c2) return {c1,c2,id1,id2};
    else return {c2,c1,id2,id1};
}
static inline Clamp compose(const Clamp& a, const Clamp& b){
    if(!(b.L > a.R || b.R < a.L)){
        Clamp res;
        if(a.L >= b.L){ res.L = a.L; res.idL = a.idL; }
        else { res.L = b.L; res.idL = b.idL; }
        if(a.R <= b.R){ res.R = a.R; res.idR = a.idR; }
        else { res.R = b.R; res.idR = b.idR; }
        return res;
    }
    if(b.L > a.R) return {b.L, b.L, b.idL, b.idL};
    else return {b.R, b.R, b.idR, b.idR};
}

struct Meta {
    int sz = 0;
    int first_id=-1, first_c=0;
    int last_id=-1, last_c=0;
    Clamp F[2] = {identity(), identity()};
};

static const int MAXN = 500000 + 5;
static int C[MAXN];
static int POS[MAXN];

static Meta GLOBAL_META;

struct Key {
    int pos, id;
    bool operator<(const Key& o) const {
        if(pos != o.pos) return pos < o.pos;
        return id < o.id;
    }
};

template<class Node_CItr, class Node_Itr, class Cmp_Fn, class _Alloc>
struct Update {
    typedef Meta metadata_type;

    void operator()(Node_Itr it, Node_CItr end_it) const {
        Meta res;
        Node_CItr L = it.get_l_child();
        Node_CItr R = it.get_r_child();

        const Meta *ML = (L == end_it ? nullptr : &L.get_metadata());
        const Meta *MR = (R == end_it ? nullptr : &R.get_metadata());

        const Key &k = **it;
        int id = k.id, c = C[id];

        res.sz = 1 + (ML ? ML->sz : 0) + (MR ? MR->sz : 0);

        if(ML){
            res.first_id = ML->first_id;
            res.first_c = ML->first_c;
        }else{
            res.first_id = id;
            res.first_c = c;
        }
        if(MR){
            res.last_id = MR->last_id;
            res.last_c = MR->last_c;
        }else{
            res.last_id = id;
            res.last_c = c;
        }

        for(int p=0;p<2;p++){
            Clamp cur = identity();
            if(ML){
                cur = compose(cur, ML->F[p]);
                int last_parity = (p ^ ((ML->sz - 1) & 1));
                if(last_parity == 0){
                    Clamp cross = make_pair_clamp(ML->last_id, ML->last_c, id, c);
                    cur = compose(cur, cross);
                }
            }
            if(MR){
                int node_parity = (p ^ ((ML ? ML->sz : 0) & 1));
                if(node_parity == 0){
                    Clamp cross2 = make_pair_clamp(id, c, MR->first_id, MR->first_c);
                    cur = compose(cur, cross2);
                }
                int pR = p ^ (((ML ? ML->sz : 0) + 1) & 1);
                cur = compose(cur, MR->F[pR]);
            }
            res.F[p] = cur;
        }

        const_cast<Meta&>(it.get_metadata()) = res;
        GLOBAL_META = res;
    }

    const Meta& get_root_meta() const { return GLOBAL_META; }
};

using OST = tree<Key, null_type, less<Key>, rb_tree_tag, Update>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; if(!(cin>>T)) return 0;
    while(T--){
        int n,m; cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>POS[i];
        for(int i=1;i<=n;i++) cin>>C[i];

        OST tr;
        for(int i=1;i<=n;i++){
            tr.insert({POS[i], i});
        }

        auto query_winner = [&]()->int{
            if(tr.empty()) return -1;
            const Meta &M = GLOBAL_META;
            int c1 = M.first_c;
            const Clamp &all = M.F[1];
            if(c1 < all.L) return all.idL;
            if(c1 > all.R) return all.idR;
            return M.first_id;
        };

        while(m--){
            int tp; cin>>tp;
            if(tp==1){
                int x,y; cin>>x>>y;
                tr.erase({POS[x], x});
                POS[x] = y;
                tr.insert({POS[x], x});
            }else{
                cout << query_winner() << '\n';
            }
        }
    }
    return 0;
}

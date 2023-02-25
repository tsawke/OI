#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template < typename T = int >
inline T read(void);

int N, M;
int vote[510000];
tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > tr[510000];

class SegTree{
private:
    int tr[510000 << 2], cnt[510000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    pair < int, int > Merge(pair < int, int > l, pair < int, int > r){
        if(l.first == r.first)return {l.first = r.first, l.second + r.second};
        if(l.second >= r.second)return {l.first, l.second - r.second};
        else return {r.first, r.second - l.second};
    }
    void Pushup(int p){
        tie(tr[p], cnt[p]) = Merge({tr[LS], cnt[LS]}, {tr[RS], cnt[RS]});
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = vote[gl = gr], cnt[p] = 1, void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    void Modify(int pos, int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = vote[gl = gr], void();
        if(pos <= MID)Modify(pos, LS, gl, MID);
        else Modify(pos, RS, MID + 1, gr);
        Pushup(p);
    }
    pair < int, int > Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return {tr[p], cnt[p]};
        pair < int, int > ret{0, -1};
        if(l <= MID)ret = Merge(Query(l, r, LS, gl, MID), ret);
        if(r >= MID + 1)ret = Merge(Query(l, r, RS, MID + 1, gr), ret);
        return ret;
    }
}st;

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)tr[vote[i] = read()].insert(i);
    st.Build();
    while(M--){
        int l = read(), r = read(), s = read(), k = read();
        auto win = st.Query(l, r).first;
        int rnkR = tr[win].order_of_key(r);
        if(*tr[win].find_by_order(rnkR) != r)--rnkR;
        int rnkL = tr[win].order_of_key(l);
        if(rnkR - rnkL + 1 > ((r - l + 1) >> 1))s = win;
        while(k--){
            int p = read();
            tr[vote[p]].erase(p), tr[s].insert(p);
            vote[p] = s, st.Modify(p);
        }printf("%d\n", s);
    }
    int l = 1, r = N, s = -1;
    auto win = st.Query(l, r).first;
    int rnkR = tr[win].order_of_key(r);
    if(*tr[win].find_by_order(rnkR) != r)--rnkR;
    int rnkL = tr[win].order_of_key(l);
    if(rnkR - rnkL + 1 > ((r - l + 1) >> 1))s = win;
    printf("%d\n", s);
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
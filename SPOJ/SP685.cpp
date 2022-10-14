#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define INF 0x3f3f3f3f

template<typename T = int>
inline T read(void);

struct Node{
    Node *ls, *rs;
    int fmn, fmx;
    OPNEW;
}nd[30000000];
void* Node::operator new(size_t){static Node* P = nd; return P++;}
int limMin, limMax;
int N, K;
int a[18000];
int sum[18000];
int fmn[18000], fmx[18000];
Node* rt;
class SegTree{
    private:
        #define MID ((gl + gr) >> 1)
        #define SIZ (gr - gl + 1)
    public:
        void Pushup(Node* p){
            if(!p)return;
            p->fmn = min(p->ls ? p->ls->fmn : INF, p->rs ? p->rs->fmn : INF),
            p->fmx = max(p->ls ? p->ls->fmx : -INF, p->rs ? p->rs->fmx : -INF);
        }
        void Modify(int idx, pair < int, int > val, Node* &p = rt, int gl = limMin, int gr = limMax){
            if(!p)p = new Node{npt, npt, INF, 0};
            if(gl == gr)return tie(p->fmn, p->fmx) = val, void();
            if(idx <= MID) Modify(idx, val, p->ls, gl, MID);
            else Modify(idx, val, p->rs, MID + 1, gr);
            Pushup(p);
        }
        pair < int, int > Query(int l, int r, Node* p = rt, int gl = limMin, int gr = limMax){
            // printf("Querying l = %d, r = %d, gl = %d, gr = %d, val = %d,%d\n", l, r, gl, gr, p ? p->fmn : -114514, p ? p->fmx : 114514);
            if(!p)return {INF, -INF};
            if(l <= gl && gr <= r)return {p->fmn, p->fmx};
            auto L = MID >= l ? Query(l, r, p->ls, gl, MID) : make_pair(INF, -INF);
            auto R = MID + 1 <= r ? Query(l, r, p->rs, MID + 1, gr) : make_pair(INF, -INF);
            return {min(L.first, R.first), max(L.second, R.second)};
        }
}st;
bool Check(int M){
    rt = new Node{npt, npt, INF, -INF};
    fmx[0] = fmn[0] = 0;
    st.Modify(sum[0], {fmn[0], fmx[0]});
    for(int i = 1; i <= N; ++i){
        tie(fmn[i], fmx[i]) = st.Query(sum[i] - M, INF);
        ++fmn[i], ++fmx[i];
        st.Modify(sum[i], {fmn[i], fmx[i]});
    }
    if(fmn[N] <= K && K <= fmx[N])return true;
    return false;
}
int main(){
    int T = read();
    while(T--){
        limMin = limMax = 0;
        N = read(), K = read();
        for(int i = 1; i <= N; ++i)
            a[i] = read(),
            a[i] >= 0 ? limMax += a[i] : limMin += a[i],
            sum[i] = sum[i - 1] + a[i];
        int l = limMin, r = limMax, ans(-1);
        while(l <= r){
            int mid = (l + r) >> 1;
            if(Check(mid))ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        printf("%d\n", ans);
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
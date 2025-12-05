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

#define MAXN (110000)
#define MAXN2 (MAXN << 1)
#define MAXN4 (MAXN << 2)
#define MAXN8 (MAXN << 3)

template< typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    bool val;
    OPNEW;
}ed[MAXN8 << 1];
ROPNEW(ed);
Edge* head[MAXN8];

struct Node{int a, b; int idx;};

int leaf[MAXN2];
int N, D;
#define N2 (N << 1)
Node val[MAXN2];
Node A[MAXN], B[MAXN];
int dis[MAXN8];
int ans[MAXN4];

class SegTree{
#define MID ((gl + gr) >> 1)
#define LS (p << 1)
#define RS (LS | 1)
private:
public:
    void Build(int p = 1, int gl = 1, int gr = N2){
        if(gl == gr)return leaf[gl = gr] = p, void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        head[p] = new Edge{head[p], LS, 0};
        head[p] = new Edge{head[p], RS, 0};
    }
    void Connect(int ori, int l, int r, int p = 1, int gl = 1, int gr = N2){
        if(l > r)return;
        if(l <= gl && gr <= r)return head[ori] = new Edge{head[ori], p, 1}, void();
        if(l <= MID)Connect(ori, l, r, LS, gl, MID);
        if(MID + 1 <= r)Connect(ori, l, r, RS, MID + 1, gr);
    }
}st;
void bfs(void){
    memset(dis, 0x3f, sizeof dis);
    deque < int > dq;
    for(int i = 1; i <= N2; ++i)
        if((!val[i].a && i >= N + 1) || (!val[i].b && i <= N))
            dis[leaf[i]] = 1, dq.push_back(leaf[i]);
    while(!dq.empty()){
        int tp = dq.front(); dq.pop_front();
        for(auto i = head[tp]; i; i = i->nxt)
            if(dis[tp] + i->val < dis[SON]){
                dis[SON] = dis[tp] + i->val;
                i->val ? dq.push_back(SON) : dq.push_front(SON);
            }
    }
    for(int i = 1; i <= N2; ++i)ans[val[i].idx] = dis[leaf[i]];
}
int main(){
    // freopen("P4083_5.in", "r", stdin);
    #define CMP_SECOND [](Node x, Node y)->bool{return x.b < y.b;}
    #define CMP_FIRST [](Node x, Node y)->bool{return x.a < y.a;}
    N = read(), D = read(); st.Build();
    for(int i = 1; i <= N; ++i)A[i].a = read(), A[i].b = read(), A[i].idx = i;
    for(int i = 1; i <= N; ++i)B[i].a = read(), B[i].b = read(), B[i].idx = i + N;
    sort(A + 1, A + N + 1, CMP_SECOND);
    sort(B + 1, B + N + 1, CMP_FIRST);
    for(int i = 1; i <= N; ++i)val[i] = A[i], val[i + N] = B[i];
    // for(int i = 1; i <= N2; ++i)printf("VAL %d : %d | %d | %d\n", i, val[i].a, val[i].b, val[i].idx);
    for(int i = 1; i <= N; ++i){
        int ptl = distance(B + 1, lower_bound(B + 1, B + N + 1, Node{A[i].a - D, 0, 0}, CMP_FIRST) + 1);
        int ptr = distance(B + 1, upper_bound(B + 1, B + N + 1, Node{A[i].a, 0, 0}, CMP_FIRST));
        st.Connect(leaf[i], ptl + N, ptr + N);
        ptl = distance(A + 1, lower_bound(A + 1, A + N + 1, Node{0, B[i].b - D, 0}, CMP_SECOND) + 1);
        ptr = distance(A + 1, upper_bound(A + 1, A + N + 1, Node{0, B[i].b, 0}, CMP_SECOND));
        st.Connect(leaf[i + N], ptl, ptr);
    }bfs();
    for(int i = 1; i <= N; ++i)printf("%d\n", ans[i] == 0x3f3f3f3f ? -1 : ans[i]);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
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
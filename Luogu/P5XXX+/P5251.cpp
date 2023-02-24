#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define LIM (110000)
#define INF (0x3f3f3f3f)

template < typename T = int >
inline T read(void);

int N, M, C;
int val[LIM], col[LIM];
int cnt[110];

class SegTree{
private:
    int sum[LIM << 2], mn[LIM << 2], mx[LIM << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    SegTree(void){memset(mn, 0x3f, sizeof mn);}
    void Pushup(int p){
        sum[p] = sum[LS] + sum[RS];
        mn[p] = min(mn[LS], mn[RS]);
        mx[p] = max(mx[LS], mx[RS]);
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return sum[p] = mn[p] = mx[p] = val[gl = gr], void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    void Modify(int pos, int val, int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return sum[p] = mn[p] = mx[p] = val, void();
        if(pos <= MID)Modify(pos, val, LS, gl, MID);
        else Modify(pos, val, RS, MID + 1, gr);
        Pushup(p);
    }
    int QuerySum(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return sum[p];
        if(l > gr || r < gl)return 0;
        return QuerySum(l, r, LS, gl, MID) + QuerySum(l, r, RS, MID + 1, gr);
    }
    int QueryMin(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return mn[p];
        if(l > gr || r < gl)return INF;
        return min(QueryMin(l, r, LS, gl, MID), QueryMin(l, r, RS, MID + 1, gr));
    }
    int QueryMax(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return mx[p];
        if(l > gr || r < gl)return 0;
        return max(QueryMax(l, r, LS, gl, MID), QueryMax(l, r, RS, MID + 1, gr));
    }
}st;

struct Node{
    int l, r;
    mutable int val;
    friend const bool operator < (const Node &a, const Node &b){
        return a.l < b.l;
    }
};

class ODT{
private:
    set < Node > tr;
public:
    auto Insert(Node p){return tr.insert(p);}
    auto Split(int p){
        auto it = tr.lower_bound(Node{p});
        if(it != tr.end() && it->l == p)return it;
        advance(it, -1);
        if(it->r < p)return tr.end();
        auto l = it->l, r = it->r, val = it->val;
        tr.erase(it);
        Insert(Node{l, p - 1, val});
        return Insert(Node{p, r, val}).first;
    }
    void Assign(int l, int r, int val){
        auto itR = Split(r + 1), itL = Split(l);
        tr.erase(itL, itR);
        Insert(Node{l, r, val});
    }
    int Query3(int l, int r){
        int tot(0);
        auto itR = Split(r + 1), itL = Split(l);
        auto itl = itL, itr = itL;
        while(itl != itR){
            while(tot < C && itr != itR)
        }
    }

}odt;

int main(){
    N = read(), M = read(), C = read();
    for(int i = 1; i <= N; ++i)val[i] = read();
    for(int i = 1; i <= N; ++i)col[i] = read(), odt.Insert(Node{i, i, col[i]});
    st.Build();
    while(M--){
        int opt = read();
        switch(opt){
            case 1:{
                int p = read(), v = read();
                st.Modify(p, v);
                break;
            }
            case 2:{
                int l = read(), r = read(), v = read();
                odt.Assign(l, r, v);
                break;
            }
            case 3:{
                int l = read(), r = read();

            }
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
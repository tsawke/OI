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

#define d(p) (vdata.at(p - 1))

template < typename T = int >
inline T read(void);

int N;
int rN;
ll ans(0);
struct Line{int l, r; int h; int val;};
basic_string < Line > lines;
basic_string < int > vdata;
tuple < int, int, int, int > vals[5100];

class SegTree{
private:
    int len[11000 << 2], lz[11000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p, int gl, int gr){
        if(lz[p])len[p] = d(gr + 1) - d(gl);
        else len[p] = gl == gr ? 0 : len[LS] + len[RS];
    }
    void Modify(int l, int r, int val, int p = 1, int gl = 1, int gr = N - 1){
        if(l <= gl && gr <= r)return lz[p] += val, Pushup(p, gl, gr);
        if(l <= MID)Modify(l, r, val, LS, gl, MID);
        if(r >= MID + 1)Modify(l, r, val, RS, MID + 1, gr);
        Pushup(p, gl, gr);
    }
    int Query(void){return len[1];}
}st, st2;

int main(){
    rN = read();
    for(int i = 1; i <= rN; ++i){
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        vals[i] = {x1, y1, x2, y2};
        vdata += {x1, x2};
        lines += {Line{x1, x2, y1, 1}, Line{x1, x2, y2, -1}};
    }N = lines.size();
    sort(vdata.begin(), vdata.end());
    vdata.erase(unique(vdata.begin(), vdata.end()), vdata.end());
    for(auto &line : lines){
        line.l = distance(vdata.begin(), next(lower_bound(vdata.begin(), vdata.end(), line.l)));
        line.r = distance(vdata.begin(), next(lower_bound(vdata.begin(), vdata.end(), line.r))) - 1;
    }sort(lines.begin(), lines.end(), [](const Line &a, const Line &b)->bool{return a.h == b.h ? a.val > b.val : a.h < b.h;});
    int lstlen(0);
    for(auto it = lines.begin(); it != lines.end(); advance(it, 1)){
        st.Modify(it->l, it->r, it->val);
        int curlen = st.Query();
        ans += abs(curlen - lstlen);
        lstlen = curlen;
    }vdata.clear(), lines.clear();
    for(int i = 1; i <= rN; ++i){
        auto [x1, y1, x2, y2] = vals[i];
        vdata += {y1, y2},
        lines += {Line{y1, y2, x1, 1}, Line{y1, y2, x2, -1}};
    }sort(vdata.begin(), vdata.end());
    vdata.erase(unique(vdata.begin(), vdata.end()), vdata.end());
    for(auto &line : lines){
        line.l = distance(vdata.begin(), next(lower_bound(vdata.begin(), vdata.end(), line.l)));
        line.r = distance(vdata.begin(), next(lower_bound(vdata.begin(), vdata.end(), line.r))) - 1;
    }sort(lines.begin(), lines.end(), [](const Line &a, const Line &b)->bool{return a.h == b.h ? a.val > b.val : a.h < b.h;});
    lstlen = 0;
    for(auto it = lines.begin(); it != lines.end(); advance(it, 1)){
        st2.Modify(it->l, it->r, it->val);
        int curlen = st2.Query();
        ans += abs(curlen - lstlen);
        lstlen = curlen;
    }printf("%lld\n", ans);
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
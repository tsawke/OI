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
ll ans(0);
struct Line{int l, r; int h; int val;};
basic_string < Line > lines;
basic_string < int > vdata;

class SegTree{
private:
    int len[210000 << 2], lz[210000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p, int gl, int gr){
        if(!lz[p])len[p] = gl == gr ? 0 : len[LS] + len[RS];
        else len[p] = d(gr + 1) - d(gl);
    }
    void Modify(int l, int r, int val, int p = 1, int gl = 1, int gr = N - 1){
        if(l <= gl && gr <= r)return lz[p] += val, Pushup(p, gl, gr);
        if(l <= MID)Modify(l, r, val, LS, gl, MID);
        if(r >= MID + 1)Modify(l, r, val, RS, MID + 1, gr);
        Pushup(p, gl, gr);
    }
    int Query(void){return len[1];}
}st;

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        vdata += {x1, x2};
        lines += {Line{x1, x2, y1, 1}, Line{x1, x2, y2, -1}};
    }N = lines.size();
    sort(vdata.begin(), vdata.end());
    vdata.erase(unique(vdata.begin(), vdata.end()), vdata.end());
    for(auto &line : lines){
        line.l = distance(vdata.begin(), next(lower_bound(vdata.begin(), vdata.end(), line.l)));
        line.r = distance(vdata.begin(), next(lower_bound(vdata.begin(), vdata.end(), line.r))) - 1;
    }sort(lines.begin(), lines.end(), [](const Line &a, const Line &b)->bool{return a.h < b.h;});
    for(auto it = lines.begin(); it != lines.end(); advance(it, 1)){
        int curh = it->h;
        st.Modify(it->l, it->r, it->val);
        while(next(it) != lines.end() && next(it)->h == curh)
            advance(it, 1), st.Modify(it->l, it->r, it->val);
        if(next(it) != lines.end())ans += (ll)st.Query() * (next(it)->h - curh);
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
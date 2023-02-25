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

#define EPS (1e-6)
#define LIM (41000)

template < typename T = int >
inline T read(void);

struct Interval{
    bool flag;
    int idx;
    double k, b;
    double CalVal(int x){
        return k * x + b;
    }
};
class LCSegTree{
private:
    Interval tr[LIM << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Update(Interval line, int p, int gl, int gr){
        if(!tr[p].flag)return tr[p] = line, void();
        if(fabs(line.CalVal(MID) - tr[p].CalVal(MID)) < EPS){
            if(line.idx < tr[p].idx)swap(tr[p], line);
        }else if(line.CalVal(MID) > tr[p].CalVal(MID))swap(tr[p], line);
        if(gl != gr && (fabs(line.CalVal(gl) - tr[p].CalVal(gl)) < EPS || line.CalVal(gl) > tr[p].CalVal(gl)))Update(line, LS, gl, MID);
        if(gl != gr && (fabs(line.CalVal(gr) - tr[p].CalVal(gr)) < EPS || line.CalVal(gr) > tr[p].CalVal(gr)))Update(line, RS, MID + 1, gr);
    }
    void UpdatePoint(int pos, int val, int idx, int p = 1, int gl = 1, int gr = LIM){
        if(gl == gr){
            if(!tr[p].flag)tr[p] = Interval{true, idx, 0.0, (double)val};
            else if(fabs(tr[p].CalVal(pos) - (double)val) < EPS)tr[p].idx = min(tr[p].idx, idx);
            else if(tr[p].CalVal(pos) < (double)val)tr[p] = Interval{true, idx, 0.0, (double)val};
            return;
        }
        if(pos <= MID)UpdatePoint(pos, val, idx, LS, gl, MID);
        else UpdatePoint(pos, val, idx, RS, MID + 1, gr);
    }
    void Insert(Interval line, int l, int r, int p = 1, int gl = 1, int gr = LIM){
        if(l <= gl && gr <= r)return Update(line, p, gl, gr);
        if(l <= MID)Insert(line, l, r, LS, gl, MID);
        if(r >= MID + 1)Insert(line, l, r, RS, MID + 1, gr);
    }
    pair < int, double > Query(int pos, int p = 1, int gl = 1, int gr = LIM){
        auto ret = tr[p].idx; auto mxv = tr[p].CalVal(pos);
        if(gl != gr){
            auto vals = pos <= MID ? Query(pos, LS, gl, MID) : Query(pos, RS, MID + 1, gr);
            if(fabs(vals.second - mxv) < EPS)ret = min(ret, vals.first);
            else if(vals.second > mxv)ret = vals.first, mxv = vals.second;
        }return {ret, mxv};
    }
}lcst;

int N;
int cnt(0);
int lst(0);

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        int opt = read();
        if(opt == 0){
            int ans = lcst.Query((read() + lst - 1) % 39989 + 1).first;
            lst = ans;
            printf("%d\n", ans);
            continue;
        }
        int sx = (read() + lst - 1) % 39989 + 1, sy = (read() + lst - 1) % (int)(1e9) + 1;
        int tx = (read() + lst - 1) % 39989 + 1, ty = (read() + lst - 1) % (int)(1e9) + 1;
        if(sx == tx)lcst.UpdatePoint(sx = tx, max(sy, ty), ++cnt);
        else lcst.Insert(Interval{true, ++cnt, (double)(ty - sy) / (tx - sx), (double)ty - (double)(ty - sy) / (tx - sx) * tx}, min(sx, tx), max(sx, tx));
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
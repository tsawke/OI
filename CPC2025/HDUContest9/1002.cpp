#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){ return rnd() % (r - l + 1) + l; }

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template < typename T = int >
inline T read();

const ll MOD = 1000000007ll;
const ll PhiMain = MOD - 1;

auto qpow = [](ll a, ll b, ll mod = MOD)->ll{
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % mod;
        b >>= 1;
        mul = mul * mul % mod;
    }return ret;
};

struct IntMod{
    ll preProd, sufProd, midSum;
    int blkCnt;
    ll mod;
    IntMod(ll m = MOD): preProd(0), sufProd(0), midSum(0), blkCnt(0), mod(m){}
    static IntMod Default(ll x, ll m){
        x = ((x % m) + m) % m;
        IntMod t(m);
        t.preProd = t.sufProd = x; t.midSum = 0; t.blkCnt = 1; return t;
    }
    ll Value() const{
        if(blkCnt == 0)return 0;
        if(blkCnt == 1)return preProd;
        ll r = preProd; r = (r + midSum) % mod; r = (r + sufProd) % mod;
        return r;
    }
    IntMod operator+(const IntMod &rhs) const{
        if(blkCnt == 0) return rhs;
        if(rhs.blkCnt == 0) return *this;
        IntMod t(mod);
        t.preProd = preProd; t.sufProd = rhs.sufProd; t.blkCnt = blkCnt + rhs.blkCnt;
        t.midSum = (midSum + rhs.midSum) % mod;
        if(blkCnt >= 2) t.midSum = (t.midSum + sufProd) % mod;
        if(rhs.blkCnt >= 2) t.midSum = (t.midSum + rhs.preProd) % mod;
        return t;
    }
    IntMod operator*(const IntMod &rhs) const{
        if(blkCnt == 0) return rhs;
        if(rhs.blkCnt == 0) return *this;
        IntMod t(mod);
        ll cross = sufProd * rhs.preProd % mod;
        t.blkCnt = blkCnt + rhs.blkCnt - 1;
        t.preProd = (blkCnt >= 2) ? preProd : cross;
        t.sufProd = (rhs.blkCnt >= 2) ? rhs.sufProd : cross;
        t.midSum = (midSum + rhs.midSum) % mod;
        if(blkCnt >= 2 && rhs.blkCnt >= 2) t.midSum = (t.midSum + cross) % mod;
        return t;
    }
};

struct ExprInt{
    bool hasShift;
    IntMod intMain, intPhi;
    IntMod expTotal, expRight;
    ExprInt(): hasShift(false), intMain(MOD), intPhi(PhiMain), expTotal(PhiMain), expRight(PhiMain){}
    static ExprInt Num(ll x){
        ExprInt t; t.hasShift = false; t.intMain = IntMod::Default(x, MOD); t.intPhi = IntMod::Default(x, PhiMain); return t;
    }
    ll Eval() const{
        ll base = intMain.Value();
        ll e = expTotal.Value() % PhiMain;
        return base * qpow(2, e, MOD) % MOD;
    }
    ExprInt operator +(const ExprInt &rhs) const{
        ExprInt t = *this;
        if(t.hasShift){
            ll oldB = t.expRight.Value();
            t.expRight = t.expRight + rhs.intPhi;
            ll newB = t.expRight.Value();
            t.expTotal = IntMod::Default(((t.expTotal.Value() + ((newB - oldB) % PhiMain + PhiMain) % PhiMain) % PhiMain + PhiMain) % PhiMain, PhiMain);
            t.expTotal = IntMod::Default((t.expTotal.Value() + rhs.expTotal.Value()) % PhiMain, PhiMain);
            if(rhs.hasShift)t.expRight = rhs.expRight;
        }else{
            t.intMain = t.intMain + rhs.intMain;
            t.intPhi = t.intPhi + rhs.intPhi;
            if(rhs.hasShift){
                t.hasShift = true,
                t.expTotal = rhs.expTotal,
                t.expRight = rhs.expRight;
            }
        }return t;
    }
    ExprInt operator*(const ExprInt &rhs) const{
        ExprInt t = *this;
        if(t.hasShift){
            ll oldB = t.expRight.Value();
            t.expRight = t.expRight * rhs.intPhi;
            ll newB = t.expRight.Value();
            ll nv = (t.expTotal.Value() + ((newB - oldB) % PhiMain + PhiMain) % PhiMain) % PhiMain;
            nv = (nv + rhs.expTotal.Value()) % PhiMain;
            t.expTotal = IntMod::Default(nv, PhiMain);
            if(rhs.hasShift)t.expRight = rhs.expRight;
        }else{
            t.intMain = t.intMain * rhs.intMain;
            t.intPhi = t.intPhi * rhs.intPhi;
            if(rhs.hasShift){
                t.hasShift = true;
                t.expTotal = rhs.expTotal;
                t.expRight = rhs.expRight;
            }
        }return t;
    }
    friend ExprInt operator<<(const ExprInt &lhs, const ExprInt &rhs){
        ExprInt t = lhs;
        t.hasShift = true;
        ll inc = (rhs.intPhi.Value() + rhs.exTotal.Value()) % PhiMain;
        t.expTotal = IntMod::Default((t.expTotal.Value() + inc) % PhiMain, PhiMain);
        t.expRight = rhs.hasShift ? rhs.expRight : rhs.intPhi;
        return t;
    }
};

int main(){
    int N = read();
    vector < char > opCh(N + 1);
    vector < int > idxA(N + 1), idxB(N + 1);
    vector < ll > numX(N + 1, 0);
    vector < int > indegCnt(N + 1, 0);

    int mcap = 2 * N + 5;
    vector < int > head(N + 1, -1), to(mcap), nxt(mcap);
    int ecnt = 0;
    auto addEdge = [&](int u, int v){
        to[ecnt] = v; nxt[ecnt] = head[u]; head[u] = ecnt++;
    };

    for(int i = 1; i <= N; ++i){
        char opt = getchar();
        while(opt != 'N' && opt != '<' && opt != '+' && opt != '*') opt = getchar();
        if(opt == 'N'){
            ll x = read < ll >();
            opCh[i] = 'N'; numX[i] = x;
        }else{
            int aIdx = read(), bIdx = read();
            opCh[i] = opt; idxA[i] = aIdx; idxB[i] = bIdx;
            addEdge(aIdx, i); indegCnt[i]++;
            addEdge(bIdx, i); indegCnt[i]++;
        }
    }

    queue < int > topo;
    for(int i = 1; i <= N; ++i) if(indegCnt[i] == 0) topo.push(i);

    vector < ExprInt > exprArr(N + 1);
    vector < uint32_t > ansArr(N + 1, 0);

    while(!topo.empty()){
        int u = topo.front(); topo.pop();
        if(opCh[u] == 'N') exprArr[u] = ExprInt::Num(numX[u]);
        else if(opCh[u] == '+') exprArr[u] = exprArr[idxA[u]] + exprArr[idxB[u]];
        else if(opCh[u] == '*') exprArr[u] = exprArr[idxA[u]] * exprArr[idxB[u]];
        else exprArr[u] = exprArr[idxA[u]] << exprArr[idxB[u]];

        ansArr[u] = (uint32_t)exprArr[u].Eval();

        for(int e = head[u]; e != -1; e = nxt[e]){
            int v = to[e];
            if(--indegCnt[v] == 0) topo.push(v);
        }
    }

    for(int i = 1; i <= N; ++i) printf("%u\n", ansArr[i]);
    return 0;
}

template < typename T >
inline T read(){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c)) c = getchar();
    if(c == '-') flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}

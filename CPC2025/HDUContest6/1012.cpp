#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define MOD (998244353ll)
#define DFT (true)
#define IDFT (false)

template<typename T = int>
inline T read(void);

ll g(3), inv_g;
int pos[1 << 20];

ll qpow(ll a, ll b){
    ll ret(1), mul(a % MOD);
    if(mul < 0) mul += MOD;
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

class Polynomial{
public:
    int len;
    ll poly[410000];
    Polynomial(){ len=0; memset(poly,0,sizeof poly); }
    Polynomial(int n){ len=n; memset(poly,0,sizeof poly); }

    void Reverse(void){
        for(int i = 0; i < len; ++i)
            pos[i] = (pos[i >> 1] >> 1) | (i & 1 ? len >> 1 : 0);
        for(int i = 0; i < len; ++i)if(i < pos[i])swap(poly[i], poly[pos[i]]);
    }
    void NTT(bool pat){
        Reverse();
        for(int siz = 2; siz <= len; siz <<= 1){
            ll gn = qpow(pat ? g : inv_g, (MOD - 1) / siz);
            for(auto p = poly; p < poly + len; p += siz){
                int mid(siz >> 1); ll gg(1);
                for(int i = 0; i < mid; ++i, (gg *= gn) %= MOD){
                    auto tmp = gg * p[i + mid] % MOD;
                    p[i + mid] = (p[i] - tmp + MOD) % MOD;
                    p[i] = (p[i] + tmp) % MOD;
                }
            }
        }
        if(!pat){
            ll inv_len = qpow(len, MOD - 2);
            for(int i = 0; i < len; ++i)(poly[i] *= inv_len) %= MOD;
        }
    }
    void Derivate(void){
        for(int i = 1; i < len; ++i)poly[i - 1] = i * poly[i] % MOD;
        if(len) poly[len - 1] = 0;
        len = max(1, len - 1);
    }
    void Integrate(void){
        for(int i = len - 1; i >= 0; --i)poly[i + 1] = poly[i] * qpow(i + 1, MOD - 2) % MOD;
        poly[0] = 0;
        ++len;
    }
    void Resize(int n){
        if(n < len)
            for(int i = n; i < len; ++i)poly[i] = 0;
        len = n;
    }
    void Print(void){
        printf("Polynomial(len = %d): ", len);
        for(int i = 0; i < len; ++i)printf("%lld ", poly[i]);
        printf("\n");
    }
}basic[8];

/* ------------------ 使用静态工作区 + 返回指针 ------------------ */
Polynomial* MulPtr(Polynomial* A, Polynomial* B, int mx) {
    int need = min(mx + 1, A->len + B->len - 1);
    if(A->len == 0 || B->len == 0 || need <= 0){
        return new Polynomial(0);
    }
    int base(1);
    while(base < need) base <<= 1;

    static Polynomial FA, FB;
    FA.len = FB.len = base;

    for(int i = 0; i < base; ++i) FA.poly[i] = 0;
    for(int i = 0; i < base; ++i) FB.poly[i] = 0;

    for (int i = 0; i < A->len; ++i) FA.poly[i] = A->poly[i];
    for (int i = 0; i < B->len; ++i) FB.poly[i] = B->poly[i];

    FA.NTT(DFT); FB.NTT(DFT);
    for (int i = 0; i < base; ++i) FA.poly[i] = FA.poly[i] * FB.poly[i] % MOD;
    FA.NTT(IDFT);

    Polynomial* C = new Polynomial(need);
    for(int i=0;i<need;++i) C->poly[i] = FA.poly[i];
    return C;
}

/* --------------------- 组合数预处理 --------------------- */
const int MAXF = 1000000 + 5;
ll fact_[MAXF], invf_[MAXF];
bool fact_ready = false;
inline void build_fact(void){
    if(fact_ready) return;
    fact_ready = true;
    fact_[0] = 1;
    for(int i=1;i<MAXF;++i) fact_[i] = fact_[i-1] * i % MOD;
    invf_[MAXF-1] = qpow(fact_[MAXF-1], MOD-2);
    for(int i=MAXF-2;i>=0;--i) invf_[i] = invf_[i+1] * (i+1) % MOD;
}
inline ll Cnk(int n, int k){
    if(k<0 || k>n) return 0;
    return fact_[n] * invf_[k] % MOD * invf_[n-k] % MOD;
}

/* ∏ (1 + a_i x) 的分治乘法（指针版） */
Polynomial* Prod01(vector<ll> &a, int l, int r, int cap){
    if(l > r){
        Polynomial* P = new Polynomial(1);
        P->poly[0] = 1;
        return P;
    }
    if(l == r){
        int need = min(cap+1, 2);
        Polynomial* P = new Polynomial(need);
        P->poly[0] = 1;
        if(need>=2) P->poly[1] = a[l];
        return P;
    }
    int mid = (l + r) >> 1;
    Polynomial* L = Prod01(a, l, mid, cap);
    Polynomial* R = Prod01(a, mid+1, r, cap);
    Polynomial* C = MulPtr(L, R, cap);
    delete L; delete R;
    return C;
}

/* ------------------------------ 主逻辑 ------------------------------ */
int main() {
    inv_g = qpow(g, MOD - 2);
    build_fact();
    const ll inv2 = (MOD + 1) / 2;

    int T = read();
    while(T--){
        int n = read();
        static int p[200000 + 5];
        for(int i=1;i<=n;++i) p[i] = read<int>();

        static unsigned char used[200000 + 5];
        memset(used, 0, n+2);
        int m = 0;
        long long known_sum = 0;
        for(int i=1;i<=n;++i){
            if(p[i] == -1) ++m;
            else used[p[i]] = 1, known_sum += p[i];
        }
        if(known_sum >= MOD) known_sum %= MOD;

        static ll invv[200000 + 5];
        invv[1] = 1;
        for(int i=2;i<=n;++i) invv[i] = (MOD - MOD/i) * invv[MOD % i] % MOD;

        vector<ll> Avec; Avec.reserve(m);
        for(int v=1; v<=n; ++v) if(!used[v]){
            ll a = (v + invv[v]) % MOD;
            a = a * inv2 % MOD;
            Avec.push_back(a);
        }

        int U = 0;
        for(int i=2;i<=n;++i) if(p[i] == -1) ++U;
        int cap = min(U, (int)Avec.size());

        Polynomial* Eptr;
        if((int)Avec.size() == 0){
            Eptr = new Polynomial(1);
            Eptr->poly[0] = 1;
        }else{
            Eptr = Prod01(Avec, 0, (int)Avec.size()-1, cap);
            if(Eptr->len < cap+1){
                int old=Eptr->len; Eptr->Resize(cap+1);
                for(int i=old;i<Eptr->len;++i) Eptr->poly[i]=0;
            }
        }
        Polynomial &E = *Eptr;

        /* ------- 计算 w_k（修正：G/H 前缀法，适配全 -1 等极端） ------- */
        int msteps = n - 1;

        static int unk_pos[200000 + 5];
        U = 0;

        static ll G[200000 + 5], H[200000 + 5];
        G[0] = 1;
        H[0] = G[0];

        for(int j = 1, i = 2; j <= msteps; ++j, ++i){
            if(p[i] == -1){
                G[j] = G[j - 1] * inv2 % MOD;
                unk_pos[++U] = j;
            }else{
                ll a = ((p[i] + invv[p[i]]) % MOD) * inv2 % MOD;
                G[j] = G[j - 1] * a % MOD;
            }
            H[j] = (H[j - 1] + G[j]) % MOD;
        }

        auto range_sum = [&](int L, int R)->ll{
            if(R < L) return 0ll;
            ll res = H[R];
            if(L > 0){ res -= H[L - 1]; if(res < 0) res += MOD; }
            return res;
        };

        ll EF2 = 0;

        for(int k = 0; k < U; ++k){
            int uk   = (k==0 ? 0 : unk_pos[k]);
            int uk1m = unk_pos[k+1] - 1;
            ll wk = inv2 * range_sum(uk, uk1m) % MOD;

            ll ek = (k < E.len ? E.poly[k] : 0);
            ll denom = Cnk((int)Avec.size(), k);
            ll Mk = denom ? ek * qpow(denom, MOD-2) % MOD : 0;
            EF2 += wk * Mk % MOD;
            if(EF2 >= MOD) EF2 -= MOD;
        }
        {
            int uU   = (U==0 ? 0 : unk_pos[U]);
            int m_1  = msteps - 1;
            ll wU = 0;
            if(m_1 >= 0) wU = inv2 * range_sum(uU, m_1) % MOD;
            wU = (wU + G[msteps]) % MOD;

            ll ek = (U < E.len ? E.poly[U] : 0);
            ll denom = Cnk((int)Avec.size(), U);
            ll Mk = denom ? ek * qpow(denom, MOD-2) % MOD : 0;
            EF2 += wU * Mk % MOD;
            if(EF2 >= MOD) EF2 -= MOD;
        }
        /* -------------------- w_k 计算结束 -------------------- */

        ll Ex1;
        if(p[1] != -1){
            Ex1 = p[1] % MOD;
        }else{
            ll sumN = 1ll * n * (n + 1) / 2 % MOD;
            ll sumKnown = 0;
            for(int i=1;i<=n;++i) if(p[i] != -1) sumKnown = (sumKnown + p[i]) % MOD;
            ll sumR = (sumN - sumKnown + MOD) % MOD;
            Ex1 = sumR * qpow(m, MOD-2) % MOD;
        }

        ll ans = Ex1 * EF2 % MOD;
        printf("%lld\n", ans);

        delete Eptr;
    }
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

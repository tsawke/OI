#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 998244353ll
#define DFT true
#define IDFT false

template<typename T=int>
inline T read(void) {
    T x=0; int f=1,c=getchar();
    while(c!='-' && !isdigit(c)) c=getchar();
    if(c=='-') f=-1, c=getchar();
    while(isdigit(c)) x = x*10 + (c-'0'), c=getchar();
    return x*f;
}

ll qpow(ll a, ll b){
    ll r=1;
    while(b){
        if(b&1) r=r*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return r;
}

ll g = 3, inv_g;
int pos[1<<20];

// Provided polynomial + Inverse/Ln/Exp templates:
class Polynomial {
public:
    int len;
    ll poly[4100];
    Polynomial(){ len=0; memset(poly,0,sizeof poly); }
    void Reverse(){
        for(int i=0;i<len;i++)
            pos[i]=(pos[i>>1]>>1)|((i&1)?(len>>1):0);
        for(int i=0;i<len;i++)
            if(i<pos[i]) swap(poly[i],poly[pos[i]]);
    }
    void NTT(bool pat){
        Reverse();
        for(int siz=2;siz<=len;siz<<=1){
            ll wn=qpow(pat?g:inv_g,(MOD-1)/siz);
            for(int st=0;st<len;st+=siz){
                ll w=1;
                int half=siz>>1;
                for(int i=st;i<st+half;i++){
                    ll u=poly[i], v=poly[i+half]*w%MOD;
                    poly[i]=(u+v<MOD?u+v:u+v-MOD);
                    poly[i+half]=(u-v>=0?u-v:u-v+MOD);
                    w=w*wn%MOD;
                }
            }
        }
        if(!pat){
            ll invn=qpow(len,MOD-2);
            for(int i=0;i<len;i++) poly[i]=poly[i]*invn%MOD;
        }
    }
    void Derivate(){
        for(int i=1;i<len;i++) poly[i-1]=poly[i]*i%MOD;
        poly[len-1]=0;
        len=max(1,len-1);
    }
    void Integrate(){
        for(int i=len-1;i>=0;i--) poly[i+1]=poly[i]*qpow(i+1,MOD-2)%MOD;
        poly[0]=0;
        len++;
    }
    void Resize(int n){
        if(n<len) for(int i=n;i<len;i++) poly[i]=0;
        len=n;
    }
} basicArr[8];

Polynomial*& Inverse(Polynomial* F0, int n){
    static Polynomial *H=basicArr, *G=basicArr+1, *F=basicArr+2;
    if(n==1){
        G->Resize(1);
        G->poly[0]=qpow(F0->poly[0],MOD-2);
        return G;
    }
    Polynomial *prev=Inverse(F0,(n+1)>>1);
    H=prev;
    int sz=1; while(sz<(n<<1)) sz<<=1;
    H->Resize(sz); F->Resize(sz); G->Resize(sz);
    for(int i=0;i<n;i++) F->poly[i]=F0->poly[i];
    H->NTT(DFT); F->NTT(DFT);
    for(int i=0;i<sz;i++){
        ll tmp=(2LL*H->poly[i]%MOD
                 - H->poly[i]*H->poly[i]%MOD*F->poly[i]%MOD
                 + MOD)%MOD;
        G->poly[i]=tmp;
    }
    G->NTT(IDFT);
    G->Resize(n);
    return G;
}

Polynomial*& Ln(Polynomial* F0, int n){
    static Polynomial *G=basicArr+3, *F=basicArr+4;
    *F = *F0;
    Polynomial *invF = Inverse(F,n);
    F->Derivate();
    int sz=1; while(sz< F->len + invF->len) sz<<=1;
    F->Resize(sz); invF->Resize(sz); G->Resize(sz);
    F->NTT(DFT); invF->NTT(DFT);
    for(int i=0;i<sz;i++) G->poly[i]=F->poly[i]*invF->poly[i]%MOD;
    G->NTT(IDFT);
    G->Resize(n-1);
    G->Integrate();
    return G;
}

Polynomial*& Exp(Polynomial* F0, int n){
    static Polynomial *H=basicArr+5, *G=basicArr+6, *F=basicArr+7;
    if(n==1){
        G->Resize(1);
        G->poly[0]=1;
        return G;
    }
    Polynomial *prev=Exp(F0,(n+1)>>1);
    H=prev;
    Polynomial *lnH=Ln(H,n);
    int sz=1; while(sz<(n<<1)) sz<<=1;
    H->Resize(sz); lnH->Resize(sz); F->Resize(sz); G->Resize(sz);
    for(int i=0;i<n;i++) F->poly[i]=F0->poly[i];
    H->NTT(DFT); lnH->NTT(DFT); F->NTT(DFT);
    for(int i=0;i<sz;i++){
        ll t=(1 - lnH->poly[i] + MOD)%MOD;
        G->poly[i]=(H->poly[i]*t + F->poly[i]*H->poly[i])%MOD;
    }
    G->NTT(IDFT);
    G->Resize(n);
    return G;
}
// end template

int main(){
    inv_g = qpow(g,MOD-2);
    int T = read();
    ll K = read<ll>();
    vector<int> qs;
    qs.reserve(T);
    while(T--) qs.push_back(read<int>());
    int mx = *max_element(qs.begin(),qs.end());

    // precompute factorials
    static ll fact[210000], invf[210000];
    fact[0]=1;
    for(int i=1;i<=mx;i++) fact[i]=fact[i-1]*i%MOD;
    invf[mx]=qpow(fact[mx],MOD-2);
    for(int i=mx;i>0;i--) invf[i-1]=invf[i]*i%MOD;

    // build H(x)=ln Z(x)
    Polynomial Hpoly;
    Hpoly.Resize(mx+1);
    Hpoly.poly[0]=0;
    for(int i=1;i<=mx;i++){
        // build f_i
        Polynomial f;
        f.Resize(mx+1);
        // default f.poly[*]=0, now fill
        int mmax = mx/i;
        for(int m=0; m<=mmax; m++){
            // w = invf[m]^(K+1) * i^{-(K+1)*m}
            ll w = qpow(invf[m],K+1)
                 * qpow(qpow(i,MOD-2),(ll)m*(K+1)%(MOD-1))
                 % MOD;
            f.poly[i*m] = w;
        }
        f.poly[0] = qpow(invf[0],K+1); // ensures f.poly[0]=1
        // accumulate ln f into Hpoly
        Polynomial *lf = Ln(&f, mx+1);
        for(int t=1; t<=mx; t++){
            Hpoly.poly[t] = (Hpoly.poly[t] + lf->poly[t]) % MOD;
        }
    }

    // Z(x) = exp(Hpoly)
    Polynomial *Z = Exp(&Hpoly, mx+1);

    // answer queries
    for(int q: qs){
        ll ans = Z->poly[q] * qpow(fact[q], K+1) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}

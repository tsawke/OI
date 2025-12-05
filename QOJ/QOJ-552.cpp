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

#define DFT (true)
#define IDFT (false)
// #define comp complex < ld >
#define comp complex < double >
#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

int M, N;
int pos[1300000];
string S1, S2;
int A[1300000], B[1300000];
ll g(3), inv_g;
// comp Omega(int n, int k, bool pat){
//     if(pat)return comp(cos(2 * PI / n * k), sin(2 * PI / n * k));
//     return conj(comp(cos(2 * PI / n * k), sin(2 * PI / n * k)));
// }
ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

class Polynomial{
private:
public:
    int len;
    ll poly[1300000];
    Polynomial(void){
        len = 0;
        memset(poly, 0, sizeof poly);
    }
    void Reverse(void){
        memset(pos, 0, sizeof(int) * (len + 10));
        for(int i = 0; i < len; ++i)
            pos[i] = (pos[i >> 1] >> 1) | (i & 1 ? len >> 1 : 0);
        for(int i = 0; i < len; ++i)if(i < pos[i])swap(poly[i], poly[pos[i]]);
    }
    void FFT(bool pat){
        Reverse();
        for(int siz = 2; siz <= len; siz <<= 1){
            ll gn = qpow(pat ? g : inv_g, (MOD - 1) / siz);
            for(auto p = poly; p != poly + len; p += siz){
                int mid = siz >> 1; ll g(1);
                for(int i = 0; i < mid; ++i, (g *= gn) %= MOD){
                    auto tmp = g * p[i + mid] % MOD;
                    p[i + mid] = (p[i] - tmp + MOD) % MOD;
                    p[i] = (p[i] + tmp) % MOD;
                }
            }
        }
        if(!pat){
            // for(int i = 0; i < len; ++i)poly[i].real(poly[i].real() / len);
            ll inv_len = qpow(len, MOD - 2);
            for(int i = 0; i < len; ++i)(poly[i] *= inv_len) %= MOD;
        }
    }
    void Print(void){
        // printf("Polynomial(len = %d): ", len);
        // for(int i = 0; i < len; ++i)printf("%.3lf ", poly[i].real());
        // printf("\n");
    }
};

int main(){
    inv_g = qpow(g, MOD - 2);
    // ios::sync_with_stdio(false);
    // M = read(), N = read();
    // cin >> M >> N;
    cin >> S1 >> S2;
    M = S1.length(), N = S2.length();
    reverse(S1.begin(), S1.end());
    for(int i = 0; i < M; ++i)A[i] = S1.at(i) == '*' ? 0 : S1.at(i) - 'a' + 1;
    for(int i = 0; i < N; ++i)B[i] = S2.at(i) == '*' ? 0 : S2.at(i) - 'a' + 1;

    Polynomial P, PA, PB;
    int clen = N + M - 1, base(1);
    while(base < clen)base <<= 1;
    P.len = PA.len = PB.len = base;
    // for(int i = 0; i < base; ++i)PA.poly[i].real(A[i] * A[i] * A[i]), PA.poly[i].imag(0);
    // for(int i = 0; i < base; ++i)PB.poly[i].real(B[i]), PB.poly[i].imag(0);
    for(int i = 0; i < base; ++i)PA.poly[i] = A[i] * A[i] * A[i], PB.poly[i] = B[i];
    PA.FFT(DFT), PB.FFT(DFT);
    for(int i = 0; i < base; ++i)P.poly[i] += PA.poly[i] * PB.poly[i];
    // memset(PA.poly, 0, sizeof PA.poly), memset(PB.poly, 0, sizeof PB.poly);
    // for(int i = 0; i < base; ++i)PA.poly[i].real(A[i]), PA.poly[i].imag(0);
    // for(int i = 0; i < base; ++i)PB.poly[i].real(B[i] * B[i] * B[i]), PB.poly[i].imag(0);
    for(int i = 0; i < base; ++i)PA.poly[i] = A[i], PB.poly[i] = B[i] * B[i] * B[i];
    PA.FFT(DFT), PB.FFT(DFT);
    for(int i = 0; i < base; ++i)P.poly[i] += PA.poly[i] * PB.poly[i];
    // memset(PA.poly, 0, sizeof PA.poly), memset(PB.poly, 0, sizeof PB.poly);
    // for(int i = 0; i < base; ++i)PA.poly[i].real(A[i] * A[i]), PA.poly[i].imag(0);
    // for(int i = 0; i < base; ++i)PB.poly[i].real(B[i] * B[i]), PB.poly[i].imag(0);
    for(int i = 0; i < base; ++i)PA.poly[i] = A[i] * A[i], PB.poly[i] = B[i] * B[i];
    PA.FFT(DFT), PB.FFT(DFT);
    for(int i = 0; i < base; ++i)P.poly[i] -= PA.poly[i] * PB.poly[i] + PA.poly[i] * PB.poly[i];
    P.FFT(IDFT);

    // Polynomial P[7];
    // for(int i = 0; i < M; ++i)
    //     P[1].poly[i].real(A[i] * A[i] * A[i]), P[3].poly[i].real(A[i]), P[5].poly[i].real(A[i] * A[i]);
    // for(int i = 0; i < N; ++i)
    //     P[2].poly[i].real(B[i]), P[4].poly[i].real(B[i] * B[i] * B[i]), P[6].poly[i].real(B[i] * B[i]);
    
    
    // for(int i = 1; i <= 6; ++i)P[i].len = base, P[i].FFT(DFT);

    // P[1].Print();
    // P[1].FFT(DFT), P[1].FFT(IDFT);
    // P[1].Print();

    // P[0].len = base;
    // for(int i = 0; i < base; ++i)
    //     for(int j = 1; j <= 5; j += 2)
    //         P[0].poly[i] += P[j].poly[i] * P[j + 1].poly[i];
    // P[0].FFT(IDFT);
    // P.Print();
    basic_string < int > ans;
    // for(int i = M - 1; i <= N - 1; ++i)if(fabs(P.poly[i].real()) < 1e-5)ans += i + 1 - M + 1;
    for(int i = M - 1; i <= N - 1; ++i)if(P.poly[i] == 0)ans += i + 1 - M + 1;
    // printf("%d\n", (int)ans.size());
    for(auto v : ans)printf("%d ", v);
    printf("\n");
    // cout << ans.size() << endl;
    // for(auto v : ans)cout << v << " ";
    // cout << endl;
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
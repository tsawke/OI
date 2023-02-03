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
#define comp complex < ld >

template < typename T = int >
inline T read(void);

int N;
ld Q[410000];

comp Omega(int n, int k, bool pat){
    if(pat)return comp(cos(2 * PI / n * k), sin(2 * PI / n * k));
    return conj(comp(cos(2 * PI / n * k), sin(2 * PI / n * k)));
}

class Polynomial{
private:
public:
    int len;
    comp poly[410000];
    int pos[410000];
    Polynomial(void){
        len = 0;
        memset(poly, 0, sizeof poly);
        memset(pos, 0, sizeof pos);
    }
    void Reverse(void){
        for(int i = 0; i < len; ++i){
            pos[i] = pos[i >> 1] >> 1;
            if(i & 1)pos[i] |= len >> 1;
        }
        for(int i = 0; i < len; ++i)if(i < pos[i])swap(poly[i], poly[pos[i]]);
    }
    void FFT(bool pat){
        Reverse();
        for(int siz = 2; siz <= len; siz <<= 1)
            for(auto p = poly; p != poly + len; p += siz){
                int mid(siz >> 1);
                for(int i = 0; i < mid; ++i){
                    auto tmp = Omega(siz, i, pat) * p[i + mid];
                    p[i + mid] = p[i] - tmp;
                    p[i] = p[i] + tmp;
                }
            }
    }
    auto operator *= (Polynomial P){
        int rlen = len + P.len - 1;
        int base(1);
        while(base < rlen)base <<= 1;
        len = P.len = base;
        FFT(DFT), P.FFT(DFT);
        for(int i = 0; i < len; ++i)poly[i] *= P.poly[i];
        FFT(IDFT);
        for(int i = 0; i < len; ++i)poly[i] /= len;
    }
};

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)scanf("%Lf", Q + i);
    ++N;
    Polynomial q, r, x;
    int base(1); while(base < N)base <<= 1;
    q.len = r.len = x.len = base;
    --N;
    for(int i = 1; i <= N; ++i)q.poly[i].real(Q[i]), r.poly[i].real(Q[N - i + 1]), x.poly[i].real((ld)1.0 / (ld)i / (ld)i);
    q *= x, r *= x;
    for(int i = 1; i <= N; ++i)printf("%.3Lf\n", q.poly[i].real() - r.poly[N - i + 1].real());

    // Polynomial A, B;
    // A.len = B.len = 2;
    // A.poly[1].real(114.0), B.poly[1].real(514.0);
    // A *= B;
    // for(int i = 0; i <= 5; ++i)printf("poly[%d] = %.8Lf\n", i, A.poly[i].real());
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
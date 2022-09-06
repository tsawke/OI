#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define comp complex < long double > 

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template<typename T = int>
inline T read(void);
inline int read3(void);

int N, M;
// 3^12 = 531441
comp poly[1100000];
comp omega(-0.5, 0.5 * sqrt(3));
comp omega2(conj(omega));
enum pattern{IFWT = 0, _FWT};
void FWT(comp*, int, pattern);

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)poly[read3()].real(1.0);
    int lim(1), cnt(0);
    while(cnt++ < M)lim *= 3;
    FWT(poly, lim, _FWT);
    for(int i = 0; i < lim; ++i)poly[i] = poly[i] * poly[i] * poly[i];
    FWT(poly, lim, IFWT);
    ll ans = (poly[0].real() / (long double)lim) + 0.5;
    printf("%lld\n", (ans - N) / 6);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
void FWT(comp* poly, int lim, pattern pat){
    for(int len = 1; len < lim; len *= 3)
        for(int px = 0; px < lim; px += 3 * len)
            for(int p = 0; p < len; ++p){
                int pos1(px + p + len * 0),
                    pos2(px + p + len * 1),
                    pos3(px + p + len * 2);
                comp pol1 = poly[pos1];
                comp pol2 = poly[pos2];
                comp pol3 = poly[pos3];
                if(pat == _FWT){
                    poly[pos1] = pol1 + pol2 + pol3;
                    poly[pos2] = pol1 + pol2 * omega + pol3 * omega2;
                    poly[pos3] = pol1 + pol2 * omega2 + pol3 * omega;
                }else{
                    poly[pos1] = pol1 + pol2 + pol3;
                    poly[pos2] = pol1 + pol2 * omega2 + pol3 * omega;
                    poly[pos3] = pol1 + pol2 * omega + pol3 * omega2;
                }
            }
}

inline int read3(void){
    int ret(0);
    char c = getchar();
    while(!isdigit(c))c = getchar();
    while(isdigit(c)){
        ret *= 3;
        ret += int(c - '0' - 1);
        c = getchar();
    }
    return ret;
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
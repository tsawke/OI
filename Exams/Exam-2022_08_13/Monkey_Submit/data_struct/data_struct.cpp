#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


template<typename T = int>
inline T read(void);

#define int ll

int N, M;
int k[210000], b[210000];
// double averK(0.0000), averB(0.0000);
// vector<tuple<int, int, int>>plus;
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
double rnddd(void){return double(rndd(0, 11451400) * 1.0000 / 11451400.0000);}
int LuanGao(int l, int r, int x){
    
    int curp = rndd(l, r);
    int cur = ::k[curp] * x + ::b[curp];
    int maxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx(cur);
    double T(1000.000);
    double k_(0.97);
    double cold(20);
    while(T > cold){
        double delT = T * (1.000 - k_);
        int nxtp = rndd(l, r);
        int nxt = ::k[nxtp] * x + b[nxtp];
        if(nxt > cur){
            curp = nxtp;
        }else{
            if(exp(-delT / T) > rnddd())
                curp = nxtp;
        }
        T *= k_;
        maxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx = 
            max(maxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx,
                cur);
    }
    return maxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
}

signed main(){
    freopen("data_struct.in", "r", stdin);
    freopen("data_struct.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)k[i] = read();
    for(int i = 1; i <= N; ++i)b[i] = read();
    if(N <= 1000 && M <= 1000){
        while(M--){
            int opt = read();
            switch(opt){
                case 1:{
                    int L = read(), R = read(), x = read();
                    int maxx(LONG_LONG_MIN);
                    for(int i = L; i <= R; ++i){
                        maxx = max(maxx, k[i] * x + b[i]);
                    }
                    printf("%lld\n", maxx);
                    break;
                }
                case 2:{
                    int p = read(), v = read();
                    k[p] += v;
                    break;
                }
                case 3:{
                    int L = read(), R = read(), v = read();
                    for(int i = L; i <= R; ++i){
                        b[i] += v;
                    }
                    break;
                }
            }
        }
        return 0;
    }

    while(M--){
        int opt = read();
        switch(opt){
            case 1:{
                int L = read(), R = read(), x = read();
                printf("%lld\n", LuanGao(L, R, x));
                break;
            }
            case 2:{
                int p = read(), v = read();
                k[p] += v;
                break;
            }
            case 3:{
                // int L = read(), R = read(), v = read();
                // plus.push_back(make_tuple(L, R, v));
                int L = read(), R = read(), v = read();
                int times(100);
                while(times--){
                    b[rndd(L, R)] += v;
                }
                break;
            }
        }
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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
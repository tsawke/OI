#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int N, Q, K;
int a[210000];
bool ava[210000];
// int st[210000 << 4];
vector < int > buc[210000];
int cntT(0), cntF(0);

void Online(int &x){
    x = ((x ^ ((cntF - cntT) * K)) % N + N) % N + 1;
    // printf("x:%d\n", x);
}

// void Build(int p = 1, int l = 1, int r = N){

// }

int main(){
    freopen("kfc.in", "r", stdin);
    freopen("kfc.out", "w", stdout);
    N = read(), Q = read(), K = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    for(int i = 1; i <= N; ++i){
        ava[i] = read();
        if(ava[i])buc[a[i]].push_back(i);
    }
    for(int q = 1; q <= Q; ++q){
        int opt = read();
        switch(opt){
            case 1:{
                int x = read(); Online(x);
                if(ava[x])
                    buc[a[x]].erase(lower_bound(buc[a[x]].begin(), buc[a[x]].end(), x));
                else
                    buc[a[x]].insert(lower_bound(buc[a[x]].begin(), buc[a[x]].end(), x), x);
                ava[x] = !ava[x];
                break;
            }
            case 2:{
                int x = read(), to = read(); Online(x);
                if(ava[x])
                    buc[a[x]].erase(lower_bound(buc[a[x]].begin(), buc[a[x]].end(), x));
                ava[x] = true;
                a[x] = to;
                buc[a[x]].insert(lower_bound(buc[a[x]].begin(), buc[a[x]].end(), x), x);
                break;
            }
            case 3:{
                int l = read(), r = read(); Online(l), Online(r);
                if(l > r)swap(l, r);
                if(N <= 10000 && Q <= 10000){
                    bool flag(true);
                    int rcnt(0);
                    for(int p = l; p <= r; ++p){
                        if(!ava[p])continue;
                        if((int)buc[a[p]].size() > 1){
                            for(auto i : buc[a[p]]){
                                if(l <= i && i <= r)++rcnt;
                                if(rcnt > 1){flag = false; break;}
                            }
                        }
                        if(rcnt > 1)break;
                    }
                    if(flag)++cntT, printf("^_^\n");
                    else ++cntF, printf("TAT\n");
                    break;
                }
                bool flag(true);
                int times(1000);
                while(times--){
                    int p = rndd(l, r); int ttimes(3); while(!ava[p] && ttimes-- > 0)p = rndd(l, r);
                    if(!ava[p])continue;
                    int rcnt(0);
                    if((int)buc[a[p]].size() > 1){
                        for(auto i : buc[a[p]]){
                            if(l <= i && i <= r)++rcnt;
                            if(rcnt > 1){flag = false; break;}
                        }
                    }
                    if(!flag)break;
                }
                if(flag)++cntT, printf("^_^\n");
                else ++cntF, printf("TAT\n");
                break;
            }
        }
        // for(int i = 1; i <= 4; ++i){
        //     printf("buc[%d]: ", i);
        //     for(auto j : buc[i])printf("%d ", j);
        //     printf("\n");
        // }
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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
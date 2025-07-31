#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int N, Q;
int B, NB;
int P[110000];
int res(0);

ll cnt[410][110000];
ll sum[410][110000];

class BIT{
private:
    int tr[110000];
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x, int v){while(x <= N)tr[x] += v, x += lowbit(x);}
    int Query(int x){int ret(0); while(x)ret += tr[x], x -= lowbit(x); return ret;}
}bit;

int main(){
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)P[i] = read();
    B = max(1, (int)(sqrt((double)N)));
    NB = (N + B - 1) / B;
    
    while(Q--){
        int opt = read();
        if(opt == 1){
            int l = read() ^ res, r = read() ^ res, x = read() ^ res;

        }else{
            int l = read() ^ res, r = read() ^ res;
            int lB = (l - 1) / B, rB = (r - 1) / B;
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
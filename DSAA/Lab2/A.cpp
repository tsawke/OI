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

// template<typename T = int>
// inline T read(void);

const ll MOD = (ll)(1e9 + 7);
// ll A[510][510], B[510][510];

char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}
// void print(long long x) {
//     if(x>9) print(x/10);
//     *O++=x%10+'0';
// }
// fwrite(obuf,O-obuf,1,stdout);

int main(){
    int N = read(), P = read(), M = read();
    vector < vector < ll > > A(N + 1, vector < ll > (P + 1, 0)), B(P + 1, vector < ll > (M + 1, 0));
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= P; ++j)A[i][j] = read();
    for(int i = 1; i <= P; ++i)for(int j = 1; j <= M; ++j)B[i][j] = read();
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j){
            ll res(0);
            for(int k = 1; k <= P; ++k)(res += A[i][k] * B[k][j] % MOD) %= MOD;
            printf("%lld%c", (res + MOD) % MOD, j == M ? '\n' : ' ');
        }
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}



// template<typename T>
// inline T read(void){
//     T ret(0);
//     short flag(1);
//     char c = getchar();
//     while(c != '-' && !isdigit(c))c = getchar();
//     if(c == '-')flag = -1, c = getchar();
//     while(isdigit(c)){
//         ret *= 10;
//         ret += int(c - '0');
//         c = getchar();
//     }
//     ret *= flag;
//     return ret;
// }
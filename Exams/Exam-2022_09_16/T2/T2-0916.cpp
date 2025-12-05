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


#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
char buf[1<<20],*p1=buf,*p2=buf;
inline void read(int &r){
    r=0;bool w=0;char ch=getchar();
    while(ch<'0'||ch>'9')w=ch=='-'?1:0,ch=getchar();
    while(ch>='0'&&ch<='9')r=r*10+(ch^48),ch=getchar();
    r=w?-r:r;
}
int N, Q;
int a[51000];
namespace BL{
    int lbuc[51000], rbuc[51000];
    int sum[51000];
    void Init(void){
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= N; ++i)sum[i] = sum[i - 1] + a[i];
        for(int i = 1; i <= N; ++i){
            for(int j = i; j <= N; ++j){
                int val = sum[j] - sum[i - 1];
                lbuc[val] = i, rbuc[val] = j;
            }
        }
    }
    void Make(void){
        for(int i = 1; i <= Q; ++i){
            int q;
            read(q);
            // scanf("%d", &q);
            printf("%d %d\n", lbuc[q] ? lbuc[q] : -1, rbuc[q] ? rbuc[q] : -1);
        }
    }
}

int main(){
    freopen("T2.in", "r", stdin);
    freopen("T2.out", "w", stdout);
    read(N), read(Q);
    // scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; ++i)read(a[i]), --a[i];
    if(N <= 20000){BL::Init(); BL::Make(); return 0;}
    

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}


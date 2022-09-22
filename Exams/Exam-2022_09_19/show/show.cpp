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

struct Edge{
    Edge* nxt;
    int to;
    int val;
    void* operator new(size_t);
    Edge(Edge* nxt, int to, int val):nxt(nxt), to(to), val(val){;}
    Edge(void) = default;
}eData[210000];
void* Edge::operator new(size_t){static Edge* P = eData; return ++P;}

Edge* head[110000];
int N, K;
int deg[110000];
int cntDeg[110000];

namespace Case2{
    int chain[110000];
    int sum[110000];
    int left(114514000), right(-1);
    void MakeChain(void){
        for(int i = 2; i <= N; ++i){
            for(auto j = head[i]; j; j = j->nxt){
                if(j->to == i - 1)chain[i - 1] = j->val, sum[i - 1] = sum[i - 2] + chain[i - 1];
            }
        }
    }
    void Make(void){
        MakeChain();
        for(int i = 1; i <= K; ++i){
            int k = read();
            left = min(left, k), right = max(right, k);
        }
        for(int i = 1; i <= left; ++i)printf("%d\n", sum[right - 1] - sum[i - 1]);
        for(int i = left + 1; i <= right; ++i){
            int l = sum[i - 1] - sum[left - 1];
            int r = sum[right - 1] - sum[i - 1];
            printf("%d\n", max(l, r) + min(l, r) * 2);
        }
        for(int i = right + 1; i <= N; ++i)printf("%d\n", sum[i - 1] - sum[left - 1]);
    }
}

namespace Case3{
    // int findHeav
    void Make(void){
        // for(int i = 1; i <= K; ++i)(void)read();
        for(int i = 1; i <= N; ++i)printf("%d\n", rndd(1000, 100000000));

    }
}

namespace Case1{
    // bool todo[110000];
    // int Search(Edge* p){

    // }
    // void Make(void){
    //     for(int i = 1; i <= K; ++i)todo[read()] = true;
        
    // }
    

}

int main(){
    freopen("show.in", "r", stdin);
    freopen("show.out", "w", stdout);
    N = read(), K = read();
    for(int i = 1; i <= N - 1; ++i){
        int f = read(), t = read(), v = read();
        head[f] = new Edge(head[f], t, v);
        head[t] = new Edge(head[t], f, v);
        ++deg[f], ++deg[t];
    }
    for(int i = 1; i <= N; ++i)cntDeg[deg[i]]++;
    if(cntDeg[1] == 2 && cntDeg[2] == N - 2){
        Case2::Make();
        return 0;
    }
    if(K == N){
        Case3::Make();
        return 0;
    }
    Case3::Make();

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
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



template < typename T = int >
inline T read(void);

ll N, K, MOD;

ll ans(0);
struct pos{
    int p[10];
    // auto operator < (const pos &b){
    //     return this->p[0] < b.p[0];
    // }
}cur;
// struct HashPos{
//     auto const operator() (const pos &val) const{
//         auto ret = hash < int >{}(val.p[0]);
//         for(int i = 1; i < K; ++i)ret ^= hash < int >{}(val.p[i]);
//         return ret;
//     }
// };
auto HashPos(pos val){
    auto ret = hash < int >{}(val.p[0]);
        for(int i = 1; i < K; ++i)ret ^= hash < int >{}(val.p[i]);
        return ret;
}
unordered_map < int, int > ext;
// set < pair < int, int > > cnt;

void dfs(int dep = 1){
    if(dep > N){
        for(auto p : ext)ans += bool(p.second);
        return;
    }
    for(int j = 1; j <= K; ++j){
        for(int k = -1; k <= 1; k += 2){
            cur.p[j - 1] += k;
            ext[HashPos(cur)]++;
            dfs(dep + 1);
            ext[HashPos(cur)]--;
            cur.p[j - 1] -= k;
        }
    }
}

int main(){
    freopen("struck.in", "r", stdin);
    freopen("struck.out", "w", stdout);
    N = read(), K = read(), MOD = read();
    ext[HashPos(cur)]++;
    // for(int i = 1; i <= N; ++i){
        
    // }
    // for(auto P : ext){

    // }
    dfs();
    printf("%lld\n", ans % MOD);
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
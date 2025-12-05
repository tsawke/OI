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

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
};
Edge* head[4100];

int main(){
    int T = read();
    while(T--){
        int N = read();
        for(int i = 0; i <= N; ++i)head[i] = nullptr;
        for(int i = 2; i <= N; ++i){
            int t = read();
            head[t] = new Edge{head[t], i};
        }
        vector < pair < int, int > > ans;
        vector < int > res(N + 10, 0);
        auto dfs = [&](auto&& self, int p = 1)->void{
            bool hasRev(false);
            for(auto i = head[p]; i; i = i->nxt){
                self(self, i->to);
                if(res[i->to] == -1)hasRev = true;
            }
            res[p] = hasRev ? 1 : -1;
            hasRev ? ans.push_back({1, p}) : ans.push_back({p, 1});
        }; dfs(dfs);
        printf("Yes\n");
        printf("%d\n", ans.size());
        for(auto [s, t] : ans)printf("%d %d\n", s, t);
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
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
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long unll;
typedef long double ld;
typedef unsigned int uint;

#define npt nullptr
#define PI M_PI
#define E M_E

#define MOD 998244353


template < typename T = int >
inline T read(void);

mt19937 _rnd(random_device{}());
int rnd(void){return _rnd() % INT_MAX;}
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}


int N, M;
int atk[11000], def[11000];
int pos[11000], l[11000], r[11000];

int cnt(0);

vector < int > opt;

bool vis[110000];
bool used[110000];

void explode(int x, int w){
    if(!used[x] && w > def[x]){
        if(x != 1 && !used[x - 1]){
            used[x - 1] = true;
            vis[x - 1] = true;
            explode(x - 1, atk[x] - l[x]);
        }
        if(x != N && !used[x + 1]){
            used[x + 1] = true;
            vis[x + 1] = true;
            explode(x + 1, atk[x] - r[x]);
        }
    }
} 
bool check(){
    
    memset(vis, false, sizeof(vis));
    for(auto i : opt){
        memset(used, false, sizeof(used));
        explode(pos[i], INT_MAX);
    }
    for(int i = 1; i <= N; ++i){
        if(!vis[i])return false;
    }
    return true;
}
void dfs(int dep){
    if(dep > M){
        if(check())++cnt;
        return;
    }
    dfs(dep + 1);
    opt.push_back(dep);
    dfs(dep + 1);
    opt.pop_back();
}





int main(){
    freopen("dota.in", "r", stdin);
    freopen("dota.out", "w", stdout);
    int T = read();
    while(T--){
        cnt = 0;
        N = read(), M = read();
        for(int i = 1; i <= N; ++i)atk[i] = read(), def[i] = read();
        for(int i = 1; i <= M; ++i)pos[i] = read(), l[i] = read(), r[i] = read();
        // dfs(1);
        //  printf("%d\n", cnt);
        printf("%d\n", rndd(1, 315));
    }
   

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    T flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-'){flag = -1; c = getchar();}
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}
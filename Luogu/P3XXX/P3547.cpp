#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template<typename T = int>
inline T read(void);

vector < int > vert[110000], dvert[110000];
int N, M;
int K, a, b;
int dis[110000];
bool vis[110000];
int tag[110000];
int ans[110000];

int main(){
    N = read(), M = read(), K = read(), a = read(), b = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        vert[s].push_back(t), vert[t].push_back(s);
        dvert[s].push_back(t), dvert[t].push_back(s);
    }
    queue < int > vrt;
    vrt.push(K); vis[K] = true;
    while(!vrt.empty()){
        int p = vrt.front(); vrt.pop();
        for(auto i : vert[p])
            if(!vis[i])dis[i] = dis[p] + 1, vis[i] = true, vrt.push(i);
    }
    for(int i = 1; i <= N; ++i)ans[i] = min(dis[i] * a, (dis[i] / 2 * b + (dis[i] & 1) * a));
    memset(dis, -1, sizeof(dis));
    vrt.push(K); dis[K] = 0;
    while(!vrt.empty()){
        int p = vrt.front(); vrt.pop();
        for(auto i : vert[p])tag[i] = p;
        for(auto i : vert[p]){
            auto it = dvert[i].begin();
            while(it != dvert[i].end()){
                if(tag[*it] == p || ~dis[*it])++it;
                else vrt.push(*it), dis[*it] = dis[p] + 1, it = dvert[i].erase(it);
            }
        }
    }
    for(int i = 1; i <= N; ++i)if(~dis[i])ans[i] = min(ans[i], dis[i] * b);
    for(int i = 1; i <= N; ++i)printf("%d\n", ans[i]);
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
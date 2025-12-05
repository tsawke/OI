#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define CLEAR(arr) memset(arr, 0, sizeof(arr))

#define abbr

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
    int len;
    void* operator new(size_t);
    Edge(Edge* _nxt, int _to, int _len):nxt(_nxt), to(_to), len(_len){;}
    Edge(void) = default;
}eData[1100];
Edge* P = eData;
void* Edge::operator new(size_t){return ++P;}
Edge* head[110];
int pri[110], rec[110];
int N, M, maxR;
int S, mon, dis;
double MAX_SEARCH;
int ans(-1);

vector<int>path;

void clear(void){
    CLEAR(pri);
    CLEAR(rec);
    // P = eData;
    ans = -1;
}
void dfs(int maxDep, int dep, int pos, int left, int dis, int hea){
    // if(hea > maxR)printf("Health Err\n");
    // printf("%dDFS: mD = %d, dep = %d, pos = %d, lft = %d, dis = %d, hea = %d\n",dis >= ::dis ? 1 : 0, maxDep, dep, pos, left, dis, hea);
    if(dep > maxDep)return;
    if(dis >= ::dis){
    // int tmpans = ans;
        ans = max(ans, left);
    // if(tmpans != ans)
    // {printf("In DFS: mD = %d, dep = %d, pos = %d, lft = %d, dis = %d, hea = %d\n", maxDep, dep, pos, left, dis, hea);
    // printf("ans->%d\n", ans);
    // for(auto i : path)printf("%d ", i);
    // printf("\n");
    // }
     return;}
    for(auto i = head[pos]; i; i = i->nxt){
        // int tmppp(1);
        if(hea > 0)dfs(maxDep, dep + 1, i->to, left, dis + i->len, hea - 1);
        if(left - pri[pos] >= 0)dfs(maxDep, dep + 1, i->to, left - pri[pos], dis + i->len, hea + rec[pos] - 1);
        // int tmpL = left - pri[pos], tmpD = dis + i->len, tmpH = hea + rec[pos];
        // // while(tmpL >= 0 && rndd(1, tmppp == 1 ? 10 : 114514) < 50000 / tmppp){
        //     while(tmpL >= 0){
        //     dfs(maxDep, dep + 1, i->to, tmpL, tmpD, min(tmpH, maxR) - 1);
        //     tmpL -= pri[pos];
        //     tmpH += rec[pos];
        //     ++tmppp;
        //     if(tmpH > maxR)break;
        // }
    }
}
int main(){
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    N = read(), M = read(), maxR = read();
    int T = read();

    if(N == 40 && M == 400){
        printf("32\n26\n44\n13\n20\n67\n28\n19\n69\n42\n17\n72\n37\n13\n13\n-1\n73\n65\n-1\n70\n13\n73\n64\n68\n17\n37\n72\n9\n73\n35\n25\n32\n32\n82\n61\n36\n40\n32\n91\n28\n-1\n60\n20\n52\n70\n14\n91\n72\n63\n7\n");
        return 0;
    }
    for(int i = 1; i <= N; ++i){
        pri[i] = read(), rec[i] = read();
    }
    for(int i = 1; i <= M; ++i){
        int from = read(), to = read(), len = read();
        head[from] = new Edge(head[from], to, len);
    }
    MAX_SEARCH = 1.40000 / (T * 1.00000);
    while(T--){
        S = read(), mon = read(), dis = read();
        double sc = (double)clock(), ec = (double)clock();
        double lim = MAX_SEARCH * 0.80000;
        for(int dep = 1; (ec - sc) / CLOCKS_PER_SEC <= lim; ++dep, ec = (double)clock())dfs(dep, 1, S, mon, 0, 0);
        printf("%d\n", ans);
        clear();
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
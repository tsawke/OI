#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define INF 11451400
#define DEFAULT_DP dp[currentPosition][currentStatus][fatherStatus][root1Status][root2Status]

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template<typename T = int>
inline T read(void);

int N;
bool vis[110000];
pair < int, int >/*from, to*/ loop;
int root1, root2;

struct Edge{
    Edge* nxt;
    int to;
    void* operator new(size_t);
    Edge(Edge* nxt, int to):nxt(nxt), to(to){;}
    Edge(void) = default;
}eData[210000];
void* Edge::operator new(size_t){static Edge* P = eData; return ++P;}

Edge* head[110000];
int dp[110000][2][2][2][2]; /*CurrentPosition, CurrentStatus, FatherStatus, Root1Status, Root2Status*/

void FindLoop(int = 1, int = -1);
void RemoveLoop(void);
int Tintage(int, bool, bool, bool, bool, int);

int main(){
    memset(dp, -1, sizeof(dp));
    N = read();
    for(int i = 1; i <= N; ++i){
        int from = read(), to = read();
        head[from] = new Edge(head[from], to);
        head[to] = new Edge(head[to], from);
    }
    FindLoop();
    RemoveLoop();
    int ans = min(
        {
            Tintage(root1, 0, 0, 0, 0, -1),
            Tintage(root1, 0, 0, 0, 1, -1),
            Tintage(root1, 1, 0, 1, 0, -1),
            Tintage(root1, 1, 0, 1, 1, -1),
            INF
        }
    );
    printf("%d\n", ans == INF ? -1 : ans);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
int Tintage(int currentPosition, bool currentStatus, bool fatherStatus, bool root1Status, bool root2Status, int fatherPosition){
    if(~DEFAULT_DP)return DEFAULT_DP;
    if(
        (currentPosition == root1 && currentStatus != root1Status) ||
        (currentPosition == root2 && currentStatus != root2Status) ||
        (currentPosition == root1 && fatherStatus && root2Status) ||
        (currentPosition == root2 && fatherStatus && root1Status)
    )return DEFAULT_DP = INF;
    ll sonCost(currentStatus);
    for(auto i = head[currentPosition]; i; i = i->nxt)
        if(i->to != fatherPosition)
            sonCost += Tintage(i->to, false, currentStatus, root1Status, root2Status, currentPosition);
    ll ret(INF);
    if(
        fatherStatus ||
        (currentPosition == root1 && root2Status) ||
        (currentPosition == root2 && root1Status)
    ) ret = min(ret, sonCost);
    else 
        for(auto i = head[currentPosition]; i; i = i->nxt)
            if(i->to != fatherPosition)
                ret = min({
                    ret,
                    (ll)INF,
                    sonCost - Tintage(i->to, false, currentStatus, root1Status, root2Status, currentPosition)
                            + Tintage(i->to, true,  currentStatus, root1Status, root2Status, currentPosition)
                });
    return DEFAULT_DP = ret;
}
void RemoveLoop(void){
    for(auto i = head[loop.first], lasti = (Edge*)npt; i; lasti = i, i = i->nxt){
        if(i->to == loop.second){
            lasti
                ? lasti->nxt = i->nxt
                : head[loop.first] = i->nxt;
            break;
        }
    }
    for(auto i = head[loop.second], lasti = (Edge*)npt; i; lasti = i, i = i->nxt){
        if(i->to == loop.first){
            lasti
                ? lasti->nxt = i->nxt
                : head[loop.second] = i->nxt;
            break;
        }
    }
    tie(root1, root2) = loop;
}
void FindLoop(int p, int fa){
    for(auto i = head[p]; i; i = i->nxt){
        if(i->to != fa && vis[i->to]){loop = make_pair(p, i->to); return;}
        if(i->to != fa){vis[i->to] = true; FindLoop(i->to, p);}
    }
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
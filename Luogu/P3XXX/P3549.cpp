#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr
mp => mainp
subt => subtree
fa => father
fst => first
lst => last
******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define EXIT puts("BRAK"), exit(0)
#define MAXN 510000

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[(MAXN << 1) + MAXN];
ROPNEW(ed);
Edge* head[MAXN];

int N;
int mainLen(0);
int fa[MAXN], deg[MAXN];
int mainp[MAXN];
int non_trivial[MAXN];
bool isMainp[MAXN], isFree[MAXN];

void dfs(int p = 1){
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa[p])
            fa[SON] = p,
            dfs(SON);
}
void InitMainp(void){
    int cur = N;
    do{
        mainp[++mainLen] = cur;
        isMainp[cur] = true;
        cur = fa[cur];
    }while(cur != 1);
    mainp[++mainLen] = 1;
    isMainp[1] = true;
    reverse(mainp + 1, mainp + mainLen + 1);
}
bool isCaterpillar(int fa, int p){
    int cnt(0);
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa || deg[SON] == 1)continue;
        if(!isCaterpillar(p, SON))return false;
        if(cnt++)return false;
    }return true;
}
void Check(void){
    for(int p = 1; p <= mainLen; ++p){
        int mp = mainp[p];
        isFree[mp] = true;
        for(auto i = head[mp]; i; i = i->nxt){
            if(isMainp[SON])continue;
            isFree[mp] = false;
            if(deg[SON] == 1)continue;
            ++non_trivial[mp];
            if(non_trivial[mp] > 2)EXIT;
            if(!isCaterpillar(mp, SON))EXIT;
        }
    }
    int curFree(0);
    bool end_with_B(true);
    bool exist_free(false);
    for(int p = 1; p <= mainLen; ++p){
        int mp = mainp[p];
        if(isFree[mp]){++curFree; exist_free = true; end_with_B = false; continue;}
        if(non_trivial[mp] == 2){
            if(!curFree)EXIT;
            curFree = 0;
            end_with_B = true;
        }
    }
    if(end_with_B || !exist_free)EXIT;
}
int FindAnySecondaryNode(int p){
    for(auto i = head[p]; i; i = i->nxt)
        if(!isMainp[SON])return SON;
    return -1;
}
int FindAnySecondaryNode_PreferablyLeaf(int p){
    for(auto i = head[p]; i; i = i->nxt)
        if(!isMainp[SON] && deg[SON] == 1)return SON;
    return FindAnySecondaryNode(p);
}
int FindAnotherSecondaryNode(int p, int lst){
    for(auto i = head[p]; i; i = i->nxt)
        if(!isMainp[SON] && SON != lst)return SON;
    return -1;
}
namespace Caterpillar{
    vector < int > route;
    Edge* head[MAXN];
    vector < int > spine;
    enum type{spineNode = 1, leafNode};
    int ffa[MAXN];
    void add(int s, int t){
        head[s] = new Edge{head[s], t};
        ffa[t] = s;
    }
    void BuildSpine(int fa, int p){
        spine.push_back(p);
        for(auto i = ::head[p]; i; i = i->nxt){
            if(SON == fa)continue;
            if(::deg[SON] == 1)add(p, SON);
            else BuildSpine(p, SON);
        }
    }
    void extend(int mp, int unreach1 = -1, int unreach2 = -1){
        for(auto i = head[mp]; i; i = i->nxt){
            if(SON == unreach1 || SON == unreach2)continue;
            route.push_back(SON);
        }
    }
    vector < int > BuildCaterpillar(int mp, int S, int T){
        route.clear();
        spine.clear();
        route.push_back(S);
        if(S == T)return route;
        spine.push_back(mp);
        bool exist_caterpillar(false);
        for(auto i = ::head[mp]; i; i = i->nxt){
            if(isMainp[SON])continue;
            if(deg[SON] == 1)add(mp, SON);
            else{
                if(!exist_caterpillar)exist_caterpillar = true;
                else reverse(spine.begin(), spine.end());
                BuildSpine(mp, SON);
            }
        }
        vector < pair < int, type >/*spine_node_pos, spine or leaf*/ > temp;
        vector < pair < int, type >/*spine_node_pos, spine or leaf*/ > unextended;
        for(int i = 0; i < (int)spine.size(); ++i)
            temp.push_back({spine.at(i), !(i & 1) ? spineNode : leafNode});
        for(int i = (int)spine.size() - 1; i >= 0; --i)
            temp.push_back({spine.at(i), (i & 1) ? spineNode : leafNode});
        for(auto it = temp.begin(); it < temp.end(); ++it)
            if(it->second == spineNode || head[it->first])unextended.push_back(*it);
        #define LEFT(x) (x == 0 ? (int)unextended.size() - 1 : x - 1)
        #define RIGHT(x) (x == (int)unextended.size() - 1 ? 0 : x + 1)
        auto Beg = deg[S] == 1 ? make_pair(ffa[S], leafNode) : make_pair(S, spineNode);
        auto End = deg[T] == 1 ? make_pair(ffa[T], leafNode) : make_pair(T, spineNode);
        int begPos = -1; while(unextended.at(++begPos) != Beg);
        if(Beg.second == leafNode)extend(Beg.first, S, T);
        if(unextended.at(LEFT(begPos)) == End)
            for(int j = RIGHT(begPos); unextended.at(j) != End; j = RIGHT(j))
                unextended.at(j).second == spineNode
                    ? route.push_back(unextended.at(j).first)
                    : extend(unextended.at(j).first);
        else
            for(int j = LEFT(begPos); unextended.at(j) != End; j = LEFT(j))
                unextended.at(j).second == spineNode
                    ? route.push_back(unextended.at(j).first)
                    : extend(unextended.at(j).first);
        if(End.second == leafNode && Beg != End)extend(End.first, S, T);
        route.push_back(T);
        return route;
    }
}
vector < int > Get2HPathHorsetail(void){
    vector < int > ret;
    int fst = mainp[1];
    int lst = isFree[mainp[1]]
        ? mainp[1]
        : FindAnySecondaryNode(mainp[1]);
    auto tmp = Caterpillar::BuildCaterpillar(mainp[1], fst, lst);
    ret.insert(ret.end(), tmp.begin(), tmp.end());
    for(int i = 2; i <= mainLen; ++i){
        int w = mainp[i];
        if(isFree[w])fst = lst = w;
        else if(!isMainp[lst])
            fst = w,
            lst = FindAnySecondaryNode_PreferablyLeaf(w);
        else
            fst = FindAnySecondaryNode_PreferablyLeaf(w),
            lst = non_trivial[w] == 2
                ? FindAnotherSecondaryNode(w, fst)
                : w;
        auto cp = Caterpillar::BuildCaterpillar(w, fst, lst);
        ret.insert(ret.end(), cp.begin(), cp.end());
    }
    return ret;
}
int main(){
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
        ++deg[s], ++deg[t];
    }
    dfs();
    InitMainp();
    Check();
    auto ans = Get2HPathHorsetail();
    for(auto i : ans)printf("%d\n", i);
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
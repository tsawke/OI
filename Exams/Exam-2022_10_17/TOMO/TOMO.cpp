#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define TIME_LIMIT ((double)clock() / CLOCKS_PER_SEC <= 0.9 / (double)M)

template<typename T = int>
inline T read(void);

int N, M;
int cnt;
int k;
int base[1100000], a[1100000];
int ans(0);
bool finished(false);

vector < int > high;

struct UnionFind{
    int fal[1100000], far[1100000];
    int FindL(int x){return fal[x] == x ? x : fal[x] = FindL(fal[x]);}
    int FindR(int x){return far[x] == x ? x : far[x] = FindR(far[x]);}
    void UnionL(int f, int s){fal[s] = FindL(f);}
    void UnionR(int f, int s){far[s] = FindR(f);}
    void reset(int N, int k){
        memset(fal, 0, sizeof(fal));
        memset(far, 0, sizeof(far));
        for(int i = 1; i <= N; ++i)
            if(a[i] < k)fal[i] = i;
            else if(a[i] > k)high.push_back(i), fal[i] = FindL(i - 1);
            else fal[i] = FindL(i - 1);
        for(int i = N; i >= 1; --i){
            if(a[i] < k)far[i] = i;
            else far[i] = FindR(i + 1);
        }
    }
}uf;

void dfs(int dep = 1){
    // printf("in dfs, dep = %d\n", dep);
    if(finished)return;
    if(!TIME_LIMIT)return finished = true, void();
    if(dep > (int)high.size()){
        int len(0);
        for(int i = 1; i <= N; ++i){
            if(a[i] >= k)++len;
            else len = 0;
        }
        ans = max(ans, len);
        return;
    }
    int p = high.at(dep - 1);
    vector < pair < int, int > > editA, editL, editR;
    if(rnddd(50)){
        int val = p - k;
        int cp = uf.FindR(p);
        while(cp && val > 0){
            editA.emplace_back(cp, a[cp]);
            editR.emplace_back(cp, uf.FindR(cp));
            val -= k - a[cp];
            a[cp] = k;
            int tcp = cp;
            if(val < 0)a[cp] += val;
            else cp = uf.FindR(cp + 1), uf.UnionR(cp, tcp);
        }
        cp = uf.FindL(p);
        while(cp && val > 0){
            editA.emplace_back(cp, a[cp]);
            editL.emplace_back(cp, uf.FindL(cp));
            val -= k - a[cp];
            a[cp] = k;
            int tcp = cp;
            if(val < 0)a[cp] += val;
            else cp = uf.FindL(cp - 1), uf.UnionL(cp, tcp);
        }
        if(val > 0){
            ans = N;
            finished = true;
            return;
        }
        dfs(dep + 1);
        for(auto i : editA)a[i.first] = i.second;
        for(auto i : editL)uf.fal[i.first] = i.second;
        for(auto i : editR)uf.far[i.first] = i.second;
    }else{
        int val = p - k;
        int cp = uf.FindL(p);
        while(cp && val > 0){
            editA.emplace_back(cp, a[cp]);
            editL.emplace_back(cp, uf.FindL(cp));
            val -= k - a[cp];
            a[cp] = k;
            int tcp = cp;
            if(val < 0)a[cp] += val;
            else cp = uf.FindL(cp - 1), uf.UnionL(cp, tcp);
        }
        cp = uf.FindR(p);
        while(cp && val > 0){
            editA.emplace_back(cp, a[cp]);
            editR.emplace_back(cp, uf.FindR(cp));
            val -= k - a[cp];
            a[cp] = k;
            int tcp = cp;
            if(val < 0)a[cp] += val;
            else cp = uf.FindR(cp + 1), uf.UnionR(cp, tcp);
        }
        if(val > 0){
            ans = N;
            finished = true;
            return;
        }
        dfs(dep + 1);
        for(auto i : editA)a[i.first] = i.second;
        for(auto i : editL)uf.fal[i.first] = i.second;
        for(auto i : editR)uf.far[i.first] = i.second;
    }

}

int main(){
    freopen("TOMO.in", "r", stdin);
    freopen("TOMO.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)base[i] = read();
    while(M--){
        memcpy(a, base, sizeof(base));
        cnt = ans = finished = 0;
        high.clear();
        k = read();
        uf.reset(N, k);
        dfs();
        printf("%d\n", ans);
    }

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
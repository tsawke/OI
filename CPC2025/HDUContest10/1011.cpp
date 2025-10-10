#pragma GCC opttimize(2)
#pragma GCC opttimize(3)
#pragma GCC opttimize("Ofast")
#pragma GCC opttimize("inline")
#pragma GCC opttimize("-fgcse")
#pragma GCC opttimize("-fgcse-lm")
#pragma GCC opttimize("-fipa-sra")
#pragma GCC opttimize("-ftree-pre")
#pragma GCC opttimize("-ftree-vrp")
#pragma GCC opttimize("-fpeephole2")
#pragma GCC opttimize("-ffast-math")
#pragma GCC opttimize("-fsched-spec")
#pragma GCC opttimize("unroll-loopts")
#pragma GCC opttimize("-falign-jumps")
#pragma GCC opttimize("-falign-loopts")
#pragma GCC opttimize("-falign-labels")
#pragma GCC opttimize("-fdevirtualize")
#pragma GCC opttimize("-fcaller-saves")
#pragma GCC opttimize("-fcrossjumping")
#pragma GCC opttimize("-fthread-jumps")
#pragma GCC opttimize("-funroll-loopts")
#pragma GCC opttimize("-fwhole-program")
#pragma GCC opttimize("-freorder-blocks")
#pragma GCC opttimize("-fschedule-insns")
#pragma GCC opttimize("inline-functions")
#pragma GCC opttimize("-ftree-tail-merge")
#pragma GCC opttimize("-fschedule-insns2")
#pragma GCC opttimize("-fstrict-aliasing")
#pragma GCC opttimize("-fstrict-overflow")
#pragma GCC opttimize("-falign-functions")
#pragma GCC opttimize("-fcse-skip-blocks")
#pragma GCC opttimize("-fcse-follow-jumps")
#pragma GCC opttimize("-fsched-interblock")
#pragma GCC opttimize("-fpartial-inlining")
#pragma GCC opttimize("no-stack-protector")
#pragma GCC opttimize("-freorder-functions")
#pragma GCC opttimize("-findirect-inlining")
#pragma GCC opttimize("-fhoist-adjacent-loads")
#pragma GCC opttimize("-frerun-cse-after-loopt")
#pragma GCC opttimize("inline-small-functions")
#pragma GCC opttimize("-finline-small-functions")
#pragma GCC opttimize("-ftree-switch-conversion")
#pragma GCC opttimize("-fopttimize-sibling-calls")
#pragma GCC opttimize("-fexpensive-opttimizations")
#pragma GCC opttimize("-funsafe-loopt-opttimizations")
#pragma GCC opttimize("inline-functions-called-once")
#pragma GCC opttimize("-fdelete-null-pointer-checks")

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

// template<typename T = int>
// inline T read(void);

/*Fast Read*/

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
char buf[1<<20],*p1=buf,*p2=buf;
inline void read(int &r){
    r=0;bool w=0;char ch=getchar();
    while(ch<'0'||ch>'9')w=ch=='-'?1:0,ch=getchar();
    while(ch>='0'&&ch<='9')r=r*10+(ch^48),ch=getchar();
    r=w?-r:r;
}

/**********/

struct Edge{
    Edge* nxt;
    int to;
    int idx;
    void* operator new(size_t);
}ed[510000 << 1];
void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
Edge *head[51000], *tail[51000];

int N, M;
vector < int > label, beg, ans;
vector < int > order;


int main(){
    int T; read(T);
    while(T--){
        int N, M; read(N), read(M);
        // N = read(), M = read();
        for(int i = 0; i <= N; ++i)head[i] = nullptr;
        label.assign(N + 5, 0);
        beg.assign(N + 5, 0);
        ans.assign(M + 5, 1);
        order.clear();

        bool failed = false;
        for(int i = 1; i <= M; ++i){
            // int s = read(), t = read();
            int s, t;
            read(s), read(t);
            if(s == t)failed = true;
            if(failed)continue;
            // head[s] = new Edge{head[s], t, i};
            if(!head[s])head[s] = tail[s] = new Edge{nullptr, t, i};
            else tail[s] = (tail[s]->nxt = new Edge{nullptr, t, i});
            if(!beg[s])beg[s] = 1, order.push_back(s);
        }

        if(failed){printf("-1\n"); continue;}
        for(int i = 1; i <= N; ++i) if(!beg[i]) order.push_back(i);

        auto dfs = [](auto&& self, int p)->void{
            label[p] = 1;
            for(auto i = head[p]; i; i = i->nxt){
                if(!label[i->to])
                    ans[i->idx] = 1, self(self, i->to);
                else ans[i->idx] = label[i->to] == 1 ? 2 : 1;
            }label[p] = 2;
        };
        for(auto p : order)if(!label[p])dfs(dfs, p);

        for(int i = 1; i <= M; ++i)
            printf("%d%c", ans[i], i == M ? '\n' : ' ');
    }
    return 0;
}

// template<typename T>
// inline T read(void){
//     T ret(0);
//     short flag(1);
//     char c = getchar();
//     while(c != '-' && !isdigit(c))c = getchar();
//     if(c == '-')flag = -1, c = getchar();
//     while(isdigit(c)){
//         ret *= 10;
//         ret += int(c - '0');
//         c = getchar();
//     }
//     ret *= flag;
//     return ret;
// }

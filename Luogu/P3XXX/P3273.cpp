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

int N, Q;
ll val[310000];
int idx[310000];
ll gadd(0);
ll tag[310000];
priority_queue < pair < ll, int >, vector < pair < ll, int > >, less < pair < ll, int > > > nods[310000], global;

class UnionFind{
private:
    int fa[310000];
public:
    UnionFind(void){for(int i = 1; i <= 301000; ++i)fa[i] = i;}
    int Find(int x){return fa[x] == x ? x : fa[x] = Find(fa[x]);}
    void Union(int s, int t){if(Find(s) != Find(t))fa[Find(s)] = Find(t);}
}uf;

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)nods[i].push({val[i] = read(), i}), global.push(nods[i].top());
    while(N--){
        string S; cin >> S;
        if(S == "A3")gadd += read();
        else if(S == "U"){
            int x = uf.Find(read()), y = uf.Find(read());
            if(x == y)continue;
            if(nods[idx[x]].size() < nods[idx[y]].size())swap(idx[x], idx[y]);
            auto lstTP = nods[idx[x]].top();
            while(!nods[idx[y]].empty()){
                auto tp = nods[idx[y]].top(); nods[idx[y]].pop();
                if(tp.first != val[tp.second])continue;
                tp.first += tag[idx[y]] - tag[idx[x]];
                val[tp.second] = tp.first;
                nods[idx[x]].push(tp);
            }
            if(lstTP.second != nods[idx[x]].top().second)val[lstTP.second] -= tag[idx[x]], val[nods[idx[x]].top().second] = nods[idx[x]].top().first + tag[idx[x]];
            uf.Union(y, x);
        }else if(S == "A1"){
            int p = read(), v = read();
            val[p] += v;
            global.push({val[p], p});
            int rp = uf.Find(p);
            nods[idx[rp]].push({val[p], p});
        }else if(S == "A2"){
            int p = uf.Find(read()), v = read();
            while(!nods[idx[p]].empty() && nods[idx[p]].top().first + tag[idx[p]] != val[nods[idx[p]].top().second])nods[idx[p]].pop();
            tag[p] += v;
            val[nods[idx[p]].top().second] = nods[idx[p]].top().first + tag[p];
            global.push({val[nods[idx[p]].top().second], nods[idx[p]].top().second});
        }else if(S == "F1"){
            
        }
    }

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
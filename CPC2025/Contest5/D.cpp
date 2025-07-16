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

#define MOD (998244353)

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    int val;
    void* operator new(size_t);
}ed[800000];
void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
Edge *head0[110000], *head1[110000];

int N, M;
bitset <110000> vis;
int ind0[110000], ind1[110000];

ll ans(0);

// basic_string < basic_string < int > > Chain, Loop;
vector < basic_string < int > > Chain, Loop;

auto CheckConnectivity = [](int s, int t)->bool{
    // printf("Checking s = %d, t = %d\n", s, t);
    for(auto p = head1[s]; p; p = p->nxt){
        if(p->to == t){
            // printf("In check %d -> %d, suc.\n", s, t);
            return true;
        }
        // printf("to = %d\n", p->to);
    
    }
        // printf("In check %d -> %d, fail.\n", s, t);
    return false;
};
auto CheckConnectivity0 = [](int s, int t)->bool{
    for(auto p = head0[s]; p; p = p->nxt)
        if(p->to == t)return true;
    return false;
};

int main(){

    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        if(v && CheckConnectivity(s, t)){
            // ++ind1[s], ++ind1[t];
            continue;
        }
        if(!v && CheckConnectivity0(s, t)){
            // ++ind0[s], ++ind0[t];
            continue;
        }
        v
            ? (++ind1[s], ++ind1[t], head1[s] = new Edge{head1[s], t, v}, head1[t] = new Edge{head1[t], s, v})
            : (++ind0[s], ++ind0[t], head0[s] = new Edge{head0[s], t, v}, head0[t] = new Edge{head0[t], s, v});
    }
    for(int i = 1; i <= N; ++i){
        if(ind0[i] == 3 || ind1[i] == 3){
            vis[i] = true;
            for(auto s = head0[i]; s; s = s->nxt){
                Edge* chead = nullptr;
                for(auto p = head0[s->to]; p; p = p->nxt){
                    if(p->to != i)chead = new Edge{chead, p->to, p->val};
                    else --ind0[s->to];
                }head0[s->to] = chead;
            }
            for(auto s = head1[i]; s; s = s->nxt){
                Edge* chead = nullptr;
                for(auto p = head1[s->to]; p; p = p->nxt){
                    if(p->to != i)chead = new Edge{chead, p->to, p->val};
                    else --ind1[s->to];
                }head1[s->to] = chead;
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        if(vis[i])continue;
        // if(!ind0[i] || ind0[i] == 3){
        //     // ++ans, ans %= MOD
        //     vis[i] = true;
        //     continue;
        // }
        if(!ind0[i]){
            vis[i] = true;
            continue;
        }
        if(ind0[i] == 1){
            basic_string < int > cur;
            cur += i;
            vis[i] = true;
            int curp = head0[i]->to, lst = i;
            bool flag(true);
            while(ind0[curp] != 1){
                if(vis[curp]){flag = false; break;}
                cur += curp;
                vis[curp] = true;
                curp = head0[curp]->to == lst ? (lst = curp, head0[curp]->nxt->to) : (lst = curp, head0[curp]->to);

            }vis[curp] = true, cur += curp;
            if(flag)Chain.push_back(cur);
        }
    }
    for(int i = 1; i <= N; ++i){
        if(vis[i])continue;
        basic_string < int > cur;
        cur += i;
        vis[i] = true;
        int curp = head0[i]->to, lst = i;
        bool flag(true);
        while(true){
            if(vis[curp]){flag = false; break;}
            cur += curp;
            vis[curp] = true;
            // if(head0[curp]->nxt == nullptr)printf("err at curp = %d, lst = %d, to = %d, size = %d\n", curp, lst, head0[curp]->to, cur.size());
            curp = (head0[curp]->to == lst) ? (lst = curp, head0[curp]->nxt->to) : (lst = curp, head0[curp]->to);
            if(curp == i)break;
        }
        if(flag)Loop.push_back(cur);
    }
    
    for(auto loop : Loop){
        for(auto it = loop.begin(); it != prev(loop.end()); ++it)
            if(CheckConnectivity(*it, *next(it)))++ans, ans %= MOD;
        if(CheckConnectivity(*prev(loop.end()), *loop.begin()))++ans, ans %= MOD;
    }
    for(auto chain : Chain){
        // printf("%d\n", chain.size());
        // if(chain.size() >= 4)
            for(auto it = chain.begin(); it != prev(chain.end()); ++it)
                if(CheckConnectivity(*it, *next(it)))++ans, ans %= MOD;
        // if(CheckConnectivity(*chain.begin(), *prev(chain.end())))++ans, ans %= MOD;
        // if()
        if(chain.size() == 3){
            // if(CheckConnectivity(*chain.begin(), *next(chain.begin())))++ans, ans %= MOD;
            // if(CheckConnectivity(*next(chain.begin()), *next(chain.begin(), 2)))++ans, ans %= MOD;
            if(
                ( CheckConnectivity(*chain.begin(), *next(chain.begin())) && CheckConnectivity(*chain.begin(), *next(chain.begin(), 2)) ) ||
                ( CheckConnectivity(*next(chain.begin(), 2), *next(chain.begin())) && CheckConnectivity(*next(chain.begin(), 2), *chain.begin()) )
            )++ans, ans %= MOD;//;;, printf("ans++++\n");
        }else{
            if(chain.size() == 4){
                if((
                    ( CheckConnectivity(*chain.begin(), *next(chain.begin(), 1)) && CheckConnectivity(*prev(chain.end(), 1), *prev(chain.end(), 2)) ) ||
                    ( CheckConnectivity(*chain.begin(), *next(chain.begin(), 2)) && CheckConnectivity(*prev(chain.end(), 1), *prev(chain.end(), 3)) ) //||
                    // ( CheckConnectivity(*chain.begin(), *next(chain.begin(), 3)) && CheckConnectivity(*prev(chain.end(), 2), *prev(chain.end(), 3)) )
                ) && CheckConnectivity(chain[0], chain[3])
                )++ans, ans %= MOD;//, printf("ans++\n");
            }
            if(chain.size() == 5){
                bool flag(false);
                for(int i = 2; i <= 5 - 2; ++i)
                    for(int j = i + 1; j <= 5 - 1; ++j){
                        if(CheckConnectivity(chain[0], chain[i - 1]) && CheckConnectivity(chain[0], chain[j - 1]) && CheckConnectivity(chain[4], chain[(2 ^ 3 ^ 4 ^ i ^ j) - 1]) && CheckConnectivity(chain[0], chain[4]))
                            flag = true;
                        if(CheckConnectivity(chain[4], chain[i - 1]) && CheckConnectivity(chain[4], chain[j - 1]) && CheckConnectivity(chain[0], chain[(2 ^ 3 ^ 4 ^ i ^ j) - 1]) && CheckConnectivity(chain[0], chain[4]))
                            flag = true;
                    }
                if(flag)++ans, ans %= MOD;
            }
            if(CheckConnectivity(*chain.begin(), *next(chain.begin())) && CheckConnectivity(*chain.begin(), *next(chain.begin(), 2)))++ans, ans %= MOD;
            if(CheckConnectivity(*prev(chain.end()), *prev(chain.end(), 2)) && CheckConnectivity(*prev(chain.end()), *prev(chain.end(), 3)))++ans, ans %= MOD;
            // if(CheckConnectivity(*chain.begin(), *prev(chain.end())) && CheckConnectivity(*chain.begin(), *next(chain.begin())))++ans, ans %= MOD;
            // if(CheckConnectivity(*chain.begin(), *prev(chain.end())) && CheckConnectivity(*prev(chain.end()), *prev(chain.end(), 2)))++ans, ans %= MOD;
        }
    }printf("%lld\n", (ans + N) % MOD);

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

/*

1 2 0
2 3 0
3 4 0
4 5 0

*/
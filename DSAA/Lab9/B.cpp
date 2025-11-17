#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

using ll = long long;
using unll = unsigned long long;
using uint = unsigned int;
using ld = long double;

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
};

const int LIM = 1100000;

int main(){
    vector < int > A(LIM, 0);
    vector < int > label(LIM, 0);
    vector < int > res(LIM, 0);
    vector < Edge* > head(LIM, nullptr);
    vector < int > L(LIM, 0), R(LIM, 0);
    vector < int > flag(LIM, 0), flag2(LIM, 0), F(LIM, 0);

    string S;
    stack < int > cur;
    int N(0), cnt(0); 
    while(cin >> S){
        if(!S.empty() && isdigit(S[0])){N = stoi(S); break;}
        if(S == "!"){
            if(!cur.empty()){
                int tp = cur.top();
                if(tp > 0) flag2[tp] ^= 1;
                else flag[-tp] ^= 1;
            }
        }else if(S[0] == 'x'){
            int val(0);
            for(int i = 1; i < (int)S.length(); ++i)
                val = val * 10 + int(S[i] - '0');
            cur.push(val);
        }else if(S == "&" || S == "|"){
            int y = cur.top(); cur.pop();
            int x = cur.top(); cur.pop();
            label[++cnt] = (S == "&" ? 2 : 3);
            L[cnt] = x; R[cnt] = y;
            cur.push(-cnt);
        }
    }

    for(int i = 1; i <= N; ++i)A[i] = read();

    auto mapID = [&](int t)->int{return t > 0 ? t : (N + (-t));};

    int root = cur.empty() ? N : mapID(cur.top());
    int Q = read();

    for(int i = 1; i <= N; ++i)F[i] = flag2[i];
    for(int i = 1; i <= cnt; ++i){
        int p = N + i;
        F[p] = flag[i];
        A[p] = label[i];
        head[p] = new Edge{head[p], mapID(L[i])};
        head[p] = new Edge{head[p], mapID(R[i])};
    }

    vector < char > vis(LIM, 0), vis2(LIM, 0);
    vector < int > val(LIM, 0);

    auto dfs = [&](auto&& self, int p, int g)->int{
        if(p <= N)return A[p] ^ g;
        if(vis[p])return val[p];
        vis[p] = 1;

        int c1(-1), c2(-1), k(0);
        for(auto i = head[p]; i && k < 2; i = i->nxt)
            (k++) == 0 ? c1 = i->to : c2 = i->to;
        int rs = c1, ls = c2;
        int x = self(self, ls, g ^ F[ls]);
        int y = self(self, rs, g ^ F[rs]);

        int opt = (A[p] ^ g);
        if(opt == 2){
            if(!x)res[rs] = 1;
            if(!y)res[ls] = 1;
            val[p] = (x & y);
        }else{
            if(x == 1)res[rs] = 1;
            if(y == 1)res[ls] = 1;
            val[p] = (x | y);
        }
        return val[p];
    };

    auto dfs2 = [&](auto&& self, int p)->void{
        if(p <= N)return;
        if(vis2[p])return;
        vis2[p] = 1;
        for(auto i = head[p]; i; i = i->nxt){
            res[i->to] |= res[p];
            self(self, i->to);
        }
    };

    int ans = dfs(dfs, root, F[root]);
    dfs2(dfs2, root);

    while(Q--)printf("%d\n", res[read()] ? ans : !ans);

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

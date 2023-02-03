#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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

int N, M;
int mx(-1);
string S[10];
unordered_set < string > block;
string ans;

void dfs(int dep = 1, int lft = mx, string cur = string()){
    if(dep > N){
        if(3 <= (int)cur.length() && (int)cur.length() <= 16 && block.find(cur) == block.end())ans = cur;
        return;
    }
    if(dep == 1)return dfs(dep + 1, lft, cur + S[dep]);
    dfs(dep + 1, lft, cur + "_" + S[dep]);
    for(int i = 1; i <= lft; ++i)
        cur += "_", dfs(dep + 1, lft - i, cur + "_" + S[dep]);
}

int main(){
    N = read(), M = read();
    int slen(0);
    for(int i = 1; i <= N; ++i)cin >> S[i], slen += S[i].length();
    for(int i = 1; i <= M; ++i){string T; cin >> T; block.insert(T);}
    mx = 16 - slen - N + 1;
    if(mx < 0)printf("-1\n"), exit(0);
    int tot(1); for(int i = 1; i <= N; ++i)tot *= i;
    for(int i = 1; i <= tot; ++i)dfs(), next_permutation(S + 1, S + N + 1);
    if(ans.empty())printf("-1\n"), exit(0);
    cout << ans << endl;
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
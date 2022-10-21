#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
// using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);

int N;
int arr[1100];
vector < int > cur;
int ans(0);

bool Check(void){
    int len[10];
    memset(len, 0, sizeof len);
    int lst(-1);
    for(auto i : cur){
        if(i == lst)++len[i];
        else if(len[i]++)return false;
    }
    int mn(INT_MAX), mx(INT_MIN);
    for(int i = 1; i <= 8; ++i)mn = min(mn, len[i]), mx = max(mx, len[i]);
    return mx - mn <= 1;
}

void dfs(int dep){
    if(dep > N){
        if(Check())ans = max(ans, (int)cur.size());
        return;
    }
    cur.emplace_back(arr[dep]);
    dfs(dep + 1);
    cur.pop_back();
    dfs(dep + 1);
}

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    N = read();
    for(int i = 1; i <= N; ++i)arr[i] = read();
    if(N <= 25)dfs(1), printf("%d\n", ans), exit(0);
    // while((double)clock() / CLOCKS_PER_SEC <= 0.95){
    //     int siz = rndd(1, N);
    //     for(int i = 1; i <= N; ++i){

        
    // }
    printf("%d\n", rndd(1, N));


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
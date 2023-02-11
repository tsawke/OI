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

#define EPS (1e-10)
#define INFLL (0x3f3f3f3f3f3f3f3fll)

template < typename T = int >
inline T read(void);

ll A, B;
ll ans(INFLL);
ll dx[10] = {0,  1, 1, 0, -1, -1, -1, 0, 1};
ll dy[10] = {0,  0, 1, 1, 1, 0, -1, -1, -1};
bitset < 10 > exists;

bool isInteger(ld v){
    return fabs(ld(ll(v)) - v) < EPS;
}
void Check(int i, int j, int base = 0){
    if(dx[i] * dy[j] - dx[j] * dy[i] == 0)return;
    ld v1 = (ld)(B * dx[i] - A * dy[i]) / (dx[i] * dy[j] - dx[j] * dy[i]);
    if(v1 <= -EPS || !isInteger(v1))return;
    ld v2 = (ld)(B * dx[j] - A * dy[j]) / (dx[j] * dy[i] - dx[i] * dy[j]);
    if(v2 <= -EPS || !isInteger(v2))return;
    ans = min(ans, ll(v1) + ll(v2) + base);
}

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T = read();
    while(T--){
        A = read(), B = read();
        for(int i = 1; i <= 8; ++i){
            char c = getchar(); while(!isdigit(c))c = getchar();
            exists[i] = c == '1';
        }ans = INFLL;
        if(!A && !B){printf("0\n"); continue;}
        for(int i = 1; i <= 8; ++i)
            if(exists[i]){
                if(A * dx[i] < 0 || B * dy[i] < 0)continue;
                if((!dx[i] && (A || !isInteger((ld)B / dy[i]))) || (!dy[i] && (B || !isInteger((ld)A / dx[i]))))continue;
                if(!dx[i])ans = min(ans, B / dy[i]);
                if(!dy[i])ans = min(ans, A / dx[i]);
                ld v1 = (ld)A / dx[i], v2 = (ld)B / dy[i];
                if(!isInteger(v1) || !isInteger(v2) || (ll)v1 != (ll)v2)continue;
                ans = min(ans, (ll)v1);
            }
        for(int i = 1; i <= 8; ++i)for(int j = i + 1; j <= 8; ++j)
            if(exists[i] && exists[j])Check(i, j);
        for(int i = 2; i <= 8; i += 2){
            if(!exists[i] || !exists[i == 2 ? 8 : i - 2])continue;
            for(int j = 1; j <= 8; j += 2){
                if(!exists[j])continue;
                A -= dx[j], B -= dy[j];
                Check(i == 2 ? 8 : i - 2, i, 1);
                A += dx[j], B += dy[j];
            }
        }
        printf("%lld\n", ans == INFLL ? -1ll : ans);
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
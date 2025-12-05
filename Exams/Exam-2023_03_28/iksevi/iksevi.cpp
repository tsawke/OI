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

#define LIM (11000000)

template < typename T = int >
inline T read(void);

int N;
pair < int, int > pos[1100000];
ll LIMV(0);
bitset < LIM > notPrime;
basic_string < int > Prime;
int tot(0);
int pri[LIM];
// pair < int, int > pri[1100000];
ll cnt[LIM];
unordered_set < int > fact[11000];

int main(){
    freopen("iksevi.in", "r", stdin);
    freopen("iksevi.out", "w", stdout);
    N = read();
    // LIMV = 10000000;
    for(int i = 1; i <= N; ++i)LIMV = max({(int)LIMV, pos[i].first = read(), pos[i].second = read()});
    for(int i = 2; i <= LIMV; ++i){
        if(!notPrime[i])Prime += i;
        for(auto p : Prime){
            if((ll)i * p > LIMV)break;
            notPrime[i * p] = true;
            if(i % p == 0)break;
        }
    }
    if(N <= 11000){
        for(int n = 1; n <= N; ++n){
            // int XX = read(), YY = read();
            int XX = pos[n].first, YY = pos[n].second;
            //0
            // ll ans(0);
            if(!XX || !YY){
                int val = XX ^ YY;
                ll ans(1);
                for(auto p : Prime){
                    if((ll)p * p > val)break;
                    int tms(1);
                    while(val % p == 0){
                        if(p != 2)++tms;
                        val /= p;
                    }ans *= tms;
                }printf("%lld\n", ans);
                continue;
            }
            if(!(XX & 1)){
                int X = XX >> 1;
                for(int i = 1; (ll)i * i <= X; ++i){
                    if(X % i)continue;
                    int d = X / i;
                    if((YY - d) % (2 * d) == 0)fact[n].insert(d);
                    if(i * i != X){
                        int d = i;
                        if((YY - d) % (2 * d) == 0)fact[n].insert(d);
                    }
                }
            }
            if(!(YY & 1)){
                int Y = YY >> 1;
                for(int i = 1; (ll)i * i <= Y; ++i){
                    if(Y % i)continue;
                    int d = Y / i;
                    if((XX - d) % (2 * d) == 0)fact[n].insert(d);
                    if(i * i != Y){
                        int d = i;
                        if((XX - d) % (2 * d) == 0)fact[n].insert(d);
                    }
                }
            }
            printf("%d\n", (int)fact[n].size());
        }exit(0);
    }
    for(auto p : Prime)pri[++tot] = p; //pri[++tot].first = p;
    auto dfs = [](auto&& self, int dep = 1, ll ccnt = 1, ll val = 1)->void{
        if(val > LIMV)return;
        if(dep > tot)return cnt[val] = ccnt, void();
        int tims(1);
        while(val <= LIMV){
            self(self, dep + 1, ccnt, val);
            val *= pri[dep];
            if(pri[dep] != 2)ccnt /= tims, ccnt *= ++tims;
        }
    }; dfs(dfs);
    for(int i = 1; i <= N; ++i)
        printf("%lld\n", (pos[i].first & 1 ? 0 : cnt[pos[i].second]) + (pos[i].second & 1 ? 0 : cnt[pos[i].first]));
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
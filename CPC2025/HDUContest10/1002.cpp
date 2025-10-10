#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-ffast-math")
#include <bits/stdc++.h>
using namespace std;

template<typename T> void read(T &x){
    x = 0; char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') x = (x<<1) + (x<<3) + (c^'0'), c = getchar();
}

const int N = 500000 + 5;

int n, m, S;
long long a[N], tauv[N], mulSum[N], tag1[N];
bool visTag[N];
vector<int> fac[N];
vector<int> smallAct;

inline long long lcmcnt(int x, int y){
    long long g = std::__gcd(x, y);
    long long l = (long long)(x / g) * y;
    return n / l;
}

int main(){
    read(n); read(m);
    for(int i = 1; i <= n; ++i) read(a[i]);
    for(int i = 1; i <= n; ++i) for(int j = i; j <= n; j += i) fac[j].push_back(i);
    for(int i = 1; i <= n; ++i) tauv[i] = (int)fac[i].size();
    S = (int)sqrt((long double)n);
    for(int x = 1; x <= S; ++x){
        long long s = 0;
        for(int i = x; i <= n; i += x) s += a[i];
        mulSum[x] = s;
    }
    while(m--){
        int op, x; read(op); read(x);
        if(op == 1){
            int k; read(k);
            if(x <= S){
                tag1[x] += k;
                if(!visTag[x]){ visTag[x] = 1; smallAct.push_back(x); }
            }else{
                for(int i = x; i <= n; i += x) a[i] += k;
                for(int s = 1; s <= S; ++s) mulSum[s] += lcmcnt(s, x) * (long long)k;
            }
        }else if(op == 2){
            int k; read(k);
            for(int d : fac[x]) a[d] += k;
            for(int s : fac[x]) if(s <= S) mulSum[s] += (long long)k * tauv[x / s];
        }else if(op == 3){
            long long ans = 0;
            if(x <= S) ans += mulSum[x];
            else{
                for(int i = x; i <= n; i += x) ans += a[i];
            }
            if(!smallAct.empty()){
                for(int s : smallAct){
                    if(tag1[s]) ans += tag1[s] * lcmcnt(x, s);
                }
            }
            printf("%lld\n", ans);
        }else{
            long long ans = 0;
            for(int d : fac[x]) ans += a[d];
            if(!smallAct.empty()){
                for(int s : smallAct){
                    if(tag1[s] && x % s == 0) ans += tag1[s] * tauv[x / s];
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}

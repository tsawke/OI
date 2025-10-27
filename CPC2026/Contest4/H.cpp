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



int main(){
    int N = read(), M = read(), K = read();
    vector < vector < int > > A(K + 10, vector < int >(N + 10, 0));
    for(int i = 1; i <= K; ++i)
        for(int j = 1; j <= N; ++j)
            A[i][j] = read();
    vector < ll > res(N + 10, 0);
    ll cur(0);
    priority_queue < pair < ll, int >, vector < pair < ll, int > >, less < pair < ll, int > > > q;
    for(int i = 1; i <= N; ++i){
        vector < int > vals;
        for(int j = 1; j <= K; ++j)vals.emplace_back(A[j][i]);
        sort(vals.begin(), vals.end());
        if(K & 1)cur += (res[i] = vals[K >> 1]);
        else{
            cur += (vals[K >> 1] + vals[(K >> 1) - 1]) >> 1;
            res[i] = (vals[K >> 1] + vals[(K >> 1) - 1]) >> 1;
            if((vals[K >> 1] + vals[(K >> 1) - 1]) & 1){
                ll sum1(0), sum0(0);
                for(int j = 1; j <= K; ++j)
                    sum1 += std::abs(res[i] + 1 - A[j][i]),
                    sum0 += std::abs(res[i] - A[j][i]);
                q.push({sum0 - sum1, i});
            }
        }
        // ll sum(0);
        // for(int j = 1; j <= K; ++j)sum += A[j][i];
        // cur += (res[i] = sum / K);
        // if(sum % K){
        //     ll sum1(0), sum0(0);
        //     for(int j = 1; j <= K; ++j)
        //         sum1 += std::abs(res[i] + 1 - A[j][i]),
        //         sum0 += std::abs(res[i] - A[j][i]);
        //     q.push({sum0 - sum1, i});
        // }
    }
    // for(int i = 1; i <= N; ++i)printf("%d%c", res[i], i == N ? '\n' : ' ');
    while(cur < M){
        if(q.empty()){
            
        }
        auto [_, idx] = q.top(); q.pop();
        ++res[idx], ++cur;
    }
    // for(int i = 1; i <= N; ++i)printf("%d%c", res[i], i == N ? '\n' : ' ');
    ll ans(0);
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= K; ++j)
            ans += std::abs(res[i] - A[j][i]);
    printf("%lld\n", ans >> 1);

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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
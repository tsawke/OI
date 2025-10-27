#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int read() {
    char c; int x = 0; bool f = 0;
    while(!isdigit(c = getchar())) f ^= (c == '-');
    while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return f ? -x : x;
}



int main(){
    int N = read();
    vector < ll > S(N + 10, 0);
    for(int i = 1; i <= N; ++i)S[i] = read();
    vector < ll > cur; cur.emplace_back(S[N]);
    vector < int > opt;
    basic_string < int > ans;
    auto dfs_ans = [&](auto&& self, int p, vector < pair < ll, int > > cur, int totsiz, int cur1)->void{
        // printf("> In dfs p = %d\n> cur:\n", p);
        // for(auto [v, idx] : cur)printf("  - [%lld, %d]\n", v, idx);
        // printf("> ans:\n");
        // for(auto v : ans)printf("%d ", v);
        // printf("\n");

        if(p == N){
            for(auto v : ans)printf("%d\n", v);
            exit(0);
        }
        if(S[p] == S[p + 1] + 1){
            ans += ++cur1;
            self(self, p + 1, cur, totsiz, cur1);
            ans.pop_back();
            return;
        }
        for(auto it = cur.begin(); it != prev(cur.end()); advance(it, 1)){
            if(it->first * next(it)->first - it->first - next(it)->first != S[p + 1] - S[p])continue;
            auto nxt = cur;
            nxt[distance(cur.begin(), it) + 1] = {it->first * next(it)->first, next(it)->second};
            ans += it->second;
            nxt.erase(next(nxt.begin(), distance(cur.begin(), it)));
            self(self, p + 1, nxt, totsiz, cur1);
            ans.pop_back();
        }
    };

    auto dfs = [&](auto&& self, int p, vector < ll > cur, int cnt1 = 0)->void{
        printf("> In pre dfs p = %d, cnt1 = %d\n", p, cnt1);
        if(p == 0){
            for(auto it = cur.begin(); it != cur.end(); advance(it, 1))
                printf("%lld ", *it, it == prev(cur.end()) ? '\n' : ' ');
            // printf("\n in ans cnt1 = %d\n", cnt1);
            for(int i = 1; i <= cnt1; ++i)printf("1 ");
            printf("\n");
            // for(auto i : opt)printf("%d\n", i);
            vector < pair < ll, int > > curr;
            for(int i = 1; i <= cur.size(); ++i)curr.push_back({cur[i - 1], i});
            dfs_ans(dfs_ans, 1, curr, cur.size(), cur.size() - 1);
            exit(0);
        }
        if(S[p] == S[p + 1] + 1){
            // printf("find\n");
            // auto nxt = cur;
            // nxt.insert(next(nxt.begin(), distance(cur.begin(), it) + 1), 1);
            // ++cnt1;
            // opt.emplace_back(distance(cur.begin(), it));
            self(self, p - 1, cur, cnt1 + 1);
            // continue;
            return;
            // break;
        }
        for(auto it = cur.begin(); it != cur.end(); advance(it, 1)){
            
            // if(*it == 1)continue;
            for(ll base = 1; base * base <= *it; ++base){
                if(*it % base)continue;
                ll other = *it / base;
                if(base * other - base - other != S[p + 1] - S[p])continue;
                auto nxt = cur;
                nxt.erase(next(nxt.begin(), distance(cur.begin(), it)));
                opt.emplace_back(distance(cur.begin(), it));
                nxt.insert(nxt.begin() + distance(cur.begin(), it), other);
                nxt.insert(nxt.begin() + distance(cur.begin(), it), base);
                self(self, p - 1, nxt, cnt1);
                break;
            }
        }
    }; dfs(dfs, N - 1, cur);

    printf("-1\n");


    return 0;
}
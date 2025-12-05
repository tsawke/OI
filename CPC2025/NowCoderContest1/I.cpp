#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <bits/stdc++.h>

void input(int &x) {
    x = 0; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
}

typedef long long LL;
const int N = 507;
const LL INF = 1e18;
typedef std::pair<LL, LL> pr;

int n;
LL a[N], s[N];
std::vector<pr> f[N][N];

LL integer_ceil_log2(LL y) {
    if(y <= 1)return 0;
    return 64 - __builtin_clzll((unsigned long long)y - 1);
}

LL B(int l, int r, int p) {
    return p ? abs((s[r] - s[p]) - (s[p] - s[l - 1])) : INF;
}

void dfs(int l, int r) {
    if(l == r || !f[l][r].empty()) return;
    
    for(int i = l; i < r; i++) {
        LL lef = INF, rig = INF, b = B(l, r, i);
        if(l < i) {
            dfs(l, i);
            int p = std::upper_bound(f[l][i].begin(), f[l][i].end(), pr(b, INF)) - f[l][i].begin() - 1;
            if(p != -1) lef = f[l][i][p].second;
        } else {
            lef = 0;
        }

        if(i + 1 < r) {
            dfs(i + 1, r);
            int p = std::upper_bound(f[i + 1][r].begin(), f[i + 1][r].end(), pr(b, INF)) - f[i + 1][r].begin() - 1;
            if(p != -1) rig = f[i + 1][r][p].second;
        } else {
            rig = 0;
        }

        if(lef >= INF || rig >= INF) continue;

        LL val = std::min(s[i] - s[l - 1], s[r] - s[i]) * integer_ceil_log2(s[r] - s[l - 1]);
        
        f[l][r].emplace_back(b, lef + rig + val);
    }

    if(f[l][r].empty()) return;
    
    std::sort(f[l][r].begin(), f[l][r].end());
    
    LL mn = INF;
    for(auto &[x, val] : f[l][r]) {
        mn = std::min(val, mn);
        val = mn;
    }
}

void solve() {
    input(n);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) f[i][j].clear();
    for(int i = 1; i <= n; i++) {
        int val;
        input(val);
        a[i] = val;
        s[i] = s[i - 1] + a[i];
    }
    
    for(int i = 1; i < n; i++) {
        LL lef = INF, rig = INF, b = B(1, n, i);
        if(1 < i) {
            dfs(1, i);
            int p = std::upper_bound(f[1][i].begin(), f[1][i].end(), pr(b, INF)) - f[1][i].begin() - 1;
            if(p != -1) lef = f[1][i][p].second;
        } else {
            lef = 0;
        }

        if(i + 1 < n) {
            dfs(i + 1, n);
            int p = std::upper_bound(f[i + 1][n].begin(), f[i + 1][n].end(), pr(b, INF)) - f[i + 1][n].begin() - 1;
            if(p != -1) rig = f[i + 1][n][p].second;
        } else {
            rig = 0;
        }
        
        if(lef >= INF || rig >= INF) {
            printf("-1 ");
            continue;
        }

        LL val = std::min(s[i], s[n] - s[i]) * integer_ceil_log2(s[n]);
        printf("%lld ", lef + rig + val);
    }
    puts("");
}

int main() {
    
    int T;
    input(T);
    while(T--) {
        solve();
    }
    return 0;
}
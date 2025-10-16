#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define li (x << 1)
#define ri ((x << 1) | 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
#define pr std::pair<int, int>

template<class T> T Abs(T x) { return x < 0 ? -x : x; }

int read() {
    int x = 0; char ch; bool f = 0;
    while(!isdigit(ch = getchar())) if(ch == '-') f = 1;
    while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 7; const pr INF = {1e18, 0};

int n, m, a[N], w[N];

namespace SGT {
    pr t[N]; int lazy[N];
    void build(int x, int l, int r) {
        lazy[x] = 0;
        if(l == r) { t[x] = {a[l] - w[l], l}; return; }
        build(ls), build(rs), t[x] = std::min(t[li], t[ri]);
    }
    void pushdown(int x) {
        if(lazy[x]) {
            if(t[li] != INF) t[li].first -= lazy[x], lazy[li] += lazy[x];
            if(t[ri] != INF) t[ri].first -= lazy[x], lazy[ri] += lazy[x];
            lazy[x] = 0;
        }
    }
    void reduce(int x, int l, int r, int L, int R, int val) {
        if(t[x] == INF) return;
        if(L <= l && r <= R) { t[x].first -= val, lazy[x] += val; return; }
        pushdown(x);
        if(L <= mid) reduce(ls, L, R, val);
        if(mid < R) reduce(rs, L, R, val);
        t[x] = std::min(t[li], t[ri]);
    }
    pr qmin(int x, int l, int r, int L, int R) {
        if(L <= l && r <= R) return t[x];
        pushdown(x); pr res = INF;
        if(L <= mid) res = qmin(ls, L, R);
        if(mid < R) res = std::min(qmin(rs, L, R), res);
        return res;
    }
}

void solve() {
    n = read(), m = read(), memset(w, 0, sizeof w);
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1, x, z; i <= m; i++) {
        x = read(), z = read();
        w[x] += z;
    }

    for(int i = n - 1; i; i--) w[i] += w[i + 1];

    SGT::build(1, 1, n);

    int front = n + 1, ans = 0;
    std::priority_queue<pr, std::vector<pr>, std::greater<pr>> q;
    for(int i = 1; i <= n; i++) {
        auto [val, pos] = SGT::qmin(1, 1, n, 1, front - 1);
        int rig = q.empty() ? 1e18 : q.top().first;

        if(val < rig) {
            fprintf(stderr, " * pos = %lld, val = %lld, ans = %lld\n", pos, val, ans);
            SGT::reduce(1, 1, n, 1, pos - 1, w[pos] - w[front]);
            for(int i = pos + 1; i < front; i++) q.emplace(a[i], i);
            front = pos, ans += val;
        } else {
            ans += rig, q.pop();
        }
        printf("%lld%c", ans, " \n"[i == n]);
    }
}

signed main() {
    int T = read(); while(T--) solve();
    return 0;
}
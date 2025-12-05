#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 100000;
int n, q;
int p_arr[MAXN + 5];

// sqrt-decomposition 参数
int B; // 块大小
int nb; // 块数

// freq[b][v]: 块 b 内 p[i]==v 的次数（1-based v）
vector< vector<int> > freq;          // size nb x (n+1) but stored as flat vector for prefix
vector< vector<ll> > pref_freq;     // 前缀和 over v
vector<ll> S; // 每个块当前 sum_{v} a[v] * freq[b][v]

// BIT 用于差分实现 a[v] 的区间加 / 点查
ll bit[MAXN + 5];
void bit_add(int i, ll x) {
    for (; i <= n; i += i & -i) bit[i] += x;
}
ll bit_sum(int i) {
    ll s = 0;
    for (; i > 0; i -= i & -i) s += bit[i];
    return s;
}
// 让 a[L..R] 加 x
void range_add(int L, int R, ll x) {
    if (L > R) return;
    bit_add(L, x);
    if (R + 1 <= n) bit_add(R + 1, -x);
}
// 取 a[v]
ll point_query(int v) {
    return bit_sum(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p_arr[i];
    }
    // 预处理分块
    B = max(1, (int)(sqrt(n * 1.0))); // 约 316
    nb = (n + B - 1) / B;
    freq.assign(nb, vector<int>(n + 2, 0));
    pref_freq.assign(nb, vector<ll>(n + 2, 0));
    S.assign(nb, 0);

    // 构造每个块的 freq
    for (int i = 1; i <= n; i++) {
        int b = (i - 1) / B;
        int v = p_arr[i];
        freq[b][v]++;
    }
    // 构造前缀 over v
    for (int b = 0; b < nb; b++) {
        ll acc = 0;
        for (int v = 1; v <= n; v++) {
            acc += freq[b][v];
            pref_freq[b][v] = acc;
        }
    }

    ll last = 0;
    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            ll L, R, x;
            cin >> L >> R >> x;
            L ^= last; R ^= last; x ^= last;
            if (L < 1) L = 1;
            if (R > n) R = n;
            if (L > R) swap(L, R);
            // 在 a[L..R] 加 x
            range_add((int)L, (int)R, x);
            // 同步每个块的 S[b]
            for (int b = 0; b < nb; b++) {
                // 这个块中所有 v ∈ [L,R] 出现次数之和
                ll cnt = pref_freq[b][R] - (L > 1 ? pref_freq[b][L - 1] : 0);
                if (cnt) {
                    S[b] += cnt * x;
                }
            }
        } else {
            ll l, r;
            cin >> l >> r;
            l ^= last; r ^= last;
            if (l < 1) l = 1;
            if (r > n) r = n;
            if (l > r) swap(l, r);
            ll ans = 0;
            int bl = (l - 1) / B;
            int br = (r - 1) / B;
            if (bl == br) {
                // 同一个块，暴力枚举
                for (int i = (int)l; i <= (int)r; i++) {
                    int v = p_arr[i];
                    ans += point_query(v);
                }
            } else {
                int end_bl = (bl + 1) * B;
                for (int i = (int)l; i <= min(n, end_bl); i++) {
                    int v = p_arr[i];
                    ans += point_query(v);
                }
                for (int b = bl + 1; b <= br - 1; b++) {
                    ans += S[b];
                }
                int start_br = br * B + 1;
                for (int i = start_br; i <= (int)r; i++) {
                    int v = p_arr[i];
                    ans += point_query(v);
                }
            }
            cout << ans << "\n";
            last = ans;
        }
    }
    return 0;
}

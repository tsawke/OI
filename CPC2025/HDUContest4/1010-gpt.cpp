#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1000000007;

// 快速幂 & 逆元
long long modexp(long long a, long long e = MOD-2) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

// 全局组合数容器（最大 N 由输入决定）
vector<int> fact, ifact;
void init_factorials(int N) {
    fact.resize(N+1);
    ifact.resize(N+1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = (long long)fact[i-1]*i%MOD;
    ifact[N] = modexp(fact[N]);
    for (int i = N; i > 0; i--) ifact[i-1] = (long long)ifact[i]*i%MOD;
}
inline int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (long long)fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}

// 对某个 D=2^bit，只为 r in [r0..r1] 计算 H[D][r]
vector<int> compute_H_range(int bit, int r0, int r1) {
    int D  = 1<<bit;
    int HD = D>>1;
    vector<int> sgnC(HD+1);
    for (int i = 0; i <= HD; i++) {
        long long v = C(HD, i);
        if (i & 1) v = (MOD - v) % MOD;
        sgnC[i] = int(v);
    }
    r0 = max(r0, 0);
    r1 = min(r1, D);
    vector<int> H(r1 - r0 + 1);
    for (int r = r0; r <= r1; r++) {
        long long sum = 0;
        int imn = max(0, r - HD);
        int imx = min(HD, r);
        for (int i = imn; i <= imx; i++) {
            sum = (sum + (long long)sgnC[i] * C(HD, r - i)) % MOD;
        }
        H[r - r0] = int(sum);
    }
    return H;
}

// subZero(D, r) = ( C(D,r) + (D-1)*H[D][r] ) * inv(D) mod
inline int subZero_from_H(int D, int r, int Hr) {
    long long v = ((long long)C(D, r) + (long long)(D - 1) * Hr) % MOD;
    static unordered_map<int,int> invD;
    auto it = invD.find(D);
    if (it == invD.end()) {
        int inv = int(modexp(D));
        it = invD.emplace(D, inv).first;
    }
    return int(v * it->second % MOD);
}

// 计算 A_total(n,r,k)：将 n 分成 r 段，每段长度 ∈ [1,k]
int A_total(int n, int r, int k) {
    long long res = 0;
    int J = (n - r) / k;
    for (int j = 0; j <= J; j++) {
        long long t = (long long)C(r, j) * C(n - j * k - 1, r - 1) % MOD;
        if (j & 1) res = (res - t + MOD) % MOD;
        else        res = (res + t) % MOD;
    }
    return int(res);
}
// 计算 A_even：所有段均为偶长
int A_even(int n, int r, int k_even) {
    // 如果 k_even<=0 则没有任何偶长段可以选
    if (k_even <= 0) return 0;
    if (n & 1) return 0;
    int ne = n >> 1;
    long long res = 0;
    int J = (ne - r) / k_even;
    for (int j = 0; j <= J; j++) {
        long long t = (long long)C(r, j) * C(ne - j * k_even - 1, r - 1) % MOD;
        if (j & 1) res = (res - t + MOD) % MOD;
        else       res = (res + t) % MOD;
    }
    return int(res);
}
// 计算 A_oneodd：恰好一段为奇长
int A_oneodd(int n, int r, int k_odd, int k_even) {
    if (((n - 1) & 1) != 0) return 0;
    int N = (n - 1) / 2 - (r - 1);
    if (N < 0) return 0;
    long long res = 0;
    for (int i = 0; i <= 1; i++) {
        long long si = (i & 1) ? MOD - 1 : 1;
        int sh = i * k_odd;
        for (int j = 0; j <= r - 1; j++) {
            int rem = N - j * k_even - sh;
            if (rem < 0) break;
            long long t = si
                        * C(r - 1, j) % MOD
                        * C(rem + (r - 1) - 1, (r - 1) - 1) % MOD;
            if (j & 1) res = (res - t + MOD) % MOD;
            else       res = (res + t) % MOD;
        }
    }
    return int(res * r % MOD);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<tuple<int,int,int,int,int>> qs(T);
    int maxD_need = 0;
    for (int i = 0; i < T; i++) {
        int n1, m1, k1, n2, m2;
        cin >> n1 >> m1 >> k1 >> n2 >> m2;
        qs[i] = {n1, m1, k1, n2, m2};
        maxD_need = max(maxD_need, 1 << m1);
        maxD_need = max(maxD_need, 1 << m2);
    }

    // 预处理组合数
    init_factorials(maxD_need);

    for (auto &q : qs) {
        int n1, m1, k1, n2, m2;
        tie(n1, m1, k1, n2, m2) = q;

        // 第一问
        int D1 = 1 << m1;
        int rmin = (n1 + k1 - 1) / k1;
        int rmax = min(n1, D1);
        auto H1 = compute_H_range(m1, rmin, rmax);

        long long ans1 = 0;
        int ke = k1 / 2, ko = (k1 + 1) / 2;
        for (int r = rmin; r <= rmax; r++) {
            int idx = r - rmin;
            int Atot = A_total(n1, r, k1);
            int A0   = A_even(n1, r, ke);
            int A1   = A_oneodd(n1, r, ko, ke);
            int Hr   = H1[idx];
            int subz = subZero_from_H(D1, r, Hr);

            long long term = 0;
            term = (term + (long long)A0 * C(D1, r)) % MOD;
            term = (term + (long long)A1 * C(D1 - 1, r - 1)) % MOD;
            long long rest = (Atot - A0 - A1) % MOD;
            if (rest < 0) rest += MOD;
            term = (term + rest * subz) % MOD;
            ans1 = (ans1 + term) % MOD;
        }
        cout << ans1 << "\n";

        // 第二问
        int D2 = 1 << m2;
        auto H2 = compute_H_range(m2, 1, n2);

        int xor_acc = 0;
        long long sum2 = 0;
        for (int r = 1; r <= n2; r++) {
            int Hr = H2[r-1];
            int v  = subZero_from_H(D2, r, Hr);
            xor_acc ^= v;
            sum2 = (sum2 + (long long)v * v) % MOD;
        }
        cout << xor_acc << " " << sum2 << "\n";
    }

    return 0;
}

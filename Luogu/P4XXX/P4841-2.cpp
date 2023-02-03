#include <iostream>
#include <cstdio>
#define mod 1004535809
using namespace std;

long long inv[200005], fiv[200005];

long long fsp(long long base, long long p) {
    long long rt = 1;
    while (p) {
        if (p & 1) (rt *= base) %= mod;
        (base *= base) %= mod;
        p >>= 1;
    }
    return rt;
}

int rtt[600005];
struct Poly {
    long long x[600005];
    void cpy(Poly &a, int len) {
        for (int i = 0; i < len; ++i) x[i] = a.x[i];
        return ;
    }
    void mem(int len) {
        for (int i = 0; i < len; ++i) x[i] = 0;
        return ;
    }
    void ntt(int w, int b) {
        int len = 1 << w;
        for (int i = 0; i < len; ++i) {
            rtt[i] = rtt[i >> 1] >> 1 | ((i & 1) << (w - 1));
            if (i < rtt[i]) swap(x[i], x[rtt[i]]);
        }
        for (int l = 2; l <= len; l <<= 1) {
            int m = l >> 1;
            long long omega = fsp(3, (mod - 1) / l);
            if (b) omega = fsp(omega, mod - 2);
            for (int i = 0; i < len; i += l) {
                long long tomega = 1;
                for (int j = i; j < i + m; ++j, (tomega *= omega) %= mod) {
                    long long t = tomega * x[j + m] % mod;
                    x[j + m] = (x[j] + mod - t) % mod;
                    x[j] = (x[j] + t) % mod;
                }
            }
        }
        return ;
    }
} g1, g2, f, tmp1, tmp2;

Poly inversion(Poly &a, Poly &b, Poly &c, int n) {
    b.mem(2 * n);
    if (a.x[0] == 1) b.x[0] = 1;
    else b.x[0] = fsp(a.x[0], mod - 2);
    for (int w = 1; (1 << (w - 1)) < n; ++w) {
        int len = 1 << w;
        c.cpy(a, len), c.ntt(w + 1, 0), b.ntt(w + 1, 0);
        for (int i = 0; i < (len << 1); ++i) (b.x[i] *= mod + 2ll - b.x[i] * c.x[i] % mod) %= mod;
        b.ntt(w + 1, 1);
        long long ny = fsp(len << 1, mod - 2);
        for (int i = 0; i < len; ++i) (b.x[i] *= ny) %= mod;
        for (int i = len; i < (len << 1); ++i) b.x[i] = 0;
    }
    return b;
}

int main() {
    int n, w = 0;
    scanf("%d", &n);
    n++;
    fiv[0] = fiv[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
        fiv[i] = fiv[i - 1] * inv[i] % mod;
    }
    g2.x[0] = 1;
    for (int i = 1; i < n; ++i) {
        long long tmp = fsp(2, 1ll * i * (i - 1) / 2 % (mod - 1));
        g1.x[i] = tmp * fiv[i - 1] % mod, g2.x[i] = tmp * fiv[i] % mod;
    }
    for(int i = 0; i <= 5; ++i)printf("p[%d] = %lld\n", i, g2.x[i]);
    g2 = inversion(g2, tmp1, tmp2, n);
    for(int i = 0; i <= 5; ++i)printf("p[%d] = %lld\n", i, g2.x[i]);
    while ((1 << w) < (n << 1)) w++;
    for (int i = n; i < (1 << w); ++i) g2.x[i] = 0;
    g1.ntt(w, 0), g2.ntt(w, 0);
    for (int i = 0; i <= (1 << w); ++i) f.x[i] = g1.x[i] * g2.x[i] % mod;
    f.ntt(w, 1);
    printf("%lld", fsp(inv[2], w) * f.x[n - 1] % mod * fsp(fiv[n - 2], mod - 2) % mod);
    return 0;
}
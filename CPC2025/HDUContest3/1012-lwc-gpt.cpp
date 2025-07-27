#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

static const int IB_SIZE = 1 << 20;
static char ibuf[IB_SIZE];
static int ipos = 0, ilen = 0;
inline int igetc() {
    if (ipos == ilen) {
        ilen = fread(ibuf, 1, IB_SIZE, stdin);
        ipos = 0;
        if (!ilen) return EOF;
    }
    return ibuf[ipos++];
}
inline void read(int &x) {
    x = 0; int c = igetc(); bool neg = false;
    while (c != '-' && (c < '0' || c > '9')) c = igetc();
    if (c == '-') { neg = true; c = igetc(); }
    for (; c >= '0' && c <= '9'; c = igetc()) x = x * 10 + (c - '0');
    if (neg) x = -x;
}
static const int OB_SIZE = 1 << 20;
static char obuf[OB_SIZE];
static int opos = 0;
inline void oputc(char c) {
    if (opos == OB_SIZE) {
        fwrite(obuf, 1, OB_SIZE, stdout);
        opos = 0;
    }
    obuf[opos++] = c;
}
inline void writeInt(long long x) {
    if (x < 0) { oputc('-'); x = -x; }
    char s[32]; int p = 0;
    if (x == 0) s[p++] = '0';
    else while (x) { s[p++] = char('0' + x % 10); x /= 10; }
    while (p--) oputc(s[p]);
    oputc('\n');
}
inline void oflush() {
    if (opos) fwrite(obuf, 1, opos, stdout), opos = 0;
}

const int N = 200005;
const int MOD = 1000000007;

struct qwq { int x, y, val, xy, yx; } a[N];
int T, n, b[N], ans;
int tree1[N], tree2[N], tree3[N], tree4[N];
int tree5[N], tree6[N], tree7[N], tree8[N];

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; ++i) {
            read(a[i].x); read(a[i].y); read(a[i].val);
            // tree1[i]=tree2[i]=tree3[i]=tree4[i]=0;
			// tree5[i]=tree6[i]=tree7[i]=tree8[i]=0;
        }
        memset(tree1, 0, (n + 2) * sizeof(int));
        memset(tree2, 0, (n + 2) * sizeof(int));
        memset(tree3, 0, (n + 2) * sizeof(int));
        memset(tree4, 0, (n + 2) * sizeof(int));
        memset(tree5, 0, (n + 2) * sizeof(int));
        memset(tree6, 0, (n + 2) * sizeof(int));
        memset(tree7, 0, (n + 2) * sizeof(int));
        memset(tree8, 0, (n + 2) * sizeof(int));

        ans = 0;
        sort(a + 1, a + n + 1, [](const qwq &A, const qwq &B) { return A.x < B.x; });

        long long suma = 0, sumx = 0, sumax = 0;
        for (int i = 1; i <= n; ++i) {
            long long xi = ( (long long)a[i].x % MOD + MOD ) % MOD;
            long long vi = ( (long long)a[i].val % MOD + MOD ) % MOD;
            long long t = ( ((long long)(i - 1) % MOD) * vi % MOD * xi % MOD + suma * xi % MOD + 3LL * MOD ) % MOD;
            t = (t - (vi * ((sumx + MOD) % MOD) % MOD + MOD) % MOD - sumax + 3LL * MOD) % MOD;
            ans += (int)t;
            if (ans >= MOD) ans -= MOD;
            suma += vi; if (suma >= MOD) suma -= MOD;
            sumx += xi; if (sumx >= MOD) sumx -= MOD;
            sumax += xi * vi % MOD; if (sumax >= MOD) sumax -= MOD;
        }

        for (int i = 1; i <= n; ++i) b[i] = a[i].y - a[i].x;
        sort(b + 1, b + n + 1);
        int cur = int(unique(b + 1, b + n + 1) - b - 1);
        for (int i = 1; i <= n; ++i) {
            a[i].yx = int(lower_bound(b + 1, b + cur + 1, a[i].y - a[i].x) - b) + 1;
        }

        for (int i = 1; i <= n; ++i) {
            int idx = a[i].yx - 1;
            long long s1 = 0, s2 = 0, s3 = 0, s7 = 0;
            for (int j = idx; j; j &= j - 1) {
                s7 += tree7[j]; if (s7 >= MOD) s7 -= MOD;
                s1 += tree1[j]; if (s1 >= MOD) s1 -= MOD;
                s2 += tree2[j]; if (s2 >= MOD) s2 -= MOD;
                s3 += tree3[j]; if (s3 >= MOD) s3 -= MOD;
            }
            long long d = a[i].y - a[i].x;
            long long nd = ( (d % MOD) + MOD ) % MOD;
            long long vm = ( (long long)a[i].val % MOD + MOD ) % MOD;

            long long t = ( s7 * vm % MOD * nd % MOD - s1 - vm * s2 % MOD + nd * s3 % MOD ) % MOD;
            if (t < 0) t += MOD;
            ans += (int)t;
            if (ans >= MOD) ans -= MOD;

            long long v1 = vm * nd % MOD;
            long long v2 = nd;
            long long v3 = vm;
            for (int j = a[i].yx; j <= n; j += j & -j) {
                tree1[j] += (int)v1; if (tree1[j] >= MOD) tree1[j] -= MOD;
                tree2[j] += (int)v2; if (tree2[j] >= MOD) tree2[j] -= MOD;
                tree3[j] += (int)v3; if (tree3[j] >= MOD) tree3[j] -= MOD;
                tree7[j] += 1;       if (tree7[j] >= MOD) tree7[j] -= MOD;
            }
        }

        for (int i = 1; i <= n; ++i) b[i] = a[i].x + a[i].y;
        sort(b + 1, b + n + 1);
        cur = int(unique(b + 1, b + n + 1) - b - 1);
        for (int i = 1; i <= n; ++i) {
            a[i].xy = int(lower_bound(b + 1, b + cur + 1, a[i].x + a[i].y) - b) + 1;
        }
        reverse(a + 1, a + n + 1);

        for (int i = 1; i <= n; ++i) {
            int idx = a[i].xy - 1;
            long long s4 = 0, s5 = 0, s6 = 0, s8 = 0;
            for (int j = idx; j; j &= j - 1) {
                s8 += tree8[j]; if (s8 >= MOD) s8 -= MOD;
                s4 += tree4[j]; if (s4 >= MOD) s4 -= MOD;
                s5 += tree5[j]; if (s5 >= MOD) s5 -= MOD;
                s6 += tree6[j]; if (s6 >= MOD) s6 -= MOD;
            }
            long long s = a[i].x + a[i].y;
            long long ns = ( (s % MOD) + 2LL * MOD ) % MOD;
            long long vm = ( (long long)a[i].val % MOD + MOD ) % MOD;

            long long t = (- (s8 * vm % MOD * ns % MOD) + MOD) % MOD;
            t = ( t + s4 - s5 * ns % MOD + vm * s6 % MOD + MOD ) % MOD;
            t = ( -t + MOD ) % MOD;
            ans += (int)t;
            if (ans >= MOD) ans -= MOD;

            long long v4 = vm * ns % MOD;
            long long v5 = vm;
            long long v6 = ns;
            for (int j = a[i].xy; j <= n; j += j & -j) {
                tree4[j] += (int)v4; if (tree4[j] >= MOD) tree4[j] -= MOD;
                tree5[j] += (int)v5; if (tree5[j] >= MOD) tree5[j] -= MOD;
                tree6[j] += (int)v6; if (tree6[j] >= MOD) tree6[j] -= MOD;
                tree8[j] += 1;       if (tree8[j] >= MOD) tree8[j] -= MOD;
            }
        }

        writeInt(ans);
    }
    oflush();
    return 0;
}

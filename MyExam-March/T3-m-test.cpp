#include <cstdio>
#include <algorithm>
#include <cstring>
#include <random>
#include <chrono>
#include <vector>
//#include<cassert>
typedef long long ll;
using namespace std;
typedef vector<int> Poly;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int MAXN = 1e7 + 5, mod = 998244353, L = 3, D = 2, m = 12, M = 15;
ll Fstpw(ll a, int b) {
    ll res = 1;

    while (b) {
        if (b & 1)
            res = res * a % mod;

        b >>= 1;
        a = a * a % mod;
    }

    return res;
}
Poly operator *(Poly a, Poly b) {
    Poly c(m);

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j + i < m && j < b.size(); j++)
            c[i + j] = (c[i + j] + 1ll * a[i] * b[j]) % mod;

    return c;
}
Poly Fstpw(Poly a, int b) {
    Poly res = Poly{1};

    while (b) {
        if (b & 1)
            res = res * a;

        b >>= 1;
        a = a * a;
    }

    return res;
}
int n, k;
Poly a(m), b(m + 1);
inline int getid(int x, int y) {
    return x * (D + 1) + y + 1;
}
namespace Gauss {
int n = m, a[M][M];
void Calc() {
    for (int i = 1; i <= n; i++) {
        if (!a[i][i]) {
            for (int j = i + 1; j <= n; j++)
                if (a[j][i]) {
                    swap(a[i], a[j]);
                    break;
                }

            if (!a[i][i])
                continue;
        }

        ll t = Fstpw(a[i][i], mod - 2);

        for (int j = i; j <= n; j++)
            a[i][j] = a[i][j] * t % mod;

        for (int j = i + 1; j <= n; j++)
            if (a[j][i]) {
                for (int k = i + 1; k <= n; k++)
                    a[j][k] = (a[j][k] - 1ll * a[j][i] * a[i][k] % mod + mod) % mod;

                a[j][i] = 0;
            }
    }

    for (int i = n; i; i--) {
        if (a[i][i]) {
            for (int j = i + 1; j <= n; j++)
                a[i][0] = (a[i][0] + 1ll * a[j][0] * a[i][j]) % mod;

            a[i][0] = (mod - a[i][0]) % mod;
        } else
            a[i][0] = rnd() % mod;
    }

    return ;
}
}
int e[L + 1][D + 1];
int f[MAXN], pre[MAXN], inv[MAXN];
int main() {
    //freopen("in","r",stdin);
    scanf("%d%d", &n, &k);
    k--;
    n -= k;

    if (k == 0 || n < 0)
        return puts("0"), 0;

    b[0] = 1;
    b[1] = mod - 1;
    b[2] = mod - 2;

    for (int i = 3; i <= m; i++) {
        for (int j = 1; j < i; j++)
            b[i] = (b[i] + 1ll * b[j] * b[i - j]) % mod;

        b[i] = b[i] * Fstpw(mod - 2, mod - 2) % mod;
    }

    for (int i = 0; i < m; i++)
        a[i] = b[i + 1] * Fstpw(mod - 2, mod - 2) % mod;

    a[0] = (a[0] + (mod + 1) / 2) % mod;
    a = Fstpw(a, k);

    for (int i = 0; i < m; i++)
        for (int x = 0; x <= L && x <= i; x++)
            for (int y = 0; y <= D; y++)
                (Gauss::a[i + 1][getid(x, y)] += a[i - x] * Fstpw(i - x, y) % mod) %= mod;

    Gauss::Calc();

    for (int i = 0; i <= L; i++)
        for (int j = 0; j <= D; j++)
            e[i][j] = Gauss::a[getid(i, j)][0];

    //for(int i=0; !e[0][i]; i++) assert(i<=D);
    for (int i = 0; i < m; i++)
        f[i] = a[i];

    for (int i = m; i <= n; i++)
        for (int j = 0, x = 1; j <= D; j++, x = 1ll * x * i % mod)
            f[i] = (f[i] + 1ll * e[0][j] * x) % mod;

    //for(int i=m; i<=n; i++) assert(f[i]);
    pre[0] = 1;
    pre[m - 1] = 1;

    for (int i = m; i <= n; i++)
        pre[i] = 1ll * pre[i - 1] * f[i] % mod;

    inv[n] = Fstpw(pre[n], mod - 2);

    for (int i = n; i >= m; i--)
        inv[i - 1] = 1ll * inv[i] * f[i] % mod;

    for (int i = m; i <= n; i++) {
        f[i] = 0;

        for (int j = 1; j <= L; j++)
            for (int k = 0, x = 1; k <= D; k++, x = 1ll * x * (i - j) % mod)
                f[i] = (f[i] + 1ll * f[i - j] * x % mod * e[j][k]) % mod;

        f[i] = f[i] * (mod - 1ll * pre[i - 1] * inv[i] % mod) % mod;
    }

    printf("%d\n", f[n]);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
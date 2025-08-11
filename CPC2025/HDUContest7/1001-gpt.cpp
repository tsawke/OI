#include <bits/stdc++.h>
using namespace std;

const int N = 10004;
static int a[N][N];
int cntX[N], cntY[N];
vector<int> X[N], Y[N];

inline int get(int x1, int y1, int x2, int y2, int n) {
    x2 = min(x2, n);
    y2 = min(y2, n);
    return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n, K; cin >> n >> K;
        for (int i = 0; i <= n; ++i) {
            cntX[i] = cntY[i] = 0;
            X[i].clear();
            Y[i].clear();
            for (int j = 0; j <= n; ++j) a[i][j] = 0;
        }
        long long tot = 0;
        for (int i = 1; i <= n; ++i) {
            int x, y, v; cin >> x >> y >> v;
            a[x][y] += v;
            tot += v;
            ++cntX[x]; ++cntY[y];
            X[x].push_back(y);
            Y[y].push_back(x);
        }
        for (int i = 1; i <= n; ++i) {
            sort(X[i].begin(), X[i].end(), greater<int>());
            sort(Y[i].begin(), Y[i].end(), greater<int>());
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

        int ans = 0, lim = (int)std::sqrt(K);
        for (int h = 1; h <= lim; ++h) {
            int w = K / h;
            for (int x = 1; x <= n; ++x) {
                if (!cntX[x] || get(x, 1, x + w - 1, n, n) <= ans) continue;
                for (int p = 0; p < (int)X[x].size(); ++p) {
                    int y = X[x][p];
                    for (int yy = y; yy >= y - h + 1 && yy; --yy) {
                        if (p && yy <= X[x][p - 1]) break;
                        ans = max(ans, get(x, yy, x + w - 1, yy + h - 1, n));
                    }
                }
            }
            if (ans == tot) break;
        }
        for (int h = 1; h <= lim; ++h) {
            int w = K / h;
            for (int y = 1; y <= n; ++y) {
                if (!cntY[y] || get(1, y, n, y + w - 1, n) <= ans) continue;
                for (int p = 0; p < (int)Y[y].size(); ++p) {
                    int x = Y[y][p];
                    for (int xx = x; xx >= x - h + 1 && xx; --xx) {
                        if (p && xx <= Y[y][p - 1]) break;
                        ans = max(ans, get(xx, y, xx + h - 1, y + w - 1, n));
                    }
                }
            }
            if (ans == tot) break;
        }
        cout << ans << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Bareiss 算法：在 O(n^3) 内计算整数矩阵的精确行列式
ll det_bareiss(const vector<vector<ll>>& A) {
    int n = A.size();
    // 工作用矩阵
    vector<vector<ll>> M = A;
    ll det_sign = 1;
    ll last = 1;
    for (int k = 0; k < n - 1; ++k) {
        // 如果主元为 0，要做行交换
        if (M[k][k] == 0) {
            int p = k + 1;
            while (p < n && M[p][k] == 0) ++p;
            if (p == n) return 0;            // 0 行列式
            swap(M[k], M[p]);
            det_sign = -det_sign;
        }
        // Bareiss 消去
        for (int i = k + 1; i < n; ++i) {
            for (int j = k + 1; j < n; ++j) {
                // 注意：此处保证整除
                M[i][j] = (M[i][j] * M[k][k] - M[i][k] * M[k][j]) / last;
            }
        }
        last = M[k][k];
    }
    return det_sign * M[n-1][n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;
    cout << "请输入 n k（以空格分隔）：";
    if (!(cin >> n >> k) || n <= 0) {
        cerr << "输入错误\n";
        return 1;
    }

    mt19937_64 rng(random_device{}());
    uniform_int_distribution<int> bit(0, 1);

    vector<vector<ll>> M(n, vector<ll>(n));

    // 随机搜索直到找到行列式 = k 的 0–1 矩阵
    while (true) {
        // 随机填 0/1
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                M[i][j] = bit(rng);

        ll d = det_bareiss(M);
        if (d == k) {
            cout << "\n找到一个行列式 = " << k << " 的矩阵：\n";
            for (auto &row : M) {
                for (ll x : row) cout << x << ' ';
                cout << '\n';
            }
            break;
        }
        // 可按需打印进度或限制尝试次数
    }

    return 0;
}

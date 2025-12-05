// build_10x10.cpp
// 利用“块对角乘积 = 行列式乘积”的构造，在 10x10 维度内，为 1..n（尽可能大的 n）
// 构造 det = k 的 0/1 矩阵（n 最终为 15）。全部为确定性、预置块库，无需随机搜索。

#include <bits/stdc++.h>
using namespace std;

using Mat = vector<vector<int>>;

// ---------------- Bareiss：整型精确行列式 ----------------
long long det_bareiss(vector<vector<long long>> a) {
    int n = (int)a.size();
    long long det_sign = 1;
    long long last = 1;
    for (int k = 0; k < n - 1; ++k) {
        int p = k;
        while (p < n && a[p][k] == 0) ++p;
        if (p == n) return 0;
        if (p != k) {
            swap(a[p], a[k]);
            det_sign = -det_sign;
        }
        long long pivot = a[k][k];
        if (pivot == 0) return 0;
        for (int i = k + 1; i < n; ++i) {
            for (int j = k + 1; j < n; ++j) {
                __int128 num = (__int128)a[i][j] * pivot - (__int128)a[i][k] * a[k][j];
                if (last != 0) num /= last; // Bareiss 保证整除
                a[i][j] = (long long)num;
            }
        }
        last = pivot;
    }
    return det_sign * a[n - 1][n - 1];
}

// ---------------- 预置基础块库（全部 0/1，已人工验证行列式） ----------------
// det = 2，3x3
static const Mat BLK_2 = {
    {0,1,1},
    {1,0,1},
    {1,1,0}
};

// det = 3，4x4
static const Mat BLK_3 = {
    {0,0,1,1},
    {0,1,0,1},
    {1,0,0,1},
    {1,1,1,0}
};

// det = 5，5x5
static const Mat BLK_5 = {
    {0,1,0,1,1},
    {1,0,1,1,1},
    {0,1,1,1,0},
    {1,1,0,0,0},
    {0,1,1,0,1}
};

// det = 7，7x7
static const Mat BLK_7 = {
    {0,1,1,0,1,0,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,1,1,0},
    {1,0,1,0,0,0,0},
    {1,0,0,0,1,0,0},
    {1,1,0,1,0,0,0},
    {1,1,0,0,0,1,0}
};

// det = 11，10x10（整块）
static const Mat BLK_11_10 = {
    {1,1,1,0,1,0,0,0,0,0},
    {1,1,1,1,1,1,0,0,1,0},
    {1,0,1,0,0,1,1,1,1,0},
    {0,1,1,0,0,1,0,1,0,1},
    {1,0,1,1,0,1,0,0,1,1},
    {1,0,1,1,0,0,1,0,0,0},
    {1,0,0,0,1,0,1,0,0,1},
    {0,1,0,1,0,0,1,0,1,1},
    {1,1,1,0,0,1,0,1,1,1},
    {1,1,0,0,1,0,0,1,1,0}
};

// det = 13，10x10（整块）
static const Mat BLK_13_10 = {
    {1,0,1,0,0,1,1,1,1,1},
    {0,1,0,0,1,0,0,1,0,0},
    {0,1,0,1,0,1,1,1,1,1},
    {1,0,0,0,0,0,1,0,0,0},
    {0,1,1,0,1,0,1,0,0,0},
    {0,0,0,1,0,0,1,0,1,1},
    {1,1,1,1,1,0,1,0,1,0},
    {1,1,0,0,0,1,0,0,1,0},
    {1,1,1,1,0,0,0,1,1,0},
    {1,1,1,0,1,1,1,0,0,1}
};

// 1x1 det=1
static const Mat BLK_1 = {{1}};

// ---------------- 工具：把若干小块拼成一个 10x10 块对角矩阵 ----------------
Mat embed_blocks_to_10(const vector<Mat>& blocks) {
    const int N = 10;
    Mat M(N, vector<int>(N, 0));
    int r = 0;
    for (const auto& B : blocks) {
        int d = (int)B.size();
        for (int i = 0; i < d; ++i)
            for (int j = 0; j < d; ++j)
                M[r + i][r + j] = B[i][j];
        r += d;
    }
    // 剩余维度补单位阵
    for (int i = r; i < N; ++i) M[i][i] = 1;
    return M;
}

// ----------------- 把 10x10 矩阵写入文件 -----------------
void dump_matrix_10_txt(const Mat& M, long long k) {

    if(k == 1){
        char name[64];
        // snprintf(name, sizeof(name), "mat_%04lld.txt", k);
        snprintf(name, sizeof(name), "mat.txt");
        FILE* out = fopen(name, "w");
        fprintf(out, "unordered_map < pair < int, int >, int, HashPair > mat[16];\n");
        fclose(out);
    }

    char name[64];
    // snprintf(name, sizeof(name), "mat_%04lld.txt", k);
    snprintf(name, sizeof(name), "mat.txt");
    // ofstream fout(name);
    FILE* out = fopen(name, "a");
    struct {
        auto operator()(const pair < int, int > &p) const{
            return hash < int >{}(p.first) ^ hash < int >{}(p.second);
        }
    };
    unordered_map < pair < int, int >, int,  > mat[16];

    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            fprintf(out, "mat[%lld].insert({{%d, %d}, %d})%c", k, i + 1, j + 1, M[i][j], j == 9 ? ';' : ',');
            // fout << M[i][j] << (j + 1 == 10 ? '\n' : ' ');
        }fprintf(out, "\n");
    }
    fclose(out);
    cerr << "saved " << name << "\n";
}

// ----------------- 质因数分解（只分我们关心的素数） -----------------
map<long long, int> factor_with_known_primes(long long k, const vector<long long>& primes) {
    map<long long, int> mp;
    for (auto p : primes) {
        while (k % p == 0) {
            mp[p]++;
            k /= p;
        }
    }
    if (k != 1) {
        // 还有未知质因数
        mp[-1] = (int)k; // 标记一下，表示不在库内
    }
    return mp;
}

// ----------------- 构造 det=k 的 10x10 矩阵 -----------------
bool build_10x10_for_k(long long k, Mat& out) {
    if (k == 1) {
        // 直接 10x10 单位阵
        out.assign(10, vector<int>(10, 0));
        for (int i = 0; i < 10; ++i) out[i][i] = 1;
        return true;
    }

    // “整块”直接支持的（维度=10）
    static const map<long long, Mat> FULL10 = {
        {11, BLK_11_10},
        {13, BLK_13_10},
    };

    // 若 k 是 FULL10 中的一个数，直接返回
    auto it_full = FULL10.find(k);
    if (it_full != FULL10.end()) {
        out = it_full->second;
        return true;
    }

    // 小素数块库（可重复乘）
    static const map<long long, Mat> PRIME_BLOCK = {
        {2, BLK_2},
        {3, BLK_3},
        {5, BLK_5},
        {7, BLK_7},
    };

    vector<long long> primes;
    for (auto& kv : PRIME_BLOCK) primes.push_back(kv.first);
    for (auto& kv : FULL10) primes.push_back(kv.first); // 也放上来，便于 factor 判定

    auto fac = factor_with_known_primes(k, primes);
    if (fac.count(-1)) {
        // 含有库外的质因数 -> 直接失败
        return false;
    }

    // 尝试用小素数块库（2,3,5,7）来拼
    vector<Mat> pieces;
    int used_dim = 0;

    for (auto [p, e] : fac) {
        if (p == 11 || p == 13) {
            // 若 k 本身就是 11 或 13，上面已 return；
            // 若还含其它因子，则肯定超过 10（因为 11/13 的块就已经用掉 10 维）
            return false;
        }
        auto it = PRIME_BLOCK.find(p);
        if (it == PRIME_BLOCK.end()) {
            // 没有这个素数的基础块
            return false;
        }
        const Mat& B = it->second;
        int d = (int)B.size();
        if ((long long)used_dim + 1LL * d * e > 10) {
            return false;
        }
        for (int i = 0; i < e; ++i) {
            pieces.push_back(B);
            used_dim += d;
        }
    }

    // 块对角拼起来，补单位阵
    out = embed_blocks_to_10(pieces);

    // （可选）严谨起见，验证一下行列式是否为 k
    vector<vector<long long>> check(10, vector<long long>(10));
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            check[i][j] = out[i][j];
    long long det = det_bareiss(check);
    if (det != k) {
        // 正负号或者其它失配（理论上不该发生）
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k = 1;
    for (;; ++k) {
        Mat M;
        if (!build_10x10_for_k(k, M)) {
            cerr << "Stopped at k = " << k
                 << ". Largest consecutive n achieved = " << (k - 1) << "\n";
            break;
        }
        dump_matrix_10_txt(M, k);
    }
    return 0;
}

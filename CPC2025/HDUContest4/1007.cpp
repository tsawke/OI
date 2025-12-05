#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAXN = 200000;

int n, q;
vector<int> b;
set<int> S4, S5;              // 匹配长度 4 / 5 的模板起点
set<int> S_long;              // 匹配长度 ≥7 的模板起点
unordered_map<int,int> L;     // 对于 p∈S_long，L[p]=len
set<int> nz;                  // 所有 b[i]!=0 的下标

inline bool match4(int p){
    if (p+3 > n) return false;
    // 1210
    if (b[p]==1&&b[p+1]==2&&b[p+2]==1&&b[p+3]==0) return true;
    // 2020
    if (b[p]==2&&b[p+1]==0&&b[p+2]==2&&b[p+3]==0) return true;
    return false;
}

inline bool match5(int p){
    if (p+4 > n) return false;
    // 21200
    return b[p]==2 && b[p+1]==1 && b[p+2]==2
        && b[p+3]==0 && b[p+4]==0;
}

bool matchLong(int p){
    int c = b[p];
    if (c < 3) return false;               // 最短长模板要 b[p]>=3
    int len = c + 4;
    if (p + len - 1 > n) return false;
    if (b[p+1] != 2 || b[p+2] != 1) return false;
    if (b[p + c] != 1) return false;
    auto it = nz.lower_bound(p+3);
    if (it == nz.end() || *it != p+c) return false;
    ++it;
    if (it!=nz.end() && *it <= p+len-1) return false;
    return true;
}

// **修正**：无条件删掉 p 在各集合里的旧记录
void removeAll(int p){
    S4.erase(p);
    S5.erase(p);
    if (S_long.erase(p)) L.erase(p);
}

// 根据新 b[p] 决定插入
void insertAll(int p){
    if (match4(p))  S4.insert(p);
    if (match5(p))  S5.insert(p);
    if (matchLong(p)){
        S_long.insert(p);
        L[p] = b[p] + 4;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--){
        cin >> n >> q;
        b.assign(n+1, 0);
        S4.clear(); S5.clear(); S_long.clear(); L.clear(); nz.clear();

        for (int i = 1; i <= n; i++){
            cin >> b[i];
            if (b[i] != 0) nz.insert(i);
        }
        // 初始化所有起点
        for (int p = 1; p <= n; p++){
            if (match4(p))  S4.insert(p);
            if (match5(p))  S5.insert(p);
            if (matchLong(p)){
                S_long.insert(p);
                L[p] = b[p] + 4;
            }
        }

        while (q--){
            int op, x, y;
            cin >> op >> x >> y;
            if (op == 1){
                // 更新 b[x]=y
                if (b[x] != 0) nz.erase(x);
                b[x] = y;
                if (b[x] != 0) nz.insert(x);
                int lo = max(1, x-6), hi = min(n, x);
                // 先删除旧的
                for (int p = lo; p <= hi; p++) removeAll(p);
                // 再插入新的
                for (int p = lo; p <= hi; p++) insertAll(p);
            } else {
                // 查询 [x..y]
                int l = x, r = y, ans = 0;
                // 长模板
                if (r - l + 1 >= 7){
                    auto it = S_long.lower_bound(l);
                    while (it != S_long.end()){
                        int p = *it;
                        if (p > r - 6) break;
                        int len = L[p];
                        if (p + len - 1 <= r) ans = max(ans, len);
                        ++it;
                    }
                }
                // 短模板
                if (r - l + 1 >= 5){
                    auto it5 = S5.lower_bound(l);
                    if (it5 != S5.end() && *it5 <= r - 4)
                        ans = max(ans, 5);
                }
                if (r - l + 1 >= 4){
                    auto it4 = S4.lower_bound(l);
                    if (it4 != S4.end() && *it4 <= r - 3)
                        ans = max(ans, 4);
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}

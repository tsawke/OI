#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll INF = (ll)4e18;

// “稀疏化”之后的列数上限：2*k（special 的左右邻）+2（边）
vector<int> allCols;
int getId(int c) {
    // 二分查找 allCols
    return int(lower_bound(allCols.begin(), allCols.end(), c) - allCols.begin());
}

// 试一次给定的激活集合 seeds，检查能否覆盖目标 parity p
// seeds：vector of (原列编号, rowParity(0/1), cost)
bool checkWin(int p, int nSparse, 
              const vector<pair<int,int>>& seeds, // (sparseId, rowParity)
              const vector<int>& outdeg
){
    int M = nSparse;
    // have[i][rp] 表示 稀疏列 i 在 Bob-turn 上是否已有行色 rp 被纳入吸引子
    static vector<array<bool,2>> have;
    static vector<array<int,2>> succ;
    have.assign(M, {false,false});
    succ.assign(M, {0,0});

    deque<pair<int,int>> dq;
    // 1) 初始化：把 seeds 全部标为 have = true
    for(auto &pr : seeds){
        int c = pr.first, rp = pr.second;
        if(!have[c][rp]){
            have[c][rp] = true;
            dq.emplace_back(c, rp);
        }
    }
    // 2) BFS
    while(!dq.empty()){
        auto [c, rp] = dq.front(); dq.pop_front();
        // 影响左右邻的 Alice-turn succ 计数
        for(int d=-1; d<=1; d+=2){
            int c2 = c + d;
            if(c2<0 || c2>=M) continue;
            succ[c2][rp] ++;
            if(succ[c2][rp] == outdeg[c2]){
                // Alice-turn(c2,rp) 一旦齐召后，能回推 Bob-turn(c2,1-rp)
                int nrp = 1 - rp;
                if(!have[c2][nrp]){
                    have[c2][nrp] = true;
                    dq.emplace_back(c2, nrp);
                }
            }
        }
    }

    // 3) 最后检查：对于每一个稀疏后的列 i，对应的原列 allCols[i]，
    //    目标行色 needed = (p + allCols[i])%2，必须 have[i][needed] = true
    for(int i=0;i<M;i++){
        int orig = allCols[i];
        int need = (p + orig)&1;
        if(!have[i][need]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<tuple<int,int,ll>> special(k);
        allCols.clear();
        allCols.reserve(3*k + 2);
        allCols.push_back(1);
        allCols.push_back(m);
        for(int i=0;i<k;i++){
            int r,c; ll w;
            cin >> r >> c >> w;
            special[i] = make_tuple(r,c,w);
            allCols.push_back(c);
            if(c>1)    allCols.push_back(c-1);
            if(c<m)    allCols.push_back(c+1);
        }
        // 去重+排序
        sort(allCols.begin(), allCols.end());
        allCols.erase(unique(allCols.begin(), allCols.end()), allCols.end());
        int M = (int)allCols.size();

        // 计算每个稀疏列的出度 outdeg: 边界 1，内部 2
        vector<int> outdeg(M, 2);
        for(int i=0;i<M;i++){
            if(allCols[i]==1 || allCols[i]==m) outdeg[i] = 1;
        }

        // 对每个 special，算出它在稀疏化之后的下标和行色
        vector<array<ll,2>> minCost(M, {INF,INF}); 
        for(auto &t : special){
            int r,c; ll w;
            tie(r,c,w) = t;
            int id = getId(c);
            int rp = r&1;
            minCost[id][rp] = min(minCost[id][rp], w);
        }

        // 对两种起始颜色 p=0(白) /1(黑) 分别求答案
        array<ll,2> answer = { -1, -1 };
        for(int p=0;p<2;p++){
            ll best = INF;

            // 1) 单点尝试
            vector<pair<int,int>> seeds;
            seeds.reserve(k);
            for(int i=0;i<M;i++){
                for(int rp=0;rp<2;rp++){
                    ll w = minCost[i][rp];
                    if(w<INF){
                        seeds.clear();
                        seeds.emplace_back(i,rp);
                        if(checkWin(p, M, seeds, outdeg)){
                            best = min(best, w);
                        }
                    }
                }
            }
            // 2) 两点尝试（可以根据需要再加三点、四点……）
            //    这里简单只试邻列对。更全的做法可再扩展。
            for(int i=0;i<M;i++){
                for(int rp=0;rp<2;rp++){
                    ll w1 = minCost[i][rp];
                    if(w1==INF) continue;
                    for(int d=-1;d<=1;d+=2){
                        int j = i + d;
                        if(j<0||j>=M) continue;
                        for(int rpj=0;rpj<2;rpj++){
                            ll w2 = minCost[j][rpj];
                            if(w2==INF) continue;
                            if(w1 + w2 >= best) continue;
                            seeds.clear();
                            seeds.emplace_back(i,rp);
                            seeds.emplace_back(j,rpj);
                            if(checkWin(p, M, seeds, outdeg)){
                                best = min(best, w1 + w2);
                            }
                        }
                    }
                }
            }

            if(best<INF) answer[p] = best;
        }

        cout << answer[0] << " " << answer[1] << "\n";
    }
    return 0;
}

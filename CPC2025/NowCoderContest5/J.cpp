#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e9+7;
const int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
vector<vector<int>> a, dis, c1, c2, tmp;
int n, m;
queue<pair<int,int>> q;

void bfs(){
    while(!q.empty()) q.pop();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dis[i][j] = inf;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j]){
                q.push({i,j});
                dis[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        for(int d = 0; d < 4; d++){
            int xx = x + dx[d], yy = y + dy[d];
            if(xx < 1 || yy < 1 || xx > n || yy > m) continue;
            if(dis[xx][yy] != inf) continue;
            q.push({xx,yy});
            dis[xx][yy] = dis[x][y] + 1;
        }
    }
}

bool check(int tag){
    long long U_low = 2, U_high = n + m;
    long long V_low = 1 - m, V_high = n - 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dis[i][j] > tag){
                long long u = i + j;
                long long v = i - j;
                U_low  = max(U_low,  u - tag);
                U_high = min(U_high, u + tag);
                V_low  = max(V_low,  v - tag);
                V_high = min(V_high, v + tag);
            }
        }
    }
    if(U_low > U_high || V_low > V_high) return false;
    for(int p = 0; p < 2; p++){
        long long u0 = U_low + ((p - (U_low & 1) + 2) % 2);
        if(u0 > U_high) continue;
        long long v0 = V_low + ((p - (V_low & 1) + 2) % 2);
        if(v0 > V_high) continue;
        long long x0 = (u0 + v0) / 2;
        long long y0 = (u0 - v0) / 2;
        if(x0 >= 1 && x0 <= n && y0 >= 1 && y0 <= m) return true;
    }
    return false;
}

int js(){
    int l = 0, r = n + m;
    while(l + 1 < r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    return check(l) ? l : l + 1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    tmp.resize(n + 3);
    for(int i = 0; i <= n + 2; i++) tmp[i].assign(m + 3, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> tmp[i][j];
        }
    }
    bool flag = false;
    if(n < m){
        swap(n, m);
        flag = true;
    }
    a.resize(n + 3);
    dis.resize(n + 3);
    c1.resize(n + m + 3);
    c2.resize(n + m + 3);
    for(int i = 0; i <= n + 2; i++){
        a[i].assign(m + 3, 0);
        dis[i].assign(m + 3, 0);
    }
    for(int i = 0; i <= n + m + 2; i++){
        c1[i].assign(m + 3, 0);
        c2[i].assign(m + 3, 0);
    }
    if(flag){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                a[i][j] = tmp[j][i];
            }
        }
    } else {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                a[i][j] = tmp[i][j];
            }
        }
    }

    bfs();
    cout << js() << "\n";
    return 0;
}

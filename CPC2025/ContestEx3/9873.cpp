#include <bits/stdc++.h>

typedef long long LL;
const int N = 1e6 + 7;

int n, m, a[N], b[N];

void solve() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= m; i++) scanf("%d", b + i);

    std::sort(a + 1, a + n + 1);
    std::sort(b + 1, b + m + 1);



    int exploded = 0;

    int cnt(0);

#define N n
if(a[1] == 1)--a[1], ++cnt;
    for(int i = 1; i <= N; ++i)if(a[i] > 1)++cnt, --a[i];
    
    
    int p1 = 1, p2 = 1;
    // int p1_1(1), p1_2(1), p2(1);
    bool suc(true);
    while(p2 <= m){
        if(!suc)break;
        while(a[p1] <= exploded && p1 <= N)++p1, ++exploded;
        while(b[p2] > exploded && cnt >= 0)--b[p2], --cnt;
        if(cnt < 0)suc = false;
        ++p2, ++exploded; 
        // // if(b[p2] <= exploded){++exploded, ++p2; continue;}
        // // while(b[p2] > exploded){
        // //     if(p1_2 > n){suc = false; break;}
        // //     if(a[p1_2] == 1){
        // //         if(p1_2++ != 1)++exploded;
        // //         else {a[p1_2 - 1]--;continue;}
                
        // //     }
        // //     --b[p2];
        // //     --a[p1_2++];
        // //     while(p1_1 < p1_2){
        // //         if(a[p1_1] == 1){++p1_1; continue;}
        // //         if(a[p1_1] <= exploded)++exploded, ++p1_1;
        // //         else break;
        // //     }
        // }
        // if(b[p2] <= exploded)++exploded, ++p2;
        // else suc = false;
    //     for(int i = 1; i <= n; i++) printf("%d ", a[i]); printf("\n");
    // for(int i = 1; i <= m; i++) printf("%d ", b[i]); printf("\n");
        // printf("cur p1 = %d, %d  p2 = %d   exp = %d\n", p1_1, p1_2, p2, exploded);
    }
    printf("%s\n", suc ? "Yes" : "No");
}

int main() {
    int T; scanf("%d", &T); while(T--) solve();
    return 0;
}
#include <bits/stdc++.h>

const int N = 2e5 + 7;

int a[N], cnt[10][N];

int main() {
    for(int n = 1; n <= 8; n++) {
        for(int i = 1; i <= n; i++) a[i] = i, cnt[n][i] = 0;

        do {
            std::stack<int> stk;
            for(int i = 1; i <= n; i++) {
                while(!stk.empty() && stk.top() > a[i]) stk.pop();
                stk.push(a[i]);
            }
            cnt[n][stk.size()]++;
        } while(std::next_permutation(a + 1, a + n + 1));

        for(int i = 1; i <= n; i++) printf("%5d%c", cnt[n][i], " \n"[i == n]);
    }
    for(int tim = 1; tim <= 8; ++tim){
        printf("tims = %d\n", tim);
        int curx = 5, cury = 1;
        for(int j = 8 - curx; j >= 1; --j){
            cnt[curx + j][cury + j] -= cnt[curx + j - 1][cury + j - 1];
        }
        for(int n = 1; n <= 8; n++)for(int i = 1; i <= n; i++) printf("%5d%c", cnt[n][i], " \n"[i == n]);
    }
    return 0;
}
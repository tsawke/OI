#include <bits/stdc++.h>

using namespace std;

int read(void){
    int ret(0), flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c))ret *= 10, ret += int(c - '0'), c = getchar();
    return ret * flag;
}
int card[5];
int t[7];

bitset < 5 > exist;


int mx(0);
void dfs(int dep = 1){
    // printf("In dfs dep = %d\n", dep);
    if(dep == 7){
        int ret(0);
        for(int i = 1; i <= 4; ++i)ret += card[i] / 5;

        // printf("status: ");
        // for(int i = 1; i <= 4; ++i)printf("%d ", card[i]);
        // printf(", ret = %d\n", ret);

        mx = max(mx, ret);

        return;
    }
    if(dep <= 4){
        dfs(dep + 1);
        if(t[dep]){
        // for(int c = 1; c <= 4; ++c){
            basic_string < int > idx;
            for(int i = 1; i <= 4; ++i)
                if(i != dep)idx += i;
            // for(int i = 0; i <= 2; ++i)printf("idx[%d] = %d\n", i, idx[i]);
            for(int i = 0; i <= card[idx[0]]; ++i){
                for(int j = 0; i + j <= 3 && j <= card[idx[1]]; ++j){
                    for(int k = 0; k <= 3 - i - j; ++k){
                        if(k > card[idx[2]])continue;
                        card[idx[0]] -= i;
                        card[idx[1]] -= j;
                        card[idx[2]] -= k;
                        card[dep] += i + j + k;
                        dfs(dep + 1);
                        card[idx[0]] += i;
                        card[idx[1]] += j;
                        card[idx[2]] += k;
                        card[dep] -= i + j + k;
                    }
                }
            }
        }
        // }
    }
    if(dep == 5){
        dfs(dep + 1);
        if(t[dep])
        for(int i = 1; i <= 4; ++i){
            if(!card[i])continue;
            for(int j = 1; j <= 4; ++j){
                if(i == j)continue;
                ++card[j], --card[i];
                dfs(dep + 1);
                --card[j], ++card[i]; 
            }
        }
    }
    if(dep == 6){
        dfs(dep + 1);
        if(t[dep])
        for(int i = 1; i <= 4; ++i){
            if(!card[i])continue;
            for(int j = 1; j <= 4; ++j){
                if(i == j || (!exist[j] && !t[5]))continue;
                ++card[j], --card[i];
                dfs(dep + 1);
                --card[j], ++card[i];
            }
        }
    }
}


int main(){
    // freopen("1.in", "r", stdin);
    int T = read();
    while(T--){

        

        // memset(dp, 0, sizeof dp);

        int N = read();
        
        memset(card, 0, sizeof card);
        exist.reset();
        
        for(int i = 1; i <= N; ++i){
            char c = getchar();
            while(!isdigit(c) && !isupper(c))c = getchar();
            c = getchar();
            // printf("Drop c = %c\n", c);
            while(!isupper(c))c = getchar();
            if(c == 'D')++card[1], exist[1] = true;
            if(c == 'C')++card[2], exist[2] = true;
            if(c == 'H')++card[3], exist[3] = true;
            if(c == 'S')++card[4], exist[4] = true;
            // printf("Get char c = %c\n", c);
            
        }

// int t[7];
            for(int i = 1; i <= 6; ++i)t[i] = read();
        int ans(0);
            for(int i = 1; i <= 4; ++i){
                ans += card[i] / 5;
                card[i] %= 5;
            }
            // for(int i = 1; i <= 4; ++i)printf("card[%d] = %d\n", i, card[i]);
            
            // ans += D / 5, D %= 5;
            // ans += C / 5, C %= 5;
            // ans += H / 5, H %= 5;
            // ans += S / 5, S %= 5;

            mx = 0;

            

            dfs();
            
            printf("%d\n", ans + mx);
    }





    return 0;
}
/*

4
5
2H 3H 4H 5H 6D
1 1 1 1 0 0
5
2S 3S 4D 5C 6D
0 0 1 0 1 1
5
2S 3S 4D 5C 6D
0 0 1 0 1 0
13
AS 2S 3S 4S 5H 6H 7H 8H 9H TH JH QH KH
0 0 0 0 0 1

*/
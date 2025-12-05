





//trash

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// #define int ll

// template<typename T = int>
// inline T read(void);

// int N;
// int a[10];
// int anss[10];
// int dfs(int, int, int);
// signed main(){
//     N = read();
//     for(int i = 1; i <= N; ++i)a[i] = read();
//     int ans(1);
//     for(int i = 1; i <= N; ++i)anss[i] = dfs(i, 1, 0), ans *= anss[i];
//     int S0 = (1 << N) - 1;
//     for(int S = S0; S; S = (S - 1) & S0){
//         int cur(1), flag(1);
//         for(int i = 1; i <= N; ++i){
//             if(S & (1 << (i - 1))){
//                 cur *= anss[i];
//                 flag = flag == 1 ? -1 : 1;
//             }
//         }
//         ans += cur * flag;
//     }
//     printf("%lld\n", ans);

//     return 0;
// }
// int dfs(int i, int times, int curSco){
//     if(times > N)return curSco == a[i] ? 1 : 0;
//     int ret(0);
//     ret += dfs(i, times + 1, curSco + 0);
//     ret += dfs(i, times + 1, curSco + 1);
//     ret += dfs(i, times + 1, curSco + 3);
//     return ret;
// }


// template<typename T>
// inline T read(void){
//     T ret(0);
//     short flag(1);
//     char c = getchar();
//     while(c != '-' && !isdigit(c))c = getchar();
//     if(c == '-')flag = -1, c = getchar();
//     while(isdigit(c)){
//         ret *= 10;
//         ret += int(c - '0');
//         c = getchar();
//     }
//     return (T)(ret * flag);
// }
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char S1[110000], S2[110000];
int a[110000], b[110000];
int ans[1100000];
int main(){
    gets(S1);
    gets(S2);
    int L1 = strlen(S1);
    int L2 = strlen(S2);
    for(int i = 0; i < L1; ++i)a[i + 1] = S1[L1 - i - 1] - '0';
    for(int i = 0; i < L2; ++i)b[i + 1] = S2[L2 - i - 1] - '0';
    int Lans = L1 + L2;
    for(int i = 1; i <= L1; ++i){
        for(int j = 1; j <= L2; ++j){
            ans[i + j - 1] += a[i] * b[j];
            ans[i + j] += ans[i + j - 1] / 10;
            ans[i + j - 1] %= 10;
        }
    }
    while(!ans[Lans] && Lans)--Lans;
    for(int i = Lans; i >= 1; --i)printf("%d", ans[i]);
    printf("\n");
//    char ct = getchar();
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char S1[110000], S2[110000];
int a[110000], b[110000];
int ans[110000];
void Swap();
int main(){
    gets(S1);
    gets(S2);
    int L1 = strlen(S1);
    int L2 = strlen(S2);
    if(!strcmp(S1, S2)){printf("0\n"); return 0;}
    if(L1 < L2 || (L1 == L2 && strcmp(S1, S2) < 0))Swap();
    for(int i = 0; i < L1; ++i)a[i + 1] = S1[L1 - i - 1] - '0';
    for(int i = 0; i < L2; ++i)b[i + 1] = S2[L2 - i - 1] - '0';
    int Lans = L1;
    for(int i = 1; i <= L1; ++i){
        if(a[i] < b[i]){
            a[i] += 10;
            --a[i + 1];
        }
        ans[i] = a[i] - b[i];
    }
    while(!ans[Lans] && Lans)--Lans;
    for(int i = Lans; i >= 1; --i)printf("%d", ans[i]);
    printf("\n");
//    char ct = getchar();
    return 0;
}
void Swap(){
    char c[110000];
    strcpy(c, S1);
    strcpy(S1, S2);
    strcpy(S2, c);
    printf("-");
}
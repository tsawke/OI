#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000010];
int n, m;
int main(){
    scanf("%d%d", &n, &m);
    a[n] = 1;
    for(int i = 1; i < n; ++i)a[i] = i + 1;
    int now = n; int j = 1;
    for(int i = 1; i <= n; ++i){
        while(j < m){now = a[now]; ++j;}
        printf("%d ", a[now]);
        a[now] = a[a[now]];
        j = 1;
    }printf("\n");
    char c = getchar(); c = getchar();
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int a, n;
int q[1000100];
int main(){
    while(scanf("%d%d", &a, &n) != EOF){
//        queue<int>q;
        int tail(1);
        q[1] = a;
        int x(1), y(1);
        while(tail < n){
            int t1 = q[x] * 2 + 1, t2 = q[y] * 3 + 1;
            int temp = min(t1, t2);
            if(t1 < t2)++x; else ++y;
            if(temp == q[tail])continue;
            q[++tail] = temp;
        }
        printf("%d\n", q[n]);
    }
    char c = getchar(); c = getchar();
    return 0;
}
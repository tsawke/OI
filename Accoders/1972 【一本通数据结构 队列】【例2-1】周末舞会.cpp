#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int a, b;
int n;
int main(){
    scanf("%d%d%d", &a, &b, &n);
    queue<int>q1;
    queue<int>q2;
    for(int i = 1; i <= a; ++i)q1.push(i);
    for(int i = 1; i <= b; ++i)q2.push(i);
    for(int i = 1; i <= n; ++i){
        printf("%d %d\n", q1.front(), q2.front());
        q1.push(q1.front());
        q2.push(q2.front());
        q1.pop();
        q2.pop();
    }
    char c = getchar(); c = getchar();
    return 0;
}
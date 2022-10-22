#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int rd(int x) {
    return rand() % (x - 1) + 1;
}
int rd(int l, int r) {
    return rand() % (r - l + 1) + l;
}
int n, m;
int main() {
    srand(time(NULL));
    n = rd(30);
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", rd(-100, 100));
    }
    m = rd(30);
    printf("\n%d\n", m);
    for (int i = 1, l, r; i <= m; i++) {
        l = rd(n), r = rd(n);
        if (r < l) swap(l, r);
        printf("%d %d\n", l, r);
    }
    return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int k;
int a[110000];
void search(int, int);
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)scanf("%d", a + i);
    scanf("%d", &k);
    search(1, n);
    for(int i = 1; i <= k; ++i)printf("%d\n", a[i]);
//    char c = getchar(); c = getchar();
    return 0;
}
void search(int left, int right){
    int mid = a[(left + right) / 2];
    int l = left, r = right;
    while(l <= r){
        while(a[l] > mid)++l;
        while(a[r] < mid)--r;
        if(l <= r){
            swap(a[l], a[r]);
            ++l;
            --r;
        }
    }
    if(l < right)search(l, right);
    if(left < r)search(left, r);
}
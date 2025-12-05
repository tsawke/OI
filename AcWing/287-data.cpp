#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("./287-data.in", "w", stdout);
    srand(unsigned(time(NULL)));
    int size = 100000;
    printf("1\n%d\n", size);
    for(int i = 1; i <= size - 1; ++i){
        printf("%d %d %d\n", 1, i + 1, rand() % 1000 + 1);
    }
    return 0;
}
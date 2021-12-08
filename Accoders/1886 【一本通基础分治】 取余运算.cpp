#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long unll;
unll a, b, c;
unll calculate(unll, unll, unll);
int main(){
    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%lld\n", calculate(a, b, c));
//    char c = getchar(); c = getchar();
    return 0;
}
unll calculate(unll value, unll indexNum, unll mod){
    unll ans(1);
    while(indexNum){
        if(indexNum & 1){
            ans *= value;
            ans %= mod;
        }
        value *= value;
        value %= mod;
        indexNum >>= 1;
    }
    return ans;
}
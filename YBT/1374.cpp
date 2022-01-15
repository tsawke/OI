#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <map>
#include <unistd.h>
#include <functional>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int main(){
	read(), read();
    int fX, fY, tX, tY;
    double route(0.00000);
    while(scanf("%d%d%d%d", &fX, &fY, &tX, &tY) != EOF){
        route += sqrt(abs(tX - fX) * 1.00000 * abs(tX - fX) * 1.00000 + abs(tY - fY) * 1.00000 * abs(tY - fY) * 1.00000) * 1.00000;
    }
    route *= 2.000000;
    // printf("route: %f\n", route);
    const double km_hV = 20.000000;
    const double m_sV = km_hV / 3.600000;
    const double m_minV = m_sV * 60.0000;
    double time = route * 1.000000 / m_minV * 1.00000;
    int ntime = ceil(time);
    // printf("min/s - %f\ntime - %f\nntime - %d\n", m_minV, time, ntime);
    printf("%d:%d\n", ntime / 60, ntime % 60);

    return 0;
}

template <typename T = int>
inline T read(void)
{
	T ret(0);
	short flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10, ret += (c - '0');
		c = getchar();
    }
    ret *= flag;
	return ret;
}
#include <cstdio>55
#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;
int h(0), m(0), s(0);
int in_s;
int main(){scanf("%d", &in_s);
	h = in_s / 3600;
	in_s %= 3600;
	m = in_s / 60;
	in_s %= 60;
	s = in_s;
	printf("%d\n%d\n%d\n", h, m, s);

	return 0;
}


#pragma warning(disable:4996)
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
char c[1100];
int k;
int ans(0);
int getDifferentWordsNum(char*, int);
bool checkEditStr(char*, int, int);
int main() {
	cin.getline(c + 1, sizeof(c));
	scanf("%d", &k);
	int len = strlen(c + 1);
	for (int n = 2; n <= len; ++n) {
		for (int i = 1; i <= len - n + 1; ++i) {
			char s[1100];
			int now(0);
			s[++now] = c[i];
			for (int j = i + 1, sum = 1; sum < n; ++j, ++sum)
				s[++now] = c[j];
			if (checkEditStr(s, now, k))++ans;
		}
	}
	ans += len;
	printf("%d\n", ans);
	return 0;
}
int getDifferentWordsNum(char* c, int len) {
	int sum(0);
	for (int i = 1, j = len; i <= len / 2; ++i, --j)
		if (c[i] != c[j])++sum;
	return sum;
}
bool checkEditStr(char* c, int len, int k) {
	int n = getDifferentWordsNum(c, len);
	//	printf("\nN = %d\n", n);
	return k >= n;
}
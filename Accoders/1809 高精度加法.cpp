#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S1[111100], S2[111100];
int L1, L2;
int f[111100], l[111100], ans[111100];

int main()
{
	gets(S1); gets(S2);
	int L1 = strlen(S1); L2 = strlen(S2);
	for(int i = L1 - 1, j = 0; i >= 0; i-- && j++) f[j] = S1[i] - '0';
	for(int i = L2 - 1, j = 0; i >= 0; i-- && j++) l[j] = S2[i] - '0';
	for(int i = 0; i <= max(L1, L2) - 1; i++){
		ans[i] += f[i] + l[i];
		if(ans[i] >= 10){ans[i] -= 10; ++ans[i + 1];}
	}
	int lans = max(L1, L2);
	if(ans[lans] != 0)++lans;
	for(int i = lans - 1; i >= 0; i--)printf("%d",ans[i]); puts("");
	return 0;
}

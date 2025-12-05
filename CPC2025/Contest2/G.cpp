#include<bits/stdc++.h>
using namespace std;

#define For(i,l,r) for(int i=l;i<=r;i++)
#define ll long long

ll n,m,a[1000][1000], flag[1000], cnt;

int main(){
	cin >> n;
	
	m = (n / 16 + 1);
	For(i,1,n){
		For(j,1,n){
			a[i][j] =  m * (i / 16) + (j / 9 + 1);
			// cout << a[i][j] << ' ';
		}
		// cout << endl;
	}

    unordered_set < int > s;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            s.insert(a[i][j]);
    printf("%d\n", s.size());
    if(s.size() > 10 + int(n * n / 100))printf("err\n"), exit(0);
	// For(i,1,1000){
	// 	if((i/16+1)*(i/9+1) > 10+ (i*i/100))
	// 		cout << "gigilele" << endl;
	// }
	
	// For(i,1,n)
	// 	For(j,1,n){
	// 		For(p,1,(n / 16 + 1)*(n / 9 + 1))
	// 			flag[p] = false;
	// 		flag[a[i][j]] = true;
	// 		cnt = 1;
	// 		For(k,1,n)
	// 			For(l,1,n)
	// 				if((k-i)*(k-i)+(j-l)*(j-l) <= 100){
	// 					if(flag[a[k][l]] == false){
	// 						flag[a[k][l]] = true;
	// 						cnt++;
	// 					}
	// 				}	
	// 		if(cnt > 8) cout << "jile" << endl;
	// 	}
}
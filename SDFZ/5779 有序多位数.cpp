#include <cstdio>
#include <algorithm>
using namespace std;
int K,X,Y; int num[3100]; int sum=1;
void round(int f,int l){
	int end=(f+l)/2;
	if((f+l)%2==0)end--;
	for(int i=f,j=l; i<=end; i++,j--){
		swap(num[i],num[j]);
	}
}
void InIt(int k,int x,int y,int &sum){
	for(int i=1; sum<=max(max(x,y),k)+1; i++){int t=i;
		int first=sum;
		while(t>0){
			num[sum]=t%10;
			t/=10; sum++;
		}int last=sum-1;
		round(first,last);
	}
}
int Printsum(int x,int y){int summ=0;
	for(int i=x; i<=y; i++){
		summ+=num[i];
	}return summ;
}
int main(){scanf("%d%d%d",&K,&X,&Y);
	
	InIt(K,X,Y,sum);
	printf("%d\n%d\n",num[K],Printsum(X,Y));
	return 0;
}


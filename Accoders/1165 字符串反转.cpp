//1165 ×Ö·û´®·´×ª
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int N;
	char str[100001];
	int i,j,m;
	scanf("%d",&N); 
	getchar();
	while(N--)	{
		gets(str);
		if(str[0]=='\0')
			printf("\n");
		else
		{
			j=0;
			for(i=0;i<strlen(str);i++)
			{			
			if(str[i]=='  '){
				for(m=i-1;m>=j;m--)
					printf("%c",str[m]);
					printf(" ");
				j=i+1;
							}
			}
			for(m=i;m>=j;m--)
				printf("%c",str[m]);
				printf("\n");
		}
	}
	return 0;
}


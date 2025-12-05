#include <cstdio>
#include <algorithm>
using namespace std;
int n1,n2,n3,n4; int sum=0;
bool stone[21000]={false};
int i1,j2,k5,l10; 
int main(){scanf("%d%d%d%d",&n1,&n2,&n3,&n4);
/*	if(n1>=10 || (n2>=5 && n1!=0))printf("%d\n",n1+n2*2+n3*5+n4*10);
	else{
		
	}*/




	

	i1=j2=k5=l10=1;
	if(n1)stone[1]=true;
	if(n2)stone[2]=true;
	if(n3)stone[5]=true;
	if(n4)stone[10]=true;
	if(!n1){n1++; i1=0;}
	if(!n2){n2++; j2=0;}
	if(!n3){n3++; k5=0;}
	if(!n4){n4++; l10=0;}
	
	for(int i=1; i<=n1; i++){
		for(int j=1; j<=n2; j++){
			for(int k=1; k<=n3; k++){
				for(int l=1; l<=n4; l++){
					stone[i*1*i1+j*2*j2+k*5*k5+l*10*l10]=true;
					stone[i*1*i1+j*2*j2+k*5*k5-l*10*l10]=true;
					stone[i*1*i1+j*2*j2-k*5*k5+l*10*l10]=true;
					stone[i*1*i1+j*2*j2-k*5*k5-l*10*l10]=true;
					stone[i*1*i1-j*2*j2+k*5*k5+l*10*l10]=true;
					stone[i*1*i1-j*2*j2+k*5*k5-l*10*l10]=true;
					stone[i*1*i1-j*2*j2-k*5*k5+l*10*l10]=true;
					stone[i*1*i1-j*2*j2-k*5*k5-l*10*l10]=true;
					stone[-i*1*i1+j*2*j2+k*5*k5+l*10*l10]=true;
					stone[-i*1*i1+j*2*j2+k*5*k5-l*10*l10]=true;
					stone[-i*1*i1+j*2*j2-k*5*k5+l*10*l10]=true;
					stone[-i*1*i1+j*2*j2-k*5*k5-l*10*l10]=true;
					stone[-i*1*i1-j*2*j2+k*5*k5+l*10*l10]=true;
					stone[-i*1*i1-j*2*j2+k*5*k5-l*10*l10]=true;
					stone[-i*1*i1-j*2*j2-k*5*k5+l*10*l10]=true;
					stone[-i*1*i1-j*2*j2-k*5*k5-l*10*l10]=true;
				}
			}
		}
	}
	for(int i=1; i<=20000; i++)if(stone[i])sum++;
	printf("%d\n",sum);
	return 0;
}


#include <stdio.h>
#include <string.h>
char a[50],b[50];
 
int cal(char *src, int ilen, int pos , int num, int d)
{
    int ret = 0, e = 1;
    for(int i = ilen - 1 ; i >= 0 ; i --)
    {
        if(i == pos)
        {
            ret += num * e; 
        }else
        {
            ret+= (src[i] - '0') * e;   
        } 
        e *= d;
    }
    return ret;
}
int main()
{
    scanf("%s%s",a,b);
    int ilen_a = strlen(a);
    int ilen_b = strlen(b);
     
    for(int i = 0 ; i < ilen_a ; i ++)
    {
        for(int j = 0 ; j < ilen_b ; j ++)
        {
            for(int k = 1 ; k <= 2 ; k ++)
            {
                int num1 = cal(a, ilen_a, i, (a[i] - '0') ^ 1, 2);
                int num2 = cal(b, ilen_b, j, ((b[j] - '0') + k) % 3, 3);
                if(num1 == num2)
                {
                    printf("%d\n",num1);
                    return 0;
                }
            }
        }
    }
}

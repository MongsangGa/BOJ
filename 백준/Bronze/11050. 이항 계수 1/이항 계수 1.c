#include <stdio.h>
#include <stdlib.h>
int Fac(int N){
    int result=1;
    for(int i=1;i<=N;i++)
        result*=i;
    return result;
}
int main()
{
    int N,M,result=0;
    scanf("%d %d",&N,&M);
    result=Fac(N)/(Fac(M)*Fac(N-M));
    printf("%d",result);
    return 0;
}
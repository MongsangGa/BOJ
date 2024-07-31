#include <stdio.h>
#include <stdlib.h>
function(int N){
    int one=N/10;
    int two=N%10;
    return (two*10)+(one+two)%10;
}
int main()
{
    int N,temp,cnt=0;
    scanf("%d",&N);
    temp=N;
    while(1){
        cnt++;
        temp=function(temp);
        if(temp==N) break;
    }
    printf("%d",cnt);
    return 0;
}

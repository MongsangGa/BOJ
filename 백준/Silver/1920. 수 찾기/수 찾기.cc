#include<stdio.h>
#include<algorithm>
using namespace std;
int N,M,c,left,mid,right,chk,A[100001]={0};
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&A[i]);
    sort(A,A+N);
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        left=chk=0,right=N-1;
        scanf("%d",&c);
        while(left<=right){
            mid=(left+right)/2;
            if(A[mid]==c){
                chk=1;
                break;
            }
            else if(A[mid]>c) right=mid-1;
            else if(A[mid]<c) left=mid+1;
        }
        if(chk==1) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
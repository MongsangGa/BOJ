#include <bits/stdc++.h>
using namespace std;
#define MAX 300001
int n,m,res;
long long int A[MAX],B;
int binary(long long int target){
    int left,right,mid;
    left=0, right=m-1;
    if(target>A[m-1]) return -1;
    while(left<=right){
        mid=(left+right)/2;
        if(target==A[mid]) return mid;
        else if(target<A[mid]) right=mid-1;
        else if(target>A[mid]) left=mid+1;
    }
    for(int i=mid;i<m;i++)
        if(target<=A[i])
            return i;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%lld", &A[i]);
        A[i]+=A[i-1];
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&B);
        res=binary(B);
        if(res==-1) printf("Go away!\n");
        else printf("%d\n",res+1);
    }
    return 0;
}

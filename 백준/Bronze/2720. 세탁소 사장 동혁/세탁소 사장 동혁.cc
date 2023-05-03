#include <bits/stdc++.h>
using namespace std;
int t,a;

int main(){
    scanf("%d",&t);
    while(t--){
        int one, two, thr, four;
        one=two=thr=four=0;
        scanf("%d",&a);
        while(a>0){
            if(a>=25) one++, a-=25;
            else if(a>=10) two++, a-=10;
            else if(a>=5) thr++, a-=5;
            else if(a>=1) four++, a-=1;
        }
        printf("%d %d %d %d\n",one, two, thr ,four);
    }
    return 0;
}

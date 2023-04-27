#include <bits/stdc++.h>
using namespace std;
long long int n;
int main(){
    scanf("%lld",&n);
    printf("%lld\n",(n-1)*(n-1));
    for(int i=2;i<=n;i++)
        printf("1 %d\n",i);
    return 0;
}

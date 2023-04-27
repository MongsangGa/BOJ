#include <bits/stdc++.h>
using namespace std;
char str[2001];
int n,res;
int main() {
    scanf("%d",&n);
    scanf("%s",str);
    for(int i=1;i<=n;i++){
        res=0;
        for(int j=0;j<i;j++) 
            res += str[j] != str[n + j - i];
        if(res==1){
            printf("YES");
            exit(0);
        }
    }
    printf("NO");
    return 0;
}
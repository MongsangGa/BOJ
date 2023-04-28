#include <bits/stdc++.h>
using namespace std;
int n,open;
char str[21];
bool check(){
    int open=0;
    for(int i=0;i<n;i++){
        if(str[i]=='(') open++;
        else open--;
    }
    if(!open){
        printf("%s",str);
        exit(0);
    }
    return false;
}
void solve(int depth){
    if(depth==n && !check())
        return;
    if(str[depth]=='G'){
        str[depth]='(';
        solve(depth+1);
        str[depth]=')';
        solve(depth+1);
    }
    solve(depth+1);
}
int main(){
    scanf("%d%s",&n,str);
    solve(0);
    return 0;
}
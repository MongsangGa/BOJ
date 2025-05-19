#include <iostream>
using namespace std;
int N,M,arr[9],check[9];
int solve(int x){
    if(x==M){
        for(int i=0;i<M;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return 0;
    }
    for(int i=1;i<=N;i++){
        if(!check[i]){
            check[i]=1;
            arr[x]=i;
            solve(x+1);
            check[i]=0;
        }
    }
    return 0;
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    solve(0);
    return 0;
}

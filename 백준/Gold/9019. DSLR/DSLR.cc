#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
int t,a,b;
bool check[MAX];
void bfs(int a, int b){
    queue<pair<int, string>> q;
    q.push({a,""});
    while(!q.empty()){
        int D,S,L,r,cur_num;
        string cur_str;
        cur_num=q.front().first;
        cur_str=q.front().second;
        q.pop();
        if(cur_num==b){
            cout<<cur_str<<'\n';
            return;
        }
        //D
        D=cur_num*2;
        if(D>9999)
            D%=10000;
        if(!check[D]) {
            check[D]=1;
            q.push({D, cur_str + 'D'});
        }
        //S
        S=cur_num-1;
        if(S<0)
            S=9999;
        if(!check[S]) {
            check[S]=1;
            q.push({S, cur_str + 'S'});
        }
        //L
        L=(cur_num%1000)*10+cur_num/1000;
        if(!check[L]) {
            check[L]=1;
            q.push({L, cur_str + 'L'});
        }
        //R
        r=(cur_num/10)+(cur_num%10)*1000;
        if(!check[r]) {
            check[r]=1;
            q.push({r, cur_str + 'R'});
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>a>>b;
        memset(check,0,sizeof(check));
        bfs(a, b);
    }
    return 0;
}
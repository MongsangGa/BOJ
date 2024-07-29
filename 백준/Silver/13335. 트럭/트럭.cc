#include <bits/stdc++.h>
using namespace std;
int truck[1001],n,w,l,res,sec;
queue<int> q;
int main(){
    scanf("%d%d%d",&n,&w,&l);
    for(int i=0;i<n;i++) scanf("%d",&truck[i]);
    res=sec=0;
    for(int i=0;i<n;i++){
        while(1){
            if(q.size()>=w){
                res-=q.front();
                q.pop();
            }
            if(res+truck[i]<=l) break;
            q.push(0);
            sec++;
        }
        q.push(truck[i]);
        res+=truck[i];
        sec++;
    }
    printf("%d",sec+w);
    return 0;
}

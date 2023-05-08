#include <bits/stdc++.h>
using namespace std;
int n,res=1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d",&n);
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&v[i].second,&v[i].first); // end, start
    sort(v.begin(),v.end());
    int beforetime=v[0].first;
    for(int i=1;i<n;i++){
        if(beforetime>v[i].second) continue;
        res++;
        beforetime=v[i].first;
    }
    printf("%d",res);
    return 0;
}

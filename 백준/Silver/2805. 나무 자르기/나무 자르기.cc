#include <bits/stdc++.h>
using namespace std;
long long int n,m,sum,res=-1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    // mid는 절단기의 높이
    long long int left=0, right=v[n-1], mid;
    while(left<=right){
        mid=(left+right)/2, sum=0;
        for(int i=0;i<n;i++)
            if(v[i]-mid>0)
                sum+=v[i]-mid;
        if(sum>=m){
            res=max(res,mid);
            left=mid+1;
        }
        else right=mid-1;
    }
    cout<<res;
    return 0;
}

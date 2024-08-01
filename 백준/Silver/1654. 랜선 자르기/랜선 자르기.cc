#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int K,N,a,res=0;
vector<long long int> v;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>K>>N;
    for(int i=0;i<K;i++) {
            cin>>a;
            v.push_back(a);
    }
    sort(v.begin(),v.end());
    long long int left=1,right=v[K-1],mid;
    while(left<=right){
        int cnt=0;
        mid=(left+right)/2;
        for(int i=0;i<v.size();i++)
            cnt+=v[i]/mid;
        if(cnt>=N){
             res=max(res,mid);
             left=mid+1;
        }
        else right=mid-1;
    }
    cout<<res;
    return 0;
}

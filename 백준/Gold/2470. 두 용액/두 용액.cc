#include <bits/stdc++.h>
using namespace std;
int n,a;
long long int res=1e11+1;
pair<int,int> p;
int main(){
    scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)
        scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    int left=0, right=n-1;
    while(left<right) {
        if(res==0) break;
        long long int sum=v[left]+v[right];
        if (abs(sum)<res){
            res=abs(sum);
            p.first = v[left], p.second = v[right];
        }
        if(sum>0) right--;
        else if(sum<0) left++;
    }
    printf("%d %d",p.first, p.second);
    return 0;
}

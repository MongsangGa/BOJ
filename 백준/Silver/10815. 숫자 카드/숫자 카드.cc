#include <bits/stdc++.h>
using namespace std;
int n,m,a,left,right,mid;
vector<int> v;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        bool is=0;
        scanf("%d",&a);
        int left=0,right=n-1;
        while(left<=right){
            mid=(left+right)/2;
            if(v[mid]==a) {
                printf("1 ");
                is=true;
                break;
            }
            else if(v[mid]>a) right=mid-1;
            else if(v[mid]<a) left=mid+1;
        }
        if(!is) printf("0 ");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000001
vector<ll> A(MAX);
vector<ll> B(MAX);
vector<ll> segmant(MAX*4);
int n,a;
ll res;
int sum(int node, int start, int end, int left, int right){
    if(start>right || left>end) return 0;
    if(left<=start && end<=right) return segmant[node];
    int mid=(start+end)/2;
    return sum(node*2,start,mid,left,right) + sum(node*2+1,mid+1,end,left,right);
}
void update(int node, int start, int end, int index, int diff){
    if(index<start || index>end) return;
    segmant[node]+=diff;
    if(start!=end){
        int mid=(start+end)/2;
        update(node*2,start,mid,index,diff);
        update(node*2+1,mid+1,end,index,diff);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    // index to A B
    for(int i=1;i<=n;i++){
        cin>>a;
        A[a]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>a;
        B[i]=A[a];
    }
    for(int i=1;i<=n;i++){
        int target=B[i];
        res+=sum(1,1,n,target+1,n);
        update(1,1,n,target,1);
    }
    cout<<res;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000001
vector<ll> segmant(MAX*4);
vector<ll> arr(MAX);
int n,a,b,c;
int find_N(int node, int start, int end, int k){
    if(start==end) return start;
    int mid=(start+end)/2;
    if(segmant[node*2]>=k) return find_N(node*2, start, mid, k);
    else return find_N(node*2+1, mid+1, end, k-segmant[node*2]);
}
void update(int node, int start, int end, int index, int diff){
    if(index<start || index>end) return;
    segmant[node]=segmant[node]+diff;
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
    while(n--){
        cin>>a;
        if(a==1){ // candy output
            cin>>b;
            int res=find_N(1,1,MAX,b);
            cout<<res<<'\n';
            arr[res]--;
            update(1,1,MAX,res,-1);
        }
        else{ // C candy input output
            cin>>b>>c;
            arr[b]+=c;
            update(1,1,MAX,b,c);
        }
    }
    return 0;
}

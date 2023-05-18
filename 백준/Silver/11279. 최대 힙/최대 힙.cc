#include<bits/stdc++.h>

using namespace std;

priority_queue<int> pq;
int t,n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        if(!n){
            if(!pq.empty()){
                cout<<pq.top()<<'\n';
                pq.pop();
            }
            else cout<<"0\n";
        }
        else pq.push(n);
    }
    cin.tie(NULL);

}

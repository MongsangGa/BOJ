#include <bits/stdc++.h>
using namespace std;
long long int n,k,temp;
string s;
int main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        s+=to_string(i);
        temp=stoll(s);
        if(temp>=k){
            temp%=k;
            s=to_string(temp);
        }
    }
    cout<<s;
    return 0;
}

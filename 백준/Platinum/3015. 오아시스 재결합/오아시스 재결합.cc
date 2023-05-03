#include <bits/stdc++.h>
using namespace std;
int n,now;
long long res;
stack<pair<int, int>> st;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    scanf("%d",&n);
    while(n--){
        scanf("%d",&now);
        int same_height=1;
        while(!st.empty() && st.top().first<now){
            res+=st.top().second;
            st.pop();
        }
        if(!st.empty()){
            if(st.top().first==now){
                if(st.size()>1) ++res;
                res+=st.top().second;
                same_height=(st.top().second)+1;
                st.pop();
            }
            else ++res;
        }
        st.push({now, same_height});
    }
    printf("%lld",res);
    return 0;
}

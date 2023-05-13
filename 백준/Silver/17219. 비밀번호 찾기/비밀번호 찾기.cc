#include <bits/stdc++.h>
using namespace std;
map<string, string> s;
int n,m;
string str1,str2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    while(n--){
        cin>>str1>>str2;
        s[str1]=str2;
    }
    while(m--){
        cin>>str1;
        cout<<s[str1]<<'\n';
    }
    return 0;
}

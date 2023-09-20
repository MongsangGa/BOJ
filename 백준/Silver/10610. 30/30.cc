#include <bits/stdc++.h>
using namespace std;
long long int sum;
string s;
int main(){
    cin>>s;
    sort(s.begin(),s.end(), greater<>());
    if(s[s.size()-1]!='0') cout<<"-1";
    else {
        for (auto i: s)
            sum += i - '0';
        if (!(sum % 3))
            cout << s;
        else cout << "-1";
    }
    return 0;
}

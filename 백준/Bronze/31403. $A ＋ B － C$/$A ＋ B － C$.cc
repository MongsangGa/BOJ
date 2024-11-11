#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
string a, b, c;

int main() {
    fastio;
    cin >> a >> b >> c;
    cout << stoi(a) + stoi(b) - stoi(c) << '\n' << stoi(a + b) - stoi(c);
    return 0;
}

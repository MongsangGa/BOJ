#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

int n, q;
string s;
map<string, int> m;
vector<string> v;

int main() {
    fastio;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> s;
        m[s] = i + 1;
        v.push_back(s);
    }
    while (q--) {
        cin >> s;
        if (isdigit(s[0])) {
            int num = stoi(s);
            cout << v[num - 1] << '\n';
        } else cout << m[s] << '\n';
    }
    return 0;
}


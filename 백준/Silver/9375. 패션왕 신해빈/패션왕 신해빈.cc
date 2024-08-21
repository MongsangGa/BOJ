#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

int t, n;
string s, c;

int main() {
    fastio;
    cin >> t;
    while (t--) {
        map<string, int> m;
        cin >> n;
        while (n--) {
            cin >> s >> c;
            m[c]++;
        }
        int res = 1;
        for (auto i: m) res *= i.second + 1;
        cout << res - 1 << '\n';
    }
    return 0;
}


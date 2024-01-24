#include <bits/stdc++.h>

using namespace std;

string s, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> s >> t) {
        int idx = 0;
        for (auto &c: t) {
            if (s[idx] == c)
                idx++;
        }
        if (idx == s.size()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

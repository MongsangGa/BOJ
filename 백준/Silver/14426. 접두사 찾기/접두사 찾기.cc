#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, m, res;
string str;
vector<string> s, f;

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str;
        s.push_back(str);
    }
    for (int i = 0; i < m; i++) {
        cin >> str;
        f.push_back(str);
    }
    sort(s.begin(), s.end());
    for (auto fs: f) {
        int idx = lower_bound(s.begin(), s.end(), fs) - s.begin();
        if (fs == s[idx].substr(0, fs.size())) ++res;
    }
    cout << res;
    return 0;
}

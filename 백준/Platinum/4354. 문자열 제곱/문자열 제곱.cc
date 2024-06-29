#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

string s;

vector<int> failure() {
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int match(int len) {
    int j = 0, ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[j]) return 0;
        j++;
        if (j == len) j = 0, ans++;
    }
    return ans;
}

int solve() {
    vector<int> f = failure();
    int res = 1, len = s.size();
    while (1) {
        len = f[len - 1];
        if (!len) break;
        if (s.size() % len) continue;
        int ans = match(len);
        res = max(res, ans);
    }
    return res;
}

int main() {
    fastio;
    cin >> s;
    while (s[0] != '.') {
        cout << solve() << '\n';
        cin >> s;
    }
    return 0;
}

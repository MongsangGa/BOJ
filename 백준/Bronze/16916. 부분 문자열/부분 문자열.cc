#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

string t, p;

vector<int> failure(string &s) {
    int l = s.size(), j = 0;
    vector<int> f(l);
    for (int i = 1; i < l; i++) {
        while (j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    fastio;
    getline(cin, t);
    getline(cin, p);
    vector<int> f = failure(p);
    int j = 0;
    for (int i = 0; i < t.size(); i++) {
        while (j > 0 && t[i] != p[j]) j = f[j - 1];
        if (t[i] == p[j]) {
            if (j == p.size() - 1) {
                cout << 1;
                exit(0);
            } else j++;
        }
    }
    cout << 0;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int l;
string s;
vector<int> f;

void failure() {
    f.resize(l);
    int j = 0;
    for (int i = 1; i < l; i++) {
        while (j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }
}

int main() {
    fastio;
    cin >> l >> s;
    failure();
    cout << l - f[l - 1];
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 1'000'002
int l, res;
char in[SIZE];
string n, m;

vector<int> failure(string &s) {
    int j = 0;
    vector<int> f(l);
    for (int i = 1; i < l; i++) {
        while (j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    fastio;
    cin >> l;
    for (int i = 0; i < l; i++) cin >> in[i];
    n = string(in);
    for (int i = 0; i < l; i++) cin >> in[i];
    m = string(in);
    vector<int> f = failure(m);
    int j = 0;
    for (int i = 0; i < 2 * l - 1; i++) {
        int ri = (i >= l) ? i - l : i;
        while (j > 0 && n[ri] != n[j]) j = f[j - 1];
        if (n[ri] == n[j]) ++j;
        if (j == l) ++res, j = f[j - 1];
    }
    cout << res / gcd(l, res) << '/' << l / gcd(l, res);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

int n;
vector<string> s;
vector<long long> v;

int main() {
    fastio;
    cin >> n;
    s.resize(n), v.resize(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        reverse(s[i].begin(), s[i].end());
        v[i] = stoll(s[i]);
    }
    sort(v.begin(), v.end());
    for (auto i: v) cout << i << '\n';
    return 0;
}

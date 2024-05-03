#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n;
vector<int> v;

int main() {
    fastio;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cout << v[(n - 1) / 2];
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n, l;
vector<int> v;

int main() {
    fastio;
    cin >> n >> l;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (v[i] <= l) ++l;
        else break;
    }
    cout << l;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int n, res;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = v.size() - 2; i >= 0; i--) {
        if (v[i] < v[i + 1]) continue;
        res += v[i] - v[i + 1] + 1;
        v[i] = v[i + 1] - 1;
    }
    cout << res;
    return 0;
}

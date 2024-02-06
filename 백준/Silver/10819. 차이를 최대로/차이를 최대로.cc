#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);

int n, res;

int main() {
    fastio;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    do {
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
            ans += abs(v[i] - v[i + 1]);
        res = max(res, ans);
    } while (next_permutation(v.begin(), v.end()));
    cout << res;
    return 0;
}

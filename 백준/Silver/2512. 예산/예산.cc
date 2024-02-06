#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);

int n, m, res;

int main() {
    fastio;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cin >> m;
    int st = 0, en = v[n - 1];
    while (st <= en) {
        int mid = (st + en) / 2;
        long long int sum = 0;
        for (int i = 0; i < n; i++) sum += min(v[i], mid);
        if (sum > m) en = mid - 1;
        else st = mid + 1, res = mid;
    }
    cout << res;
    return 0;
}

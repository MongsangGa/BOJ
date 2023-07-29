#include <bits/stdc++.h>

using namespace std;

#define MAX 1'000'000
vector<int> v, res;

int n, a, idx, arr[MAX], dp[MAX], len;

int main() {
    cin >> n;
    v.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > v.back()) {
            v.push_back(arr[i]);
            ++len;
            dp[i] = len;
        } else {
            idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[idx] = arr[i];
            dp[i] = idx;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i] == len) {
            res.push_back(arr[i]);
            --len;
        }
    }
    cout << res.size() << '\n';
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << ' ';
    }
    return 0;
}

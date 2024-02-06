#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define SIZE 2001

int n, arr[SIZE];
vector<int> v;

int main() {
    fastio;
    cin >> n;
    for (int i = n - 1; i >= 0; i--) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        if (v.empty() || v.back() < arr[i]) v.push_back(arr[i]);
        else {
            int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[idx] = arr[i];
        }
    }
    cout << n - v.size();
    return 0;
}

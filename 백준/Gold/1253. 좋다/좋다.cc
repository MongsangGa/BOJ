#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n, res;
vector<int> v;

int main() {
    fastio;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        vector<int> arr;
        for (int j = 0; j < n; j++)
            if (i ^ j)
                arr.push_back(v[j]);
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int sum = arr[l] + arr[r];
            if (sum == v[i]) {
                res++;
                break;
            }
            if (sum < v[i]) l++;
            else r--;
        }
    }
    cout << res;
    return 0;
}

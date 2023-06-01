#include<bits/stdc++.h>

using namespace std;

int n, res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i++)
        res = max(res, v[i] * (i + 1));
    cout << res;
}
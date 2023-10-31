#include<bits/stdc++.h>

using namespace std;

int n, k, res;

int main() {
    cin >> n >> k;
    vector<int> v(n), dist;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++)
        dist.push_back(v[i] - v[i - 1]);
    sort(dist.begin(), dist.end());
    for (int i = 0; i < k - 1; i++)
        if (!dist.empty())
            dist.pop_back();
    for (auto &i: dist)
        res += i;
    cout << res;
    return 0;
}

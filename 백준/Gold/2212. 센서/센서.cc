#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 10'002

int n, k, res;

int main() {
    fastio;
    cin >> n >> k;
    vector<int> a(n), d;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++)
        d.push_back(a[i] - a[i - 1]);
    sort(d.begin(), d.end());
    for (int i = 0; i < k - 1; i++)
        if (!d.empty())
            d.pop_back();
    for (auto i: d) res += i;
    cout << res;
    return 0;
}

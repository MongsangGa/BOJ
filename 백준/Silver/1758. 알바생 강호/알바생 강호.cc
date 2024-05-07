#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n;
long long res;
vector<int> v;

int main() {
    fastio;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i++)
        if (v[i] - i > 0)
            res += v[i] - i;

    cout << res;
    return 0;
}

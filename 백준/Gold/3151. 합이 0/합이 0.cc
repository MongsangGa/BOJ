#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

long long n, res;
vector<int> v;

int main() {
    fastio;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int target = -(v[i] + v[j]);
            int tl = lower_bound(v.begin() + j + 1, v.end(), target) - v.begin();
            int tu = upper_bound(v.begin() + j + 1, v.end(), target) - v.begin();
            if (tl == n) continue;
            if (!(v[i] + v[j] + v[tl])) res += tu - tl;
        }
    }
    cout << res;
    return 0;
}

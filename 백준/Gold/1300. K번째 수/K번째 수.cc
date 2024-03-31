#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define ll long long
ll N, K, l, r, res;

ll solve(ll mid) {
    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += min(N, (ll) mid / i);
        if (i > mid) break;
    }
    return sum;
}

int main() {
    fastio;
    cin >> N >> K;
    l = 1, r = N * N;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (solve(mid) < K) l = mid + 1;
        else res = mid, r = mid - 1;
    }
    cout << res;
    return 0;
}

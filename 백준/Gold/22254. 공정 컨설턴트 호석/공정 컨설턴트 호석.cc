#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long
#define SIZE 100'002

int n, x, arr[SIZE];

ll solve(int m) {
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<>> q;
    for (int i = 0; i < m; i++)
        q.push(0);
    for (int i = 0; i < n; i++) {
        ll now = q.top();
        q.pop();
        now += arr[i];
        ans = max(ans, now);
        if (now > x) break;
        q.push(now);
    }
    return ans;
}

int main() {
    fastio;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int s = 1, e = 1e6;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (solve(mid) > x) s = mid + 1;
        else e = mid - 1;
    }
    cout << s;
    return 0;
}
// lgX * NlgN

#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define ll long long
#define SIZE 100'003

ll n, m, b, x[SIZE], psum[SIZE];

int main() {
    fastio;
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        psum[i] = psum[i - 1] + x[i];
    }
    int res = 0;
    // i: start-range
    for (int i = 1; i <= n; i++) {
        int s = i, e = n;
        while (s <= e) {
            // mid: end-range
            int mid = (s + e) / 2;
            int fac = (i + mid) / 2;
            ll sum = 0;
            // right cost
            sum += psum[mid] - psum[fac] - (x[fac] * (mid - fac));
            // left cost
            sum += x[fac] * (fac - i) - (psum[fac - 1] - psum[i - 1]);
            if (sum <= b)
                s = mid + 1, res = max(res, mid - i + 1);
            else
                e = mid - 1;
        }
    }
    cout << res;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 1'000'002

int n, k, arr[SIZE], s, e, cnt, res;

int main() {
    fastio;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    while (s <= e && e < n) {
        if (cnt > k) {
            if (arr[s] % 2) cnt--;
            s++;
        } else {
            if (arr[e] % 2) cnt++;
            e++;
        }
        if (cnt <= k) res = max(res, e - s - cnt);
    }
    cout << res;
    return 0;
}

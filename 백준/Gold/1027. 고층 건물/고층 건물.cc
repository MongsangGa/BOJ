#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 52
#define INF 1e9
int n, arr[SIZE], cnt[SIZE], res;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        double maxL = -INF;
        for (int j = i + 1; j < n; j++) {
            double now = (double) (arr[j] - arr[i]) / (j - i);
            if (now > maxL)
                maxL = now, cnt[i] += 1, cnt[j] += 1;
        }
    }
    for (auto i: cnt) res = max(res, i);
    cout << res;
    return 0;
}

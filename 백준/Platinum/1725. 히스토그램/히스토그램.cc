#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 100'001
int n, idx, arr[SIZE];
long long res;
stack<pair<long long, int>> s;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        if (i < n) cin >> arr[i];
        idx = i;
        while (!s.empty() && s.top().first >= arr[i]) {
            idx = s.top().second;
            int w = i - idx;
            res = max(res, w * s.top().first);
            s.pop();
        }
        s.push({arr[i], idx});
    }
    cout << res;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 102

int n, m, maxL, arr[SIZE];

bool solve(int len) {
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] <= len) continue;
        cnt += (arr[i] - arr[i - 1] - 1) / len;
    }
    return cnt <= m;
}

int main() {
    fastio;
    cin >> n >> m >> maxL;
    arr[0] = 0, arr[n + 1] = maxL;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    n += 2;
    sort(arr, arr + n);
    int s = 1, e = 1001;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (solve(mid)) e = mid - 1;
        else s = mid + 1;
    }
    cout << s;
    return 0;
}

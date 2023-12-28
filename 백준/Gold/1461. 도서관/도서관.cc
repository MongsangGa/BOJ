#include <bits/stdc++.h>

using namespace std;

#define SIZE 10'002
int n, m, center, arr[SIZE], res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n + 1);
    for (int i = 0; i <= n; i++)
        if (!arr[i])
            center = i;
    for (int i = 0; i < center; i += m)
        res += abs(arr[i]) * 2;
    for (int i = n; i > center; i -= m)
        res += arr[i] * 2;
    res -= max(abs(arr[0]), abs(arr[n]));
    cout << res;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 100'001

int n, m, arr[S];
long long res, tmp;

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int s = 0, e = m - 1;
    for (int i = s; i <= e; i++)
        tmp += arr[i];
    res = tmp;
    for (int i = m; i < n; i++) {
        tmp = tmp - arr[i - m] + arr[i];
        res = max(res, tmp);
    }
    cout << res;
    return 0;
}

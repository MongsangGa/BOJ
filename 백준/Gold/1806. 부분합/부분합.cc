#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, s, arr[100'002], res = 1e9;
long long sum;

int main() {
    fastio;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int en = 0;
    sum = arr[0];
    for (int st = 0; st < n; st++) {
        while (sum < s && en < n)
            sum += arr[++en];
        if (en == n) break;
        res = min(res, en - st + 1);
        sum -= arr[st];
    }
    if (res == 1e9) cout << 0;
    else cout << res;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)
#define SIZE 200'002
#define INF 360'000

int n, a[SIZE], b[SIZE];

vector<int> failure() {
    int j = 0;
    vector<int> f(n);
    for (int i = 1; i < n; i++) {
        while (j > 0 && a[i] != a[j]) j = f[j - 1];
        if (a[i] == a[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n), sort(b, b + n);
    a[n] = a[0] + INF, b[n] = b[0] + INF;
    for (int i = 0; i < n; i++) a[i] = a[i + 1] - a[i], b[i] = b[i + 1] - b[i];
    vector<int> f = failure();
    int j = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        int ri = (i >= n) ? i - n : i;
        while (j > 0 && b[ri] != a[j]) j = f[j - 1];
        if (b[ri] == a[j]) ++j;
        if (j == n) {
            cout << "possible";
            return 0;
        }
    }
    cout << "impossible";
    return 0;
}

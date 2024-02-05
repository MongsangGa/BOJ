#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define X first
#define Y second
#define SIZE 21
#define INF 1e9

int n, arr[SIZE][SIZE], check[SIZE], res = INF;

int Calc() {
    int s1, s2;
    s1 = s2 = 0;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        if (check[i]) a.push_back(i);
        else b.push_back(i);
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            if (i == j) continue;
            s1 += arr[a[i]][a[j]];
            s2 += arr[b[i]][b[j]];
        }
    }
    return abs(s1 - s2);
}

void solve(int cur, int len) {
    if (len == n / 2) {
        res = min(res, Calc());
        return;
    }
    for (int i = cur; i <= n; i++) {
        check[i] = true;
        solve(i + 1, len + 1);
        check[i] = false;
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    solve(1, 0);
    cout << res;
    return 0;
}

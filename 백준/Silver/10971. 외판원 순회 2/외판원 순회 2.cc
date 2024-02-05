#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define X first
#define Y second
#define SIZE 11
#define INF 1e8+1

int n, arr[SIZE][SIZE], res = INF;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = i;
    do {
        int ans = 0, chk = false;
        for (int i = 0; i < n - 1; i++) {
            if (!arr[v[i]][v[i + 1]])
                chk = true;
            else
                ans += arr[v[i]][v[i + 1]];
        }
        if (!chk && arr[v[n - 1]][v[0]]) {
            ans += arr[v[n - 1]][v[0]];
            res = min(res, ans);
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << res;
    return 0;
}


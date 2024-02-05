#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define X first
#define Y second
#define SIZE 21
#define INF 1e9

int n, arr[SIZE][SIZE], res = INF;

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    vector<int> v(n, 1);
    for (int i = 0; i < n / 2; i++) v[i] = 0;
    do {
        int s1, s2;
        s1 = s2 = 0;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            if (v[i]) a.push_back(i + 1);
            else b.push_back(i + 1);
        }
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (i == j) continue;
                s1 += arr[a[i]][a[j]];
                s2 += arr[b[i]][b[j]];
            }
        }
        res = min(res, abs(s1 - s2));
    } while (next_permutation(v.begin(), v.end()));
    cout << res;
    return 0;
}

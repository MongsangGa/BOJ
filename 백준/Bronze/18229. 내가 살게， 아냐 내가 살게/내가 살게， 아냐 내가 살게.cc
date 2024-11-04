#include<bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, m, k, arr[101][101], res[101];

int main() {
    fastio;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++) {
            res[i] += arr[i][j];
            if (res[i] >= k) {
                cout << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
    return 0;
}

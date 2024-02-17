#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 21
#define INF 1e9


int n, arr[SIZE][SIZE], res = INF;

int calc(vector<int> v) {
    int t = 0, len = v.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i == j) continue;
            t += arr[v[i]][v[j]];
        }
    }
    return t;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    for (int k = 1; k <= n / 2; k++) {
        vector<int> v(n, 1);
        for (int i = 0; i < k; i++) v[i] = 0;
        do {
            vector<int> a, b;
            for (int i = 0; i < n; i++) {
                if (v[i]) a.push_back(i);
                else b.push_back(i);
            }
            res = min(res, abs(calc(a) - calc(b)));
        } while (next_permutation(v.begin(), v.end()));
    }
    cout << res;
    return 0;
}

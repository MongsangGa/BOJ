#include <bits/stdc++.h>

using namespace std;

int t, n, score, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end());
        score = 1e8, cnt = 0;
        for (int i = 0; i < n; i++)
            if (v[i].second < score)
                score = v[i].second, cnt++;
        cout << cnt << '\n';
    }
}

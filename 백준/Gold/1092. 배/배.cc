#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n, m, t = 0;
vector<int> c, w;

int main() {
    fastio;
    cin >> n;
    c.resize(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    cin >> m;
    w.resize(m);
    for (int i = 0; i < m; i++) cin >> w[i];
    sort(c.begin(), c.end(), greater<>());
    sort(w.begin(), w.end(), greater<>());
    if (c[0] < w[0]) cout << -1;
    else {
        while (!w.empty()) {
            ++t;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < w.size(); j++) {
                    if (c[i] >= w[j]) {
                        w.erase(w.begin() + j);
                        break;
                    }
                }
            }
        }
        cout << t;
    }
    return 0;
}
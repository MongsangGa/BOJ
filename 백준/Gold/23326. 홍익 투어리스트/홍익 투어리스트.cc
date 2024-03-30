#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

map<int, bool> m;
int n, q;

int main() {
    fastio;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a) m[i] = true;
    }
    int cur = 0;
    while (q--) {
        int order, i;
        cin >> order;
        if (order == 1) {
            cin >> i;
            --i;
            if (m[i]) m.erase(i);
            else m[i] = true;
        } else if (order == 2) {
            cin >> i;
            cur = (cur + i) % n;
        } else {
            if (m.empty()) cout << "-1\n";
            else {
                auto iter = m.lower_bound(cur);
                if (iter == m.end()) cout << n - cur + m.begin()->first << '\n';
                else cout << iter->first - cur << '\n';
            }
        }
    }
    return 0;
}

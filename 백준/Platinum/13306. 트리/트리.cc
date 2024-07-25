#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 200'002

int arr[SIZE], p[SIZE];
stack<tuple<int, int, int>> query;
stack<string> res;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    p[y] = x;
}

int main() {
    fastio;
    int n, q;
    cin >> n >> q;
    q += n - 1;
    for (int i = 2; i <= n; i++) cin >> arr[i];
    while (q--) {
        int o, x, y;
        cin >> o;
        if (!o) {
            cin >> x;
            query.push({o, o, x});
        } else {
            cin >> x >> y;
            query.push({o, x, y});
        }
    }
    for (int i = 1; i <= n; i++) p[i] = i;
    while (!query.empty()) {
        auto [o, x, y] = query.top();
        query.pop();
        if (!o) merge(arr[y], y);
        else {
            if (find(x) == find(y)) res.push("YES");
            else res.push("NO");
        }
    }
    while (!res.empty()) {
        cout << res.top() << '\n';
        res.pop();
    }
    return 0;
}

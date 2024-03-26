#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int t, n, ex, ey;
vector<bool> vis;
vector<pair<int, int>> arr;

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[0] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < arr.size(); i++) {
            if (vis[i]) continue;
            if (abs(arr[i].first - cur.first) + abs(arr[i].second - cur.second) <= 1000)
                q.push({arr[i].first, arr[i].second}), vis[i] = true;
        }
    }
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        vis.resize(n + 1), arr.resize(n + 1);
        for (int i = 0; i <= n; i++)
            cin >> arr[i].first >> arr[i].second;
        cin >> ex >> ey;
        BFS(arr[0].first, arr[0].second);
        bool is_able = false;
        for (int i = 0; i < arr.size(); i++)
            if (vis[i] && abs(ex - arr[i].first) + abs(ey - arr[i].second) <= 1000)
                is_able = true;
        if (is_able) cout << "happy\n";
        else cout << "sad\n";
        vis.clear(), arr.clear();
    }
    return 0;
}

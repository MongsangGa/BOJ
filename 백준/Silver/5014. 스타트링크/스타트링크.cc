#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define X first
#define Y second
#define SIZE 1'000'002

int f, s, g, u, d, vis[SIZE];
queue<int> q;

int main() {
    fastio;
    cin >> f >> s >> g >> u >> d;
    vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (auto i: {cur + u, cur - d}) {
            if (i <= 0 || i > f || vis[i]) continue;
            vis[i] = vis[cur] + 1;
            q.push(i);
        }
    }
    if (!vis[g]) cout << "use the stairs";
    else cout << vis[g] - 1;
    return 0;
}


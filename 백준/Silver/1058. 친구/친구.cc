#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define ll long long int
#define SIZE 51

int n, vis[SIZE], res;
string s[SIZE];

void BFS(int st) {
    queue<pair<int, int>> q;
    q.push({st, 0});
    vis[st] = 1;
    while (!q.empty()) {
        auto [cur, len] = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (!vis[i] && s[cur][i] == 'Y') {
                if (len + 1 > 2) continue;
                vis[i] = 1;
                q.push({i, len + 1});
            }
        }
    }
    return;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        int sum = -1;
        fill(vis, vis + SIZE, 0);
        BFS(i);
        for (int j = 0; j < n; j++)
            sum += vis[j];
        res = max(res, sum);
    }
    cout << res;
    return 0;
}

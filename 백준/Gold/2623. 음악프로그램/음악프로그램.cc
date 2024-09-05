#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define SIZE 1'003

int n, m, arr[SIZE], ind[SIZE];
vector<int> adj[SIZE], res;
queue<int> q;

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        int len;
        cin >> len;
        for (int i = 0; i < len; i++) cin >> arr[i];
        for (int i = 0; i < len - 1; i++) {
            adj[arr[i]].push_back(arr[i + 1]);
            ++ind[arr[i + 1]];
        }
    }
    for (int i = 1; i <= n; i++) if (!ind[i]) q.push(i);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        res.push_back(now);
        for (int nxt: adj[now]) {
            --ind[nxt];
            if (!ind[nxt]) q.push(nxt);
        }
    }
    if (res.size() != n) cout << 0;
    else for (auto r: res) cout << r << '\n';
    return 0;
}

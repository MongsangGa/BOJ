#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 502

int t, n, m, a, b, arr[SIZE], ind[SIZE], adj[SIZE][SIZE];
vector<int> res;

int main() {
    fastio;
    cin >> t;
    while (t--) {
        queue<int> q;
        res.clear();
        fill(arr, arr + SIZE, 0);
        fill(ind, ind + SIZE, 0);
        fill(adj[0], adj[SIZE - 1], 0);
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                adj[arr[j]][arr[i]] = 1, ind[arr[i]]++;
        cin >> m;
        while (m--) {
            cin >> a >> b;
            if (adj[a][b]) ind[a]++, ind[b]--;
            else ind[a]--, ind[b]++;
            swap(adj[a][b], adj[b][a]);
        }
        for (int i = 1; i <= n; i++) if (!ind[i]) q.push(i);
        int chk = 0;
        for (int i = 0; i < n; i++) {
            if (q.empty()) {
                chk = 1;
                break;
            }
            if (q.size() > 1) {
                chk = 2;
                break;
            }
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for (int nxt = 1; nxt <= n; nxt++) {
                if (adj[cur][nxt]) {
                    ind[nxt]--;
                    if (!ind[nxt])
                        q.push(nxt);
                }
            }
        }
        if (chk == 1) cout << "IMPOSSIBLE";
        else if (chk == 2) cout << "?";
        else for (auto i: res) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}

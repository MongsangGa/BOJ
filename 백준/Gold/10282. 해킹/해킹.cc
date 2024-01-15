#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define SIZE 10'001
#define INF 1e9 + 1
int t, arr[SIZE];
// cost, node
priority_queue<pii, vector<pii >, greater<pii>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        vector<pii > adj[SIZE];
        fill(arr, arr + SIZE, INF);
        int n, d, c;
        cin >> n >> d >> c;
        for (int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            adj[b].push_back({s, a});
        }
        arr[c] = 0;
        pq.push({0, c});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (arr[cur.second] != cur.first) continue;
            for (auto nxt: adj[cur.second]) {
                if (arr[nxt.second] <= arr[cur.second] + nxt.first) continue;
                arr[nxt.second] = arr[cur.second] + nxt.first;
                pq.push({arr[nxt.second], nxt.second});
            }
        }
        int idx = 0, res = 0;
        for (int i = 1; i <= n; i++)
            if (arr[i] != INF)
                idx++, res = max(res, arr[i]);
        cout << idx << ' ' << res << '\n';
    }
    return 0;
}

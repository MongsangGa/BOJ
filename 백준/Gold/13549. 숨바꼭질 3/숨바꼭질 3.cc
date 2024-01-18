#include <bits/stdc++.h>

using namespace std;

const int SIZE = 2e5;
const int INF = 1e9;
#define pi pair<int,int>
int st, en, d[SIZE + 2];
priority_queue<pi, vector<pi >, greater<>> pq;

int dijkstra() {
    fill(d, d + SIZE, INF);
    d[st] = 0;
    pq.push({d[st], st});
    while (!pq.empty()) {
        auto [cost, idx] = pq.top();
        pq.pop();
        if (idx == en) break;
        if (d[idx] != cost) continue;
        int nIdx;
        nIdx = 2 * idx;
        if (nIdx <= SIZE && d[idx] < d[nIdx]) {
            d[nIdx] = d[idx];
            pq.push({d[nIdx], nIdx});
        }
        nIdx = idx + 1;
        if (nIdx <= SIZE && d[idx] + 1 < d[nIdx]) {
            d[nIdx] = d[idx] + 1;
            pq.push({d[nIdx], nIdx});
        }
        nIdx = idx - 1;
        if (nIdx >= 0 && d[idx] + 1 < d[nIdx]) {
            d[nIdx] = d[idx] + 1;
            pq.push({d[nIdx], nIdx});
        }
    }
    return d[en];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> st >> en;
    dijkstra();
    cout << d[en] << ' ';
    return 0;
}
